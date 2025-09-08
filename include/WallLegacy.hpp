/**
 * @file WallLegacy.hpp
 * @author Guillaume LEMONNIER  
 * @brief Déclarations legacy pour la classe Wall (compatibilité temporaire)
 * @version 1.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _WALL_LEGACY_HPP_
#define _WALL_LEGACY_HPP_

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Classe Wall legacy (ancienne implementation)
 * Cette classe maintient la compatibilité avec l'ancien code
 * pendant la transition vers l'architecture moderne
 */
class Wall {
private:
    // Attributs principaux
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;
    std::vector<sf::Vector2f> m_positionVector;
    
    // Sprite du mur
    const char* m_name;

public:
    // Constructeur/Destructeur
    Wall(void);
    Wall(const char* name);
    ~Wall(void);
    
    // Accesseurs position
    sf::Vector2f getPosition(void);
    std::vector<sf::Vector2f> getPositionVector(void);
    
    // Setters position
    void setPosition(sf::Vector2f POSITION);
    void setPositionVector(std::vector<sf::Vector2f> vector);
    
    // Sprite
    sf::Sprite getSpritePosition(sf::Vector2f position);
    sf::Sprite loadSprite(void);
    void loadTexture(void);
};

#endif // _WALL_LEGACY_HPP_
