/**
 * @file GamePublic.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Game.hpp"

void Game::executionGame()
{
    allDrawWindow();
    mooveMonster();
    switchMap();
    swordAttack();
    collideMonster();
    gainChest();
    if(m_Player.isInvulnerable())
    {
        m_Player.frameInvulnerable();
    }
    if(m_Mob1.isInvulnerable())
    {
        m_Mob1.frameInvulnerable();
    }
}
void Game::keyDown()
{
    if(!m_Sword.getExecution() && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, m_Player.getSpeed() * 1.f)))
    {
        if(!m_Player.getOrientationDown())
        {
            m_Player.setOrientationDown();
        }
        m_Player.animationMoveDown();
    }
}
void Game::keyLeft()
{
    if(!m_Sword.getExecution() && !previewCollide(m_Player.getPosition(), sf::Vector2f(m_Player.getSpeed() * -1.f, 0.f)))
    {
        if(!m_Player.getOrientationLeft())
        {
            m_Player.setOrientationLeft();
        }
        m_Player.animationMoveLeft();
    }
}
void Game::keyRight()
{
    if(!m_Sword.getExecution() && !previewCollide(m_Player.getPosition(), sf::Vector2f(m_Player.getSpeed() * 1.f, 0.f)))
    {
        if(!m_Player.getOrientationRight())
        {
            m_Player.setOrientationRight();
        }
        m_Player.animationMoveRight();
    }
}
void Game::keyUp()
{
    if(!m_Sword.getExecution() && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, m_Player.getSpeed() * -1.f)))
    {
        if(!m_Player.getOrientationUp())
        {
            m_Player.setOrientationUp();
        }
        m_Player.animationMoveUp();
    }
}
void Game::keySpace()
{
    if(!m_Sword.getExecution())
    {
        m_Sword.setOrientationUp(m_Player.getOrientationUp()); 
        m_Sword.setOrientationDown(m_Player.getOrientationDown());
        m_Sword.setOrientationRight(m_Player.getOrientationRight());
        m_Sword.setOrientationLeft(m_Player.getOrientationLeft());
        m_Sword.startAnimation(m_Player.getPositionSword(), m_Player.getOrientationValue());
    }
}