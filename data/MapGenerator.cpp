#include "MapGenerator.hpp"
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

// Constructor / Destructor

MapGenerator::MapGenerator()
{
    //std::cout << "map generator create " << this << std::endl;
}

MapGenerator::~MapGenerator()
{
    //std::cout << "map generator delete " << this << std::endl;
}

// Accessor

std::vector<sf::Vector2f> MapGenerator::getListPositionWallExt()
{
    return m_WallExt;
}

std::vector<sf::Vector2f> MapGenerator::getListPositionGroundExt()
{
    return m_GroundExt;
}

std::vector<sf::Vector2f> MapGenerator::getListPositionWallInt()
{
    return m_WallInt;
}

std::vector<sf::Vector2f> MapGenerator::getListPositionGroundInt()
{
    return m_GroundInt;
}

// Function public

void MapGenerator::generateMap()
{
    // Open the file
    std::string name = "data/maping/" + std::to_string(m_y) + "_" + std::to_string(m_x) + ".xsb";
    std::ifstream ifmap(name);
    /*
    if(ifmap)
    {
        std::cout << "open" << std::endl;
    }
    else
    {
        std::cout << "no open" << std::endl;
    }
    */

    // generate the Vector2f
    std::string ligne;
    char    lettre;
    m_WallExt.clear();
    m_GroundExt.clear();
    m_WallInt.clear();
    m_GroundInt.clear();

    for(int positiony = 1; positiony < 11; positiony ++)
    {
        for(int positionx = 0; positionx < 18; positionx ++)
        {
            ifmap.get(lettre);
            if(lettre == 't')
            {
                //std::cout << "t ";
                m_WallExt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));
            }
            else if(lettre == 'g')
            {
                //std::cout << "g ";
                m_GroundExt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));                
            }
            else if(lettre == 'b')
            {
                //std::cout << "b ";
                m_WallInt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));                
            }
            else if(lettre == 'c')
            {
                //std::cout << "c ";
                m_GroundInt.push_back(sf::Vector2f(positionx * 64.f, positiony * 64.f));                
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

// Function private