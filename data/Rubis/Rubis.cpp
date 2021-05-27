/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Rubis.hpp"

Rubis::Rubis()
{
    m_Texture.loadFromFile(m_nameimage);
    m_Sprite.setTexture(m_Texture);
}
Rubis::~Rubis()
{
    
}