/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Chest.hpp"

void Chest::loadSprite(const char *name)
{
    m_Texture.loadFromFile(name);
    m_Sprite.setTexture(m_Texture);
}