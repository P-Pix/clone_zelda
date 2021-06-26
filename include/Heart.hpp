/**
 * @file Heart.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _HEART_HPP_
#define _HEART_HPP_

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
class Heart
{
    public:
        // Constructor / Destructor
            Heart(void);
            Heart(int frameinvulnerable);
            ~Heart(void);

        // Accessor
            std::vector<sf::Sprite> getListSprite(void);
            sf::Sprite getSprite(int number);

            int getLife(void);
            int getMaxLife(void);

            bool isAlive(void);
            bool isInvulnerable(void);

        // Function
            void updateHeart(void);
            void setPosition(sf::Sprite sprite, sf::Vector2f position);

            void setMaxLifeUp(void);
            void setHeart(int life);
            void setDamage(int power);
            void frameInvulnerable(void);

    private:
        // Variable
            // basic
                int m_life = 12,
                    m_maxlife = 12,

                    m_invulnerability = 0,
                    m_frameinvulnerable = 120;
                
                bool    m_alive = true,
                        m_invulnerable = false;

                const char  *m_name0 = "image/heart04.png",
                            *m_name1 = "image/heart14.png",
                            *m_name2 = "image/heart24.png",
                            *m_name3 = "image/heart34.png",
                            *m_name4 = "image/heart44.png";
            
            // std
                std::vector<sf::Sprite> m_List;

            // SFML
                sf::Texture m_T0Heart,
                            m_T1Heart,
                            m_T2Heart,
                            m_T3Heart,
                            m_T4Heart;
                
                sf::Sprite  m_S0Heart,
                            m_S1Heart,
                            m_S2Heart,
                            m_S3Heart,
                            m_S4Heart;

        // Function
            sf::Sprite setSpritePosition(sf::Sprite sprite, sf::Vector2f position);
            void listeHeartConstructor(int life);
            void heartConstructor(int partie);
            void initConstructor(void);

};

#endif