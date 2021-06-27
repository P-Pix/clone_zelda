/**
 * @file MapGeneratorPublicCreateMap.cpp
 * @author Guillaume LEMONNIER
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/MapGenerator.hpp"


#include "../printing.cpp"

std::vector<sf::Vector2f> MapGenerator::addVector2f(std::vector<sf::Vector2f> list, sf::Vector2f position)
{
    list.push_back(position);
    return list;
}
///////////////////////////////////////

void MapGenerator::positionLetter(char lettre, int positionx, int positiony, int x)
{
    if(lettre == m_listletter[x])
    {
        m_listvector[x] = addVector2f(m_listvector[x], sf::Vector2f(positionx * 64.f, positiony * 64.f));
        m_listbool[x] = true;
    }
}

void MapGenerator::generateMap(void)
{
    // Open the file
    std::string name = "maping/" + std::to_string(m_y) + "_" + std::to_string(m_x) + "map.xsb";
    std::ifstream ifmap(name);

    char lettre;

    m_map.clear();

    for(int x = 0; x < NUMBER_ELEMENT; x ++)
    {
        m_listbool[x] = false;
        m_listvector[x].clear();
    }

    //m_Chest.generateChest(void);

    for(int positiony = 1; positiony < TILE_Y + 1; positiony ++)
    {
        std::vector<char> ligne;
        for(int positionx = 0; positionx < TILE_X; positionx ++)
        {
            ifmap.get(lettre);
            for(int x = 0; x < NUMBER_ELEMENT; x ++)
            {
                positionLetter(lettre, positionx, positiony, x);
            }
            ligne.push_back(lettre);
        }
        m_map.push_back(ligne);
    }
    std::cout << m_map << std::endl;
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