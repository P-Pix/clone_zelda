/**
 * @file MakeSprite.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _MAKESPRITE_HPP_
#define _MAKESPRITE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class MakeSprite {
private:
    sf::Texture m_Texture;

    void loadSprite(const char *NameTexture);

protected:
    /// Size of the Sprite
    /// 0 if it's the default constructor
    unsigned int m_sizex = 0,
            m_sizey = 0;

    sf::Sprite m_Sprite;

public:
    ////////////////////////////////////////
    /// Default constructor
    /// Create a empty Sprite
    MakeSprite(void);

    /// Constructor with a Picture name
    /// Create a Sprite with the Picture
    MakeSprite(const char *NameTexture);

    /// Destructor
    ~MakeSprite(void);
};

#endif