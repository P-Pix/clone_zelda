/**
 * @file StaticEntity.cpp
 * @author Guillaume LEMONNIER
 * @brief Implémentation de la classe StaticEntity
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/StaticEntity.hpp"
#include "../include/Utils.hpp"
#include "../include/Logger.hpp"

StaticEntity::StaticEntity()
    : Entity()
    , m_staticType(StaticEntityType::DECORATION)
    , m_isSolid(false)
    , m_isInteractable(false) {
}

StaticEntity::StaticEntity(StaticEntityType type, const std::string& texturePath)
    : Entity(EntityType::ITEM, texturePath)
    , m_staticType(type)
    , m_isSolid(type == StaticEntityType::WALL || type == StaticEntityType::OBSTACLE)
    , m_isInteractable(type == StaticEntityType::CHEST || type == StaticEntityType::DOOR) {
}

bool StaticEntity::isCollidingWith(const sf::FloatRect& bounds) const {
    if (!m_isSolid || !m_active) {
        return false;
    }
    
    return getBounds().intersects(bounds);
}

sf::FloatRect StaticEntity::getBounds() const {
    return m_sprite.getGlobalBounds();
}

void StaticEntity::addSprite(const sf::Sprite& sprite) {
    m_additionalSprites.push_back(sprite);
}

void StaticEntity::clearSprites() {
    m_additionalSprites.clear();
    m_additionalTextures.clear();
}

void StaticEntity::draw(sf::RenderWindow& window) {
    if (!m_active) {
        return;
    }
    
    // Dessiner le sprite principal
    Entity::draw(window);
    
    // Dessiner les sprites additionnels
    for (const auto& sprite : m_additionalSprites) {
        window.draw(sprite);
    }
}

void StaticEntity::loadMultipleTextures(const std::vector<std::string>& texturePaths) {
    m_additionalTextures.clear();
    m_additionalSprites.clear();
    
    for (const auto& path : texturePaths) {
        sf::Texture texture;
        if (Utils::loadTexture(texture, path)) {
            m_additionalTextures.push_back(std::move(texture));
            
            sf::Sprite sprite;
            sprite.setTexture(m_additionalTextures.back());
            sprite.setPosition(getPosition());
            m_additionalSprites.push_back(sprite);
        } else {
            Logger::warning("Failed to load additional texture: %s", path.c_str());
        }
    }
}
