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

#include "../../include/MapGenerator.hpp"

bool MapGenerator::hasTree(void)
{
    return m_tree;
}
bool MapGenerator::hasGround(void)
{
    return m_ground;
}
bool MapGenerator::hasCavern(void)
{
    return m_cavern;
}
bool MapGenerator::hasBloc(void)
{
    return m_bloc;
}
int MapGenerator::getMapX(void)
{
    return m_x;
}
int MapGenerator::getMapY(void)
{
    return m_y;
}
bool MapGenerator::thereChest(void)
{
    return m_Chest.getChest();
}
sf::Sprite MapGenerator::getChestSprite(void)
{
    return m_Chest.getSprite();
}
sf::Sprite MapGenerator::getGainSprite(void)
{
    return m_Chest.getSpriteGain();
}
int MapGenerator::getGainRubis(void)
{
    return m_Chest.getValorRubis();
}
int MapGenerator::getGainLife(void)
{
    return m_Chest.getValorLife();
}