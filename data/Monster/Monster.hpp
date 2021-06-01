/**
 * @file Monster.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__MONSTER__)
#define __MONSTER__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../Gain/Gain.hpp"
#include "../Heart/Heart.hpp"
//#include "Ai.hpp"

class Monster
{
    public:
        // Constructeur / Destructeur
            // Constructeur
                Monster();
                Monster(const char *name);
            
            // Destructeur
                ~Monster();
                
        // Accessor
            // Sprite
                sf::Sprite getSprite();

            // Position
                sf::Vector2f getPosition();
                sf::Vector2f getNextPosition();

            // Power
                int getPower();

            // alive
                bool isAlive();
                int getGainRubisValor();
                int getGainLifeValor();
                bool thereGain();
                bool isInvulnerable();

        // Function
            // Attribution
                void setPower(int power);
                void moove();
                void nextPosition();
                void setDamage(int power);

                void recoilUp();
                void recoilDown();
                void recoilRight();
                void recoilLeft();

                void createPaternRelative();
                void gainIsGet();
                void frameInvulnerable();
    
    private:
        // Variable
            // basic
                int m_moveaction = 0,
                    m_power = 4;

                const char *m_monster = "skin/monster1.png";

            // std
                std::vector<sf::Vector2f> m_Patern;

            // SFML
                sf::Sprite  m_Sprite;
                sf::Texture m_Texture;
            
            // class
                Gain m_Gain;
                Heart m_Heart;

        // Function
            void loadTexture(const char *name);
            void loadSprite();
            void initSprite();
            void loadPosition();
            void dropGain();

};

#endif