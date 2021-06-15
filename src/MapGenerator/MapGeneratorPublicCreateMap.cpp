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

void MapGenerator::generateMap(void)
{
    // Open the file
    std::string name = "maping/" + std::to_string(m_y) + "_" + std::to_string(m_x) + "map.xsb";
    std::ifstream ifmap(name);

    // generate the Vector2f
    std::string ligne;
    char lettre;
    m_WallExt.clear();
    m_GroundExt.clear();
    m_WallInt.clear();
    m_GroundInt.clear();
    m_map.clear();

    m_bloc = false;
    m_cavern = false;
    m_ground = false;
    m_tree = false;

    //m_Chest.generateChest(void);

    for(int positiony = 1; positiony < 12; positiony ++)
    {
        std::vector<char> ligne;
        for(int positionx = 0; positionx < 17; positionx ++)
        {
            ifmap.get(lettre);
            if(lettre == 't')
            {
                //std::cout << "t ";
                m_WallExt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));
                m_tree = true;
            }
            else if(lettre == 'g')
            {
                //std::cout << "g ";
                m_GroundExt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));
                m_ground = true;         
            }
            else if(lettre == 'b')
            {
                //std::cout << "b ";
                m_WallInt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));
                m_bloc = true;          
            }
            else if(lettre == 'c')
            {
                //std::cout << "c ";
                m_GroundInt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));
                m_cavern = true;           
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