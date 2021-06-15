/**
 * @file HeartPublicLifeBar.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Heart.hpp"

void Heart::updateHeart(void)
{
    int numberheart = m_life / 4,
        lastheart = m_life % 4,
        taillist = m_maxlife / 4,
        positionx = 0,
        positiony = 0,
        size = 0;

    this -> m_List.clear();

    std::vector<sf::Sprite> listelife(numberheart, m_S0Heart),
                            listeheart(taillist, m_S0Heart);

    // full heart
    for(size = 0; size < listelife.size(); size ++)
    {
        this -> m_List.push_back(setSpritePosition(m_S4Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
        positionx ++;
        if(positionx == 10)
        {
            positionx = 0;
            positiony ++;
        }
    }
    
    // quart heart
    if(lastheart == 1)
    {
        this -> m_List.push_back(setSpritePosition(m_S1Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
    }
    else if(lastheart == 2)
    {
        this -> m_List.push_back(setSpritePosition(m_S2Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
    }
    else if(lastheart == 3)
    {
        this -> m_List.push_back(setSpritePosition(m_S3Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
    }

    // empty heart
    for(size = size; size < listeheart.size(); size ++)
    {
        this -> m_List.push_back(setSpritePosition(m_S0Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
        positionx ++;
        if(positionx == 10)
        {
            positionx = 0;
            positiony ++;
        }
    }
}
void Heart::setPosition(sf::Sprite sprite, sf::Vector2f position)
{
    sprite.setPosition(position);
}
void Heart::setMaxLifeUp(void)
{
    m_maxlife += 4;
    m_life = m_maxlife;
}
void Heart::setHeart(int life)
{
    m_life += life;
    if(m_life > m_maxlife)
    {
        m_life = m_maxlife;
    }
    updateHeart();
}
void Heart::setDamage(int power)
{
    if(!m_invulnerable)
    {
        m_life -= power;
        if(m_life <= 0)
        {
            m_life = 0;
            m_alive = false;
        }
        m_invulnerable = true;
        m_invulnerability = 0;
    }
    updateHeart();
}
void Heart::frameInvulnerable(void)
{
    if(m_invulnerability == m_frameinvulnerable)
    {
        m_invulnerable = false;
    }
    m_invulnerability ++;
}