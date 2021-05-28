/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::swordAttack()
{
    if(m_Sword.getExecution())
    {
        if(collideSword(m_Mob1.getPosition()) && m_Mob1.isAlive())
        {
            m_Mob1.setDamage(m_Sword.getPower());
            if(m_Mob1.isAlive())
            {
                if(m_Player.getOrientationDown() && !previewCollide(m_Mob1.getPosition(), sf::Vector2f(0.f, 64.f)))
                {
                    m_Mob1.recoilDown();
                }
                else if(m_Player.getOrientationUp() && !previewCollide(m_Mob1.getPosition(), sf::Vector2f(0.f, -64.f)))
                {
                    m_Mob1.recoilUp();
                }
                else if(m_Player.getOrientationRight() && !previewCollide(m_Mob1.getPosition(), sf::Vector2f(64.f, 0.f)))
                {
                    m_Mob1.recoilRight();
                }
                else if(m_Player.getOrientationLeft() && !previewCollide(m_Mob1.getPosition(), sf::Vector2f(-64.f, 0.f)))
                {
                    m_Mob1.recoilLeft();
                }
            }
        }
        else if(collideSword(m_Map.getChestSprite().getPosition()))
        {
            m_Map.oprenChest();
        }
    }
}