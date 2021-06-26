/**
 * @file GamePrivateCollide.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Game.hpp"

void Game::collideMonster(void)
{
    if(collideTwoSprite64x64(m_Player.getPosition(), m_Mob1.getPosition()))
    {
        if(m_Mob1.isAlive())
        {
            m_Player.setDamage(m_Mob1.getPower());
            collidePosition(m_Player.getPosition(), m_Mob1.getPosition());
            if(!m_Sword.getExecution())
            {
                if(m_collidedown && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, -64.f)) && !previewLimitMap(m_Player.getPosition(), sf::Vector2f(0.f, -64.f)))
                {
                    m_Player.recoilUp();
                }
                else if(m_collideup && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, 64.f)) && !previewLimitMap(m_Player.getPosition(), sf::Vector2f(0.f, 64.f)))
                {
                    m_Player.recoilDown();
                }
                else if(m_collideright && !previewCollide(m_Player.getPosition(), sf::Vector2f(-64.f, 0.f)) && !previewLimitMap(m_Player.getPosition(), sf::Vector2f(-64.f, 0.f)))
                {
                    m_Player.recoilLeft();
                }
                else if(m_collideleft && !previewCollide(m_Player.getPosition(), sf::Vector2f(64.f, 0.f)) && !previewLimitMap(m_Player.getPosition(), sf::Vector2f(64.f, 0.f)))
                {
                    m_Player.recoilRight();
                }
            }
        }
        else if(m_Mob1.thereGain())
        {
            m_Player.setHeart(m_Mob1.getGainLifeValor());
            m_Player.updateRubis(m_Mob1.getGainRubisValor());
            m_Mob1.gainIsGet();
        }
    }
}
bool Game::collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2)
{
    float   sprite1x = sprite1.x,
            sprite1y = sprite1.y,

            sprite2x = sprite2.x,
            sprite2y = sprite2.y;

    return (sprite1x + 5 <= sprite2x + 64 && sprite1x + 59 >= sprite2x && sprite1y + 32 <= sprite2y + 64 && sprite1y + 64 > sprite2y);
}
void Game::collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2)
{
    float   sprite1x = sprite1.x,
            sprite1y = sprite1.y,

            sprite2x = sprite2.x,
            sprite2y = sprite2.y;

    m_collidedown = false;
    m_collideleft = false;
    m_collideright = false;
    m_collideup = false;

    
    if(sprite1x < sprite2x + 64 && sprite1x + 64 > sprite2x && sprite1y < sprite2y + 64 && sprite1y + 32 > sprite2y)
    {
        m_collideup = true;   
    }
    else if(sprite1x < sprite2x + 64 && sprite1x + 64 > sprite2x + 64 && sprite1y + 64 > sprite2y && sprite1y + 64 < sprite2y + 64)
    {
        m_collideleft = true;                
    }
    else if(sprite1x < sprite2x && sprite1x + 64 > sprite2x && sprite1y < sprite2y + 64 && sprite1y + 64 > sprite2y)
    {
        m_collideright = true;
    }
    else if(sprite1x < sprite2x + 64 && sprite1x + 64 > sprite2x && sprite1y + 64 > sprite2y && sprite1y + 64 < sprite2y + 64)
    {
        m_collidedown = true;
    }
}
bool Game::collideSword(sf::Vector2f target)
{
    float   sprite1x = m_Sword.getPosition().x,
            sprite1y = m_Sword.getPosition().y,

            sprite2x = target.x,
            sprite2y = target.y;

    if(m_Sword.getAttackDown())
    {
        return (sprite1x >= sprite2x && sprite1x - 64 <= sprite2x + 64 && sprite1y + 64 >= sprite2y && sprite1y + 64 <= sprite2y + 64);
    }
    else if(m_Sword.getAttackLeft())
    {
        return (sprite1x - 64 <= sprite2x + 64 && sprite1x - 64 >= sprite2x && sprite1y >= sprite2y && sprite1y - 64 <= sprite2y + 64);
    }
    else if(m_Sword.getAttackRight())
    {
        return (sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y);
    }
    else if(m_Sword.getAttackUp())
    {
        return (sprite1x + 64 >= sprite2x && sprite1x <= sprite2x + 64 && sprite1y - 64 <= sprite2y + 64 && sprite1y - 64 >= sprite2y);
    }
    return false;
}
bool Game::collideWall(sf::Vector2f sprite, std::vector<sf::Vector2f> wall)
{
    for(int x = 0; x < wall.size(); x ++)
    {
        if(collideTwoSprite64x64(sprite, wall[x]))
        {
            return true;
        }
    }
    return false;
}
bool Game::previewCollide(sf::Vector2f user, sf::Vector2f moove)
{
    float   nextx = user.x + moove.x,
            nexty = user.y + moove.y;

    bool collide = false;

    if(m_Map.hasTree())
    {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionTree());
    }
    if(m_Map.hasWall() && !collide)
    {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWall());
    }
    if(m_Map.thereChest() && !collide)
    {
        collide = collideTwoSprite64x64(sf::Vector2f(nextx, nexty), m_Map.getChestSprite().getPosition());
    }
    return collide;
}
bool Game::previewLimitMap(sf::Vector2f user, sf::Vector2f moove)
{
    float   nextx = user.x + moove.x,
            nexty = user.y + moove.y;

    if(nextx > 768 || nextx < 0 || nexty > 1024 || nexty < 0)
    {
        return true;
    }
    return false;
}