/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Chest.hpp"

void Chest::generateChest()
{
    loadSprite(m_namechestclose);
    m_spawnchest = false;
    std::srand(std::time(nullptr));
    short spawn = std::rand() % 5;
    if(spawn == 1)
    {
        m_spawnchest = true;
        m_open = false;
    }
}
void Chest::openChest()
{
    if(!m_open)
    {
        loadSprite(m_namechestopen);
        m_Gain.choseGain(sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y + 64));
        m_Gain.getSpriteGain();
        m_open = !m_open;
    }
}
void Chest::isGet()
{
    m_Gain.isGet();
}