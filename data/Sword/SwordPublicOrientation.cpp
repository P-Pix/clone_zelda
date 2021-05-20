#include "Sword.hpp"

void Sword::setOrientationDown(bool playerdown)
{
    m_animationdown = playerdown;
}
void Sword::setOrientationLeft(bool playerleft)
{
    m_animationleft = playerleft;
}
void Sword::setOrientationRight(bool playerright)
{
    m_animationright = playerright;
}
void Sword::setOrientationUp(bool playerup)
{
    m_animationup = playerup;
}