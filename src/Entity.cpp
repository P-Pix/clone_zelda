/**
 * @file Entity.cpp
 * @author Guillaume LEMONNIER
 * @brief Implémentation de la classe Entity
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/Entity.hpp"
#include "../include/Utils.hpp"
#include "../include/Logger.hpp"
#include <sstream>

Entity::Entity() 
    : m_position(0.0f, 0.0f)
    , m_type(EntityType::ITEM)
    , m_active(true)
    , m_texturePath("") {
}

Entity::Entity(EntityType type, const std::string& texturePath)
    : m_position(0.0f, 0.0f)
    , m_type(type)
    , m_active(true)
    , m_texturePath(texturePath) {
    
    if (!loadTexture(texturePath)) {
        Logger::warning("Failed to load texture for entity: %s", texturePath.c_str());
    } else {
        setupSprite();
    }
}

bool Entity::loadTexture(const std::string& texturePath) {
    if (texturePath.empty()) {
        Logger::warning("Empty texture path provided");
        return false;
    }
    
    if (!Utils::loadTexture(m_texture, texturePath)) {
        return false;
    }
    
    m_texturePath = texturePath;
    return true;
}

void Entity::setupSprite() {
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
}

void Entity::draw(sf::RenderWindow& window) {
    if (m_active) {
        window.draw(m_sprite);
    }
}

sf::Sprite Entity::getSprite() const {
    return m_sprite;
}

void Entity::setPosition(const sf::Vector2f& position) {
    m_position = position;
    m_sprite.setPosition(position);
}

sf::Vector2f Entity::getPosition() const {
    return m_position;
}

std::string Entity::serialize() const {
    std::stringstream ss;
    ss << static_cast<int>(m_type) << ";"
       << m_position.x << ";" << m_position.y << ";"
       << m_active << ";"
       << m_texturePath;
    return ss.str();
}

void Entity::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string token;
    
    if (std::getline(ss, token, ';')) {
        m_type = static_cast<EntityType>(std::stoi(token));
    }
    if (std::getline(ss, token, ';')) {
        m_position.x = std::stof(token);
    }
    if (std::getline(ss, token, ';')) {
        m_position.y = std::stof(token);
    }
    if (std::getline(ss, token, ';')) {
        m_active = static_cast<bool>(std::stoi(token));
    }
    if (std::getline(ss, token)) {
        m_texturePath = token;
        loadTexture(m_texturePath);
        setupSprite();
    }
}

bool Entity::isCollidingWith(const sf::FloatRect& bounds) const {
    return getBounds().intersects(bounds);
}

sf::FloatRect Entity::getBounds() const {
    return m_sprite.getGlobalBounds();
}
