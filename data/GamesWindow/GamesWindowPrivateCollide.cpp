/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::collideMonster()
{
    makeListMonster();
    for(int x = 0; x < m_listmob.size(); x ++)
    {
        if(collideTwoSprite64x64(m_Player.getPosition(), m_listmob[x].getPosition()) && m_listmob[x].isAlive())
        {
            m_Player.setDamage(m_listmob[x].getPower());
            collidePosition(m_Player.getPosition(), m_listmob[x].getPosition());
            if(m_collidedown && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, -64.f)))
            {
                m_Player.recoilUp();
            }
            else if(m_collideup && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, 64.f)))
            {
                m_Player.recoilDown();
            }
            else if(m_collideright && !previewCollide(m_Player.getPosition(), sf::Vector2f(-64.f, 0.f)))
            {
                m_Player.recoilLeft();
            }
            else if(m_collideleft && !previewCollide(m_Player.getPosition(), sf::Vector2f(64.f, 0.f)))
            {
                m_Player.recoilRight();
            }
        }
        else if(collideTwoSprite64x64(m_Player.getPosition(), m_listmob[x].getPosition()) && !m_listmob[x].isAlive())
        {
            m_Player.setHeart(m_listmob[x].getGainLifeValor());
            m_Player.updateRubis(m_listmob[x].getGainRubisValor());
        }
        /*
        if(!m_listmob[x].isAlive())
        {
            this -> m_listmob[x] = new Monster;
        }
        */
    }
}
bool GamesWindow::collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2)
{
    int sprite1x = sprite1.x,
        sprite1y = sprite1.y,

        sprite2x = sprite2.x,
        sprite2y = sprite2.y;

    return (sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y);
}
void GamesWindow::collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2)
{
    int sprite1x = sprite1.x,
        sprite1y = sprite1.y,

        sprite2x = sprite2.x,
        sprite2y = sprite2.y;

    m_collidedown = false;
    m_collideleft = false;
    m_collideright = false;
    m_collideup = false;

    
    if(sprite1x < sprite2x + 64 && sprite1x + 64 > sprite2x && sprite1y < sprite2y + 64 && sprite1y > sprite2y)
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
bool GamesWindow::collideSword(sf::Vector2f sprite)
{
    int sprite1x = m_Sword.getPosition().x,
        sprite1y = m_Sword.getPosition().y,

        sprite2x = sprite.x,
        sprite2y = sprite.y;

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
bool GamesWindow::collideWall(sf::Vector2f sprite, std::vector<sf::Vector2f> wall)
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
bool GamesWindow::previewCollide(sf::Vector2f user, sf::Vector2f moove)
{
    int nextx = user.x + moove.x,
        nexty = user.y + moove.y;

    bool collide = false;

    if(m_Map.hasTree())
    {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWallExt());
    }
    if(m_Map.hasBloc() && !collide)
    {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWallInt());
    }
    return collide;
}