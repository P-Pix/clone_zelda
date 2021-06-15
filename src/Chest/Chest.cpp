/**
 * @file Chest.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Chest.hpp"

Chest::Chest(void)
{
    loadSprite(m_namechestclose);
    m_Sprite.setPosition(sf::Vector2f(512.f, 320.f));
    std::srand(std::time(nullptr));
}
Chest::~Chest(void)
{

}