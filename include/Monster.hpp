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

#ifndef _MONSTER_HPP_
#define _MONSTER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Gain.hpp"
#include "Heart.hpp"
//#include "Ai.hpp"

class Monster {
public:
    // Constructeur / Destructeur
    // Constructeur
    Monster(void);

    Monster(const char *name);

    // Destructeur
    ~Monster(void);

    // Accessor
    Monster *getAdress(void);

    Monster getMonster(void);

    // Sprite
    sf::Sprite getSprite(void);

    // Position
    sf::Vector2f getPosition(void);

    sf::Vector2f getNextPosition(void);

    // Power
    int getPower(void);

    // alive
    bool isAlive(void);

    int getGainRubisValor(void);

    int getGainLifeValor(void);

    bool thereGain(void);

    bool isInvulnerable(void);

    // Function
    // Attribution
    void setPower(int power);

    void moove(void);

    void nextPosition(void);

    void setDamage(int power);

    void recoilUp(void);

    void recoilDown(void);

    void recoilRight(void);

    void recoilLeft(void);

    void createPaternRelative(void);

    void gainIsGet(void);

    void frameInvulnerable(void);

private:
    // Variable
    // basic
    int m_moveaction = 0,
            m_power = 4;

    const char *m_monster = "image/monster1.png";

    // std
    std::vector <sf::Vector2f> m_Patern;

    // SFML
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

    // class
    Gain m_Gain;
    Heart m_Heart;

    // Function
    void loadTexture(const char *name);

    void loadSprite(void);

    void initSprite(void);

    void loadPosition(void);

    void dropGain(void);

};

#endif