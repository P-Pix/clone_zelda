/**
 * @file Character.cpp
 * @author Guillaume LEMONNIER
 * @brief Implémentation de la classe Character
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/Character.hpp"
#include "../include/Logger.hpp"
#include "../include/Config.hpp"
#include <cmath>

Character::Character() 
    : Entity()
    , m_speed(Config::DEFAULT_PLAYER_SPEED)
    , m_maxHealth(100.0f)
    , m_currentHealth(100.0f)
    , m_currentDirection(Direction::DOWN)
    , m_state(CharacterState::IDLE)
    , m_animationTimer(0.0f)
    , m_currentFrame(0) {
}

Character::Character(EntityType type, const std::string& texturePath, float maxHealth)
    : Entity(type, texturePath)
    , m_speed(Config::DEFAULT_PLAYER_SPEED)
    , m_maxHealth(maxHealth)
    , m_currentHealth(maxHealth)
    , m_currentDirection(Direction::DOWN)
    , m_state(CharacterState::IDLE)
    , m_animationTimer(0.0f)
    , m_currentFrame(0) {
}

void Character::update(float deltaTime) {
    if (!m_active || isDead()) {
        return;
    }
    
    updateAnimation(deltaTime);
    
    // Mettre à jour le sprite avec la frame courante
    m_sprite.setTextureRect(getTextureRect());
}

bool Character::isCollidingWith(const sf::FloatRect& bounds) const {
    return getBounds().intersects(bounds);
}

sf::FloatRect Character::getBounds() const {
    return m_sprite.getGlobalBounds();
}

void Character::move(Direction direction, float deltaTime) {
    if (!m_active || isDead()) {
        return;
    }
    
    setCurrentDirection(direction);
    
    sf::Vector2f newPosition = getNextPosition(direction, deltaTime);
    
    if (canMoveTo(newPosition)) {
        setPosition(newPosition);
        setState(CharacterState::WALKING);
    } else {
        setState(CharacterState::IDLE);
    }
}

sf::Vector2f Character::getNextPosition(Direction direction, float deltaTime) const {
    sf::Vector2f currentPos = getPosition();
    float distance = m_speed * deltaTime;
    
    switch (direction) {
        case Direction::UP:
            return sf::Vector2f(currentPos.x, currentPos.y - distance);
        case Direction::DOWN:
            return sf::Vector2f(currentPos.x, currentPos.y + distance);
        case Direction::LEFT:
            return sf::Vector2f(currentPos.x - distance, currentPos.y);
        case Direction::RIGHT:
            return sf::Vector2f(currentPos.x + distance, currentPos.y);
        default:
            return currentPos;
    }
}

bool Character::canMoveTo(const sf::Vector2f& position) const {
    // Vérifier les limites de la fenêtre
    if (position.x < 0 || position.y < 0 ||
        position.x + Config::SPRITE_SIZE > Config::WINDOW_WIDTH ||
        position.y + Config::SPRITE_SIZE > Config::WINDOW_HEIGHT) {
        return false;
    }
    
    return true;
}

void Character::updateAnimation(float deltaTime) {
    m_animationTimer += deltaTime;
    
    // Changer de frame toutes les 150ms
    if (m_animationTimer >= 0.15f) {
        updateAnimationFrame();
        m_animationTimer = 0.0f;
    }
}

void Character::updateAnimationFrame() {
    // Logique d'animation simple: 3 frames par direction
    if (m_state == CharacterState::WALKING) {
        m_currentFrame = (m_currentFrame + 1) % 3;
    } else {
        m_currentFrame = 1; // Frame centrale pour idle
    }
}

sf::IntRect Character::getTextureRect() const {
    int frameWidth = Config::SPRITE_SIZE;
    int frameHeight = Config::SPRITE_SIZE;
    
    // Calcul de la position dans la texture selon la direction
    int row = static_cast<int>(m_currentDirection);
    int col = m_currentFrame;
    
    return sf::IntRect(
        col * frameWidth,
        row * frameHeight,
        frameWidth,
        frameHeight
    );
}

void Character::takeDamage(float damage) {
    if (isDead()) {
        return;
    }
    
    CharacterState oldState = m_state;
    
    m_currentHealth = std::max(0.0f, m_currentHealth - damage);
    
    if (isDead()) {
        setState(CharacterState::DEAD);
        onDeath();
        Logger::info("Character died after taking %.1f damage", damage);
    } else {
        setState(CharacterState::DAMAGED);
        onDamage(damage);
        Logger::debug("Character took %.1f damage, health: %.1f/%.1f", 
                     damage, m_currentHealth, m_maxHealth);
    }
    
    onStateChange(oldState, m_state);
}

void Character::heal(float healAmount) {
    if (isDead()) {
        return;
    }
    
    float oldHealth = m_currentHealth;
    m_currentHealth = std::min(m_maxHealth, m_currentHealth + healAmount);
    
    Logger::debug("Character healed %.1f, health: %.1f/%.1f", 
                 healAmount, m_currentHealth, m_maxHealth);
}

void Character::setMaxHealth(float maxHealth) {
    m_maxHealth = std::max(1.0f, maxHealth);
    
    // Ajuster la vie actuelle si nécessaire
    if (m_currentHealth > m_maxHealth) {
        m_currentHealth = m_maxHealth;
    }
}
