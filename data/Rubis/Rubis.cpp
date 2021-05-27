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
    m_Sprite.setPosition(sf::Vector2f(640.f, 16.f));
    m_Font.loadFromFile(m_namefont);

    generateText();
}
Rubis::~Rubis()
{
    
}