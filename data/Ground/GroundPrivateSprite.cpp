/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Ground.hpp"

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