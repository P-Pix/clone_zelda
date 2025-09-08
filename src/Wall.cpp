/**
 * @file Wall.cpp
 * @author Guillaume LEMONNIER
 * @brief Implémentation modernisée de la classe Wall
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/Wall.hpp"
#include "../include/Logger.hpp"
#include "../include/Config.hpp"
#include <algorithm>

Wall::Wall()
    : StaticEntity(StaticEntityType::WALL, "image/tree.png")
    , m_wallType(WallType::TREE)
    , m_spritesNeedUpdate(true) {
    
    initializeByType(m_wallType);
}

Wall::Wall(WallType type)
    : StaticEntity(StaticEntityType::WALL, "")
    , m_wallType(type)
    , m_spritesNeedUpdate(true) {
    
    initializeByType(type);
}

Wall::Wall(const std::string& texturePath)
    : StaticEntity(StaticEntityType::WALL, texturePath)
    , m_wallType(WallType::TREE)
    , m_spritesNeedUpdate(true) {
}

Wall::Wall(WallType type, const std::vector<sf::Vector2f>& positions)
    : StaticEntity(StaticEntityType::WALL, "")
    , m_wallType(type)
    , m_wallPositions(positions)
    , m_spritesNeedUpdate(true) {
    
    initializeByType(type);
    
    if (!positions.empty()) {
        setPosition(positions[0]); // Position principale
    }
}

std::unique_ptr<Entity> Wall::clone() const {
    auto wall = std::make_unique<Wall>(m_wallType, m_wallPositions);
    return std::move(wall);
}

void Wall::initializeByType(WallType type) {
    std::string texturePath = getTexturePathForType(type);
    
    if (!loadTexture(texturePath)) {
        Logger::warning("Failed to load wall texture: %s", texturePath.c_str());
        // Fallback sur la texture par défaut
        loadTexture("image/tree.png");
    }
    
    setupSprite();
}

std::string Wall::getTexturePathForType(WallType type) const {
    switch (type) {
        case WallType::TREE:
            return "image/tree.png";
        case WallType::STONE:
            return "image/stone_wall.png";
        case WallType::BRICK:
            return "image/brick_wall.png";
        case WallType::WOODEN:
            return "image/wooden_wall.png";
        case WallType::METAL:
            return "image/metal_wall.png";
        default:
            return "image/tree.png";
    }
}

void Wall::setupSprite() {
    StaticEntity::setupSprite();
    m_spritesNeedUpdate = true;
}

void Wall::setPositions(const std::vector<sf::Vector2f>& positions) {
    m_wallPositions = positions;
    m_spritesNeedUpdate = true;
    
    if (!positions.empty()) {
        setPosition(positions[0]);
    }
    
    Logger::debug("Wall positions set, count: %zu", positions.size());
}

void Wall::addWallAt(const sf::Vector2f& position) {
    // Vérifier si une position similaire existe déjà
    auto it = std::find_if(m_wallPositions.begin(), m_wallPositions.end(),
        [&position](const sf::Vector2f& pos) {
            float distance = std::sqrt(
                std::pow(pos.x - position.x, 2) + 
                std::pow(pos.y - position.y, 2)
            );
            return distance < 10.0f; // Tolérance de 10 pixels
        });
    
    if (it == m_wallPositions.end()) {
        m_wallPositions.push_back(position);
        m_spritesNeedUpdate = true;
        
        Logger::debug("Wall added at position (%.1f, %.1f)", position.x, position.y);
    }
}

void Wall::removeWallAt(const sf::Vector2f& position) {
    auto it = std::find_if(m_wallPositions.begin(), m_wallPositions.end(),
        [&position](const sf::Vector2f& pos) {
            float distance = std::sqrt(
                std::pow(pos.x - position.x, 2) + 
                std::pow(pos.y - position.y, 2)
            );
            return distance < 10.0f;
        });
    
    if (it != m_wallPositions.end()) {
        m_wallPositions.erase(it);
        m_spritesNeedUpdate = true;
        
        Logger::debug("Wall removed at position (%.1f, %.1f)", position.x, position.y);
    }
}

bool Wall::isCollidingWith(const sf::FloatRect& bounds) const {
    if (!m_isSolid || !m_active) {
        return false;
    }
    
    // Vérifier collision avec le sprite principal
    if (StaticEntity::isCollidingWith(bounds)) {
        return true;
    }
    
    // Vérifier collision avec tous les murs additionnels
    for (const auto& wallBounds : getAllBounds()) {
        if (wallBounds.intersects(bounds)) {
            return true;
        }
    }
    
    return false;
}

std::vector<sf::FloatRect> Wall::getAllBounds() const {
    std::vector<sf::FloatRect> allBounds;
    
    // Ajouter les bounds du sprite principal
    allBounds.push_back(getBounds());
    
    // Ajouter les bounds de tous les murs
    for (const auto& position : m_wallPositions) {
        sf::FloatRect bounds(
            position.x,
            position.y,
            Game::SPRITE_SIZE,
            Game::SPRITE_SIZE
        );
        allBounds.push_back(bounds);
    }
    
    return allBounds;
}

void Wall::updateSpritesCache() const {
    if (!m_spritesNeedUpdate) {
        return;
    }
    
    m_wallSprites.clear();
    
    // Créer un sprite pour chaque position
    for (const auto& position : m_wallPositions) {
        m_wallSprites.push_back(createSpriteAt(position));
    }
    
    m_spritesNeedUpdate = false;
}

sf::Sprite Wall::createSpriteAt(const sf::Vector2f& position) const {
    sf::Sprite sprite;
    sprite.setTexture(m_texture);
    sprite.setPosition(position);
    return sprite;
}

void Wall::draw(sf::RenderWindow& window) {
    if (!m_active) {
        return;
    }
    
    // Dessiner le sprite principal
    StaticEntity::draw(window);
    
    // Mettre à jour le cache si nécessaire
    updateSpritesCache();
    
    // Dessiner tous les murs additionnels
    for (const auto& sprite : m_wallSprites) {
        window.draw(sprite);
    }
}

void Wall::onCollision(Entity* other) {
    if (other && other->getEntityType() == EntityType::PLAYER) {
        Logger::debug("Player collided with wall");
        // Logique spécifique à la collision avec le joueur
    }
}
