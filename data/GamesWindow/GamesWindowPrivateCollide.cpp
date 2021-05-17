/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

void GamesWindow::collideMonster()
{
    makeListMonster();
    for(int x = 0; x < m_listmob.size(); x ++)
    {
        if(collideUser(m_listmob[x].getPosition()))
        {
            m_Player.setDamage(m_listmob[x].getPower());
            m_Heart.updateHeart(m_Player.getLife(), m_Player.getMaxLife());
            collidePosition(m_Player.getSprite(), m_listmob[x].getSprite());
            if(m_collidedown)
            {
                m_Player.recoilDown();
            }
            else if(m_collideup)
            {
                m_Player.recoilUp();
            }
            else if(m_collideright)
            {
                m_Player.recoilRight();
            }
            else if(m_collideleft)
            {
                m_Player.recoilLeft();
            }
        }
        /*
        if(!m_listmob[x].isAlive())
        {
            m_listmob[x].~Monster();
        }
        */
    }
}
bool GamesWindow::collideUser(sf::Vector2f sprite)
{
    int sprite1x = m_Player.getPosition().x,
        sprite1y = m_Player.getPosition().y,

        sprite2x = sprite.x,
        sprite2y = sprite.y;

    return (sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y);
}
void GamesWindow::collidePosition(sf::Sprite sprite1, sf::Sprite sprite2)
{
    int sprite1x = sprite1.getPosition().x,
        sprite1y = sprite1.getPosition().y,

        sprite2x = sprite2.getPosition().x,
        sprite2y = sprite2.getPosition().y;

    m_collidedown = false;
    m_collideleft = false;
    m_collideright = false;
    m_collideup = false;

    
    if(sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 32 > sprite2y)
    {
        //x>=y avec y < 32 alors partie haut
        m_collideup = true;   
    }
    else if(sprite1x <= sprite2x + 64 && sprite1x + 32 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y)
    {
        //y>=x avec x < 32 alors partie gauche
        m_collideleft = true;
    }
    else if(sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y)
    {
        //x>=y avec x >= 32 alors partie droite
        m_collideright = true;
    }
    else if(sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y)
    {
        //y>=x avec y >= 32 alors partie bas
        m_collidedown = true;                
    }
}
bool GamesWindow::collideSword(sf::Sprite sprite)
{
    int sprite1x = m_Sword.getSprite().getPosition().x,
        sprite1y = m_Sword.getSprite().getPosition().y,

        sprite2x = sprite.getPosition().x,
        sprite2y = sprite.getPosition().y;

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
bool GamesWindow::collideWall(std::vector<sf::Vector2f> wall)
{
    for(int x = 0; x < wall.size(); x ++)
    {
        if(collideUser(wall[x]))
        {
            return true;
        }
    }
    return false;
}