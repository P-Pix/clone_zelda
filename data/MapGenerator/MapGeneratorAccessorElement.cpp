/**
 * @file MapGeneratorAccessorElement.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MapGenerator.hpp"

bool MapGenerator::hasTree()
{
    return m_tree;
}
bool MapGenerator::hasGround()
{
    return m_ground;
}
bool MapGenerator::hasCavern()
{
    return m_cavern;
}
bool MapGenerator::hasBloc()
{
    return m_bloc;
}
int MapGenerator::getMapX()
{
    return m_x;
}
int MapGenerator::getMapY()
{
    return m_y;
}
bool MapGenerator::thereChest()
{
    return m_Chest.getChest();
}
sf::Sprite MapGenerator::getChestSprite()
{
    return m_Chest.getSprite();
}
sf::Sprite MapGenerator::getGainSprite()
{
    return m_Chest.getSpriteGain();
}
int MapGenerator::getGainRubis()
{
    return m_Chest.getValorRubis();
}
int MapGenerator::getGainLife()
{
    return m_Chest.getValorLife();
}