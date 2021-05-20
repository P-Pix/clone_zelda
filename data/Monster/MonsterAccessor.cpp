#include "Monster.hpp"

sf::Sprite Monster::getSprite()
{
    return m_Sprite;
}
sf::Vector2f Monster::getNextPosition()
{
    return m_Patern[m_moveaction];
}
sf::Vector2f Monster::getPosition()
{
    return m_Sprite.getPosition();
}
int Monster::getPower()
{
    return m_power;
}
bool Monster::isAlive()
{
    return m_alive;
}