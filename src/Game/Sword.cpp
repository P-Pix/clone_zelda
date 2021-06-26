/**
 * @file GamePrivateSword.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Game.hpp"

void Game::swordAttack(void)
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
            //monsterReceveAttack(x);
        }
        else if(collideSword(m_Map.getChestSprite().getPosition()))
        {
            m_Map.oprenChest();
        }
    }
}
void Game::monsterReceveAttack(unsigned int mob)
{
    m_listmob[mob].setDamage(m_Sword.getPower());
    if(m_listmob[mob].isAlive())
    {
        if(m_Player.getOrientationDown() && !previewCollide(m_listmob[mob].getPosition(), sf::Vector2f(0.f, 64.f)))
        {
            m_listmob[mob].recoilDown();
        }
        else if(m_Player.getOrientationUp() && !previewCollide(m_listmob[mob].getPosition(), sf::Vector2f(0.f, -64.f)))
        {
            m_listmob[mob].recoilUp();
        }
        else if(m_Player.getOrientationRight() && !previewCollide(m_listmob[mob].getPosition(), sf::Vector2f(64.f, 0.f)))
        {
            m_listmob[mob].recoilRight();
        }
        else if(m_Player.getOrientationLeft() && !previewCollide(m_listmob[mob].getPosition(), sf::Vector2f(-64.f, 0.f)))
        {
            m_listmob[mob].recoilLeft();
        }
    }
}