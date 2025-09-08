/**
 * @file SimpleWall.hpp
 * @author Guillaume LEMONNIER
 * @brief Version simplifiée du Wall pour la transition
 * @version 2.0
 * @date 2025-07-26
 */

#ifndef SIMPLE_WALL_HPP
#define SIMPLE_WALL_HPP

#include <SFML/Graphics.hpp>
#include "SimpleConfig.hpp"
#include <vector>

class Wall {
public:
    // Constructeurs / Destructeur
    Wall();
    Wall(const char* nametexture);
    ~Wall() = default;

    // Accesseurs (compatibilité)
    sf::Sprite getSprite() const { return m_sprite; }
    std::vector<sf::Sprite> getListSprite() const { return m_spriteList; }

    // Méthodes
    void setPosition(sf::Vector2f position);
    void setPositionVector(std::vector<sf::Vector2f> vector);

private:
    // Variables
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::vector<sf::Sprite> m_spriteList;
    const char* m_textureName;

    // Méthodes privées
    sf::Sprite getSpritePosition(sf::Vector2f position);
    sf::Sprite loadSprite();
    void loadTexture();
};

#endif // SIMPLE_WALL_HPP
