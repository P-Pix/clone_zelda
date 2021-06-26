/**
 * @file MapGeneratorPublicCreateMap.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/MapGenerator.hpp"

void MapGenerator::addBridge(sf::Vector2f position)
{
    m_Bridge.push_back(position);
    m_boolbridge = true;
}
void MapGenerator::addDust(sf::Vector2f position)
{
    m_Dust.push_back(position);
    m_booldust = true;
}
void MapGenerator::addSlad(sf::Vector2f position)
{
    m_Slad.push_back(position);
    m_boolslad = true;
}

///////////////////////////////////////

void MapGenerator::addOrangeTree(sf::Vector2f position)
{
    m_OrangeTree.push_back(position);
    m_boolorangetree = true;
}
void MapGenerator::addTree(sf::Vector2f position)
{
    m_Tree.push_back(position);
    m_booltree = true;
}
void MapGenerator::addWall(sf::Vector2f position)
{
    m_Wall.push_back(position);
    m_boolwall = true;
}
void MapGenerator::addWater(sf::Vector2f position)
{
    m_Water.push_back(position);
    m_boolwater = true;
}
void MapGenerator::addWhiteTree(sf::Vector2f position)
{
    m_WhiteTree.push_back(position);
    m_boolwhitetree = true;
}

///////////////////////////////////////

void (MapGenerator::*ptr[8])(sf::Vector2f) = 
{
    MapGenerator::addBridge,
    MapGenerator::addDust,
    MapGenerator::addSlad,

    MapGenerator::addOrangeTree,
    MapGenerator::addTree,
    MapGenerator::addWall,
    MapGenerator::addWater,
    MapGenerator::addWhiteTree,
};

char listletter[8] = 
{
    'p',
    'g',
    's',

    'o',
    't',
    'b',
    'e',
    'w'
};

void MapGenerator::generateMap(void)
{
    // Open the file
    std::string name = "maping/" + std::to_string(m_y) + "_" + std::to_string(m_x) + "map.xsb";
    std::ifstream ifmap(name);

    std::string ligne;

    char lettre;

    m_Tree.clear();
    m_Wall.clear();
    m_OrangeTree.clear();
    m_WhiteTree.clear();
    m_Water.clear();

    m_Dust.clear();
    m_Slad.clear();
    m_Bridge.clear();

    m_map.clear();

    m_booltree = false;
    m_boolorangetree = false;
    m_boolwater = false;
    m_boolwall = false;
    m_boolwhitetree = false;

    m_booldust = false;
    m_boolbridge = false;
    m_boolslad = false;

    //m_Chest.generateChest(void);

    for(int positiony = 1; positiony < 12; positiony ++)
    {
        std::vector<char> ligne;
        for(int positionx = 0; positionx < 17; positionx ++)
        {
            ifmap.get(lettre);
            for(int x = 0; x < 8; x ++)
            {
                if(lettre == listletter[x])
                {
                    //std::cout << lettre;
                    ptr[x](sf::Vector2f(positionx * 64.f, positiony * 64.f));
                }
            }
            ligne.push_back(lettre);
        }
        //std::cout << std::endl;
        m_map.push_back(ligne);
    }
    ifmap.close();
}

void MapGenerator::setMapDown(void)
{
    m_y += 1;
}
void MapGenerator::setMapUp(void)
{
    m_y -= 1;
}
void MapGenerator::setMapLeft(void)
{
    m_x -= 1;
}
void MapGenerator::setMapRight(void)
{
    m_x += 1;
}