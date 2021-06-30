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

bool MapGenerator::hasBridge(void)
{
    return m_listbool[0];
}
bool MapGenerator::hasDust(void)
{
    return m_listbool[1];
}
bool MapGenerator::hasSlad(void)
{
    return m_listbool[2];
}

bool MapGenerator::hasOrangeTree(void)
{
    return m_listbool[3];
}
bool MapGenerator::hasTree(void)
{
    return m_listbool[4];
}
bool MapGenerator::hasWall(void)
{
    return m_listbool[5];
}
bool MapGenerator::hasWater(void)
{
    return m_listbool[6];
}
bool MapGenerator::hasWhiteTree(void)
{
    return m_listbool[7];
}

bool MapGenerator::hasGreyDust(void)
{
    return m_listbool[8];
}
bool MapGenerator::hasRock(void)
{
    return m_listbool[9];
}
bool MapGenerator::hasRedRock(void)
{
    return m_listbool[10];
}

bool MapGenerator::hasWhiteRock(void)
{
    return m_listbool[11];
}
///////////////////////////////////////

int MapGenerator::getMapX(void)
{
    return m_x;
}
int MapGenerator::getMapY(void)
{
    return m_y;
}

///////////////////////////////////////

bool MapGenerator::thereChest(void)
{
    return m_Chest.getChest();
}

///////////////////////////////////////

sf::Sprite MapGenerator::getChestSprite(void)
{
    return m_Chest.getSprite();
}
sf::Sprite MapGenerator::getGainSprite(void)
{
    return m_Chest.getSpriteGain();
}

///////////////////////////////////////

int MapGenerator::getGainRubis(void)
{
    return m_Chest.getValorRubis();
}
int MapGenerator::getGainLife(void)
{
    return m_Chest.getValorLife();
}

///////////////////////////////////////

std::vector<sf::Vector2f> MapGenerator::getListPositionBridge(void)
{
    return m_listvector[0];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionDust(void)
{
    return m_listvector[1];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionSlad(void)
{
    return m_listvector[2];
}

std::vector<sf::Vector2f> MapGenerator::getListPositionOrangeTree(void)
{
    return m_listvector[3];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionTree(void)
{
    return m_listvector[4];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionWall(void)
{
    return m_listvector[5];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionWater(void)
{
    return m_listvector[6];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionWhiteTree(void)
{
    return m_listvector[7];
}

std::vector<sf::Vector2f> MapGenerator::getListPositionGreyDust(void)
{
    return m_listvector[8];
}

std::vector<sf::Vector2f> MapGenerator::getListPositionRock(void)
{
    return m_listvector[9];
}
std::vector<sf::Vector2f> MapGenerator::getListPositionRedRock(void)
{
    return m_listvector[10];
}

std::vector<sf::Vector2f> MapGenerator::getListPositionWhiteRock(void)
{
    return m_listvector[11];
}


///////////////////////////////////////

std::vector<std::vector<char>> MapGenerator::getMap(void)
{
    return m_map;
}