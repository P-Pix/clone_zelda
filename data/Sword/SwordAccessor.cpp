#include "Sword.hpp"

sf::Sprite Sword::getSprite()
{
    return m_Sprite;
}
sf::Vector2f Sword::getPosition()
{
    return m_Sprite.getPosition();
}
int Sword::getPower()
{
    return m_power;
}
bool Sword::getExecution()
{
    return m_aniamtionexe;
}
bool Sword::getAttackUp()
{
    return m_animationup;
}
bool Sword::getAttackLeft()
{
    return m_animationleft;
}
bool Sword::getAttackRight()
{
    return m_animationright;
}
bool Sword::getAttackDown()
{
    return m_animationdown;
}