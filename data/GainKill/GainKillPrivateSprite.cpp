/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GainKill.hpp"

void GainKill::loadSprite(const char *name)
{
    loadTexture(name);
    m_Sprite.setTexture(m_Texture);
}
void GainKill::loadTexture(const char *name)
{
    if(!m_Texture.loadFromFile(name))
    {
        std::cout << "error image " << name << std::endl;
    }
}
void GainKill::setPostionSprite(sf::Vector2f position)
{
    m_Sprite.setPosition(position);
}