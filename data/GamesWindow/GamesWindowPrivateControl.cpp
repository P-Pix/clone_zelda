#include "GamesWindow.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

void GamesWindow::swordAttack()
{
    if(m_Sword.getExecution())
    {
        if(collideSword(m_Mob1.getSprite()))
        {
            if(m_Player.getOrientationDown())
            {
                m_Mob1.recoilDown();
            }
            else if(m_Player.getOrientationUp())
            {
                m_Mob1.recoilUp();
            }
            else if(m_Player.getOrientationRight())
            {
                m_Mob1.recoilRight();
            }
            else if(m_Player.getOrientationLeft())
            {
                m_Mob1.recoilLeft();
            }
            m_Mob1.setDamage(m_Sword.getPower());
        }
    }
}
void GamesWindow::canMove()
{
    m_canmove = true;
    if(m_Map.hasBloc())
    {
        if(collideWall(m_Map.getListPositionWallInt()))
        {
            m_canmove = false;
        }
    }
    else if(m_Map.hasTree())
    {
        if(collideWall(m_Map.getListPositionWallExt()))
        {
            m_canmove = false;
        }
    }
}
void GamesWindow::pollEvent()
{
    if(this -> m_Window -> pollEvent(this -> m_Event))
    {
        if(this -> m_Event.type == sf::Event::Closed)
        {
            this -> m_Window -> close();
        }
        else if (this -> m_Event.type == sf::Event::KeyPressed)
        {
            if(this -> m_Event.key.code == sf::Keyboard::Escape)
            {
                this -> m_Window -> close();
            }
            else if(this -> m_Event.key.code == sf::Keyboard::Down)
            {
                if(!m_Sword.getExecution() && m_canmove)
                {
                    if(!m_Player.getOrientationDown())
                    {
                        m_Player.setOrientationDown();
                    }
                    m_Player.animationMoveDown();
                }
            }
            else if(this -> m_Event.key.code == sf::Keyboard::Up)
            {
                if(!m_Sword.getExecution() && m_canmove)
                {
                    if(!m_Player.getOrientationUp())
                    {
                        m_Player.setOrientationUp();
                    }
                    m_Player.animationMoveUp();
                }
            }
            else if(this -> m_Event.key.code == sf::Keyboard::Left)
            {
                if(!m_Sword.getExecution() && m_canmove)
                {
                    if(!m_Player.getOrientationLeft())
                    {
                        m_Player.setOrientationLeft();
                    }
                    m_Player.animationMoveLeft();
                }
            }
            else if(this -> m_Event.key.code == sf::Keyboard::Right)
            {
                if(!m_Sword.getExecution() && m_canmove)
                {
                    if(!m_Player.getOrientationRight())
                    {
                        m_Player.setOrientationRight();
                    }
                    m_Player.animationMoveRight();
                }
            }
            else if(this -> m_Event.key.code == sf::Keyboard::Space)
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
        }
    }
}