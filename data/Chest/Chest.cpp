/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Chest.hpp"

Chest::Chest()
{
    loadSprite(m_namechestclose);
    m_Sprite.setPosition(sf::Vector2f(512.f, 320.f));
}
Chest::~Chest()
{

}