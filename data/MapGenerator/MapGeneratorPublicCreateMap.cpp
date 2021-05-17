/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "MapGenerator.hpp"
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

void MapGenerator::generateMap()
{
    // Open the file
    std::string name = "data/maping/" + std::to_string(m_y) + "_" + std::to_string(m_x) + "map.xsb";
    std::ifstream ifmap(name);

    // generate the Vector2f
    std::string ligne;
    char lettre;
    m_WallExt.clear();
    m_GroundExt.clear();
    m_WallInt.clear();
    m_GroundInt.clear();

    m_bloc = false;
    m_cavern = false;
    m_ground = false;
    m_tree = false;

    for(int positiony = 1; positiony < 11; positiony ++)
    {
        for(int positionx = 0; positionx < 18; positionx ++)
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
        }
        //std::cout << std::endl;
    }
}

void MapGenerator::setMapDown()
{
    m_y += 1;
}
void MapGenerator::setMapUp()
{
    m_y -= 1;
}
void MapGenerator::setMapLeft()
{
    m_x -= 1;
}
void MapGenerator::setMapRight()
{
    m_x += 1;
}