/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Ground.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

void Ground::initSprite()
{
    loadTexture();
    loadSprite();
}
void Ground::loadSprite()
{
    m_Sprite.setTexture(m_Texture);
}
void Ground::loadTexture()
{
    if(!m_Texture.loadFromFile(m_name))
    {
        std::cout << "error image " << m_name << std::endl;
    }
}