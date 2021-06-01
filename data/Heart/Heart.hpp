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

#if !defined(__HEART__)
#define __HEART__

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
class Heart
{
    public:
        // Constructor / Destructor
            Heart();
            Heart(int frameinvulnerable);
            ~Heart();

        // Accessor
            std::vector<sf::Sprite> getListSprite();
            sf::Sprite getSprite(int number);

            int getLife();
            int getMaxLife();

            bool isAlive();
            bool isInvulnerable();

        // Function
            void updateHeart();
            void setPosition(sf::Sprite sprite, sf::Vector2f position);

            void setMaxLifeUp();
            void setHeart(int life);
            void setDamage(int power);
            void frameInvulnerable();

    private:
        // Variable
            // basic
                int m_life = 12,
                    m_maxlife = 12,

                    m_invulnerability = 0,
                    m_frameinvulnerable = 120;
                
                bool    m_alive = true,
                        m_invulnerable = false;

                const char  *m_name0 = "skin/heart04.png",
                            *m_name1 = "skin/heart14.png",
                            *m_name2 = "skin/heart24.png",
                            *m_name3 = "skin/heart34.png",
                            *m_name4 = "skin/heart44.png";
            
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
            void initConstructor();

};

#endif