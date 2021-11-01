/**
 * @file Ground.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _GROUND_HPP_
#define _GROUND_HPP_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "MakeSprite.hpp"

class Ground {
public:
    // Constructor / Destrutor
    Ground(void);

    Ground(const char *name);

    ~Ground(void);

    // Accessor
    std::vector <sf::Sprite> getListSprite(void);

    sf::Sprite getSprite(void);

    Ground *getAdress(void);

    // Function
    void setPositionVector(std::vector <sf::Vector2f> vector);

    void setPosition(sf::Vector2f position);


private:
    // Variable
    // std
    const char *m_name = "";
    std::vector <sf::Sprite> m_ListeSprite;

    // Class
    MakeSprite m_MSprite;

    // SFML
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

    // Function
    void initSprite(void);

    void loadTexture(void);

    void loadSprite(void);
};

#endif