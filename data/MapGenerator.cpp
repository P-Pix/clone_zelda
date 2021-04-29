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
    char    lettre;
    openMap();

    m_WallExt.clear();
    m_GroundExt.clear();
    m_WallInt.clear();
    m_GroundInt.clear();

    for(int positiony = 0; positiony < 10; positiony ++)
    {
        for(int positionx = 1; positionx <= 17; positionx ++)
        {
            this -> m_map -> get(lettre);
            if(lettre == 't')
            {
                m_WallExt.push_back(sf::Vector2f(positiony * 64.f, positionx * 64.f));
            }
            else if(lettre == 'g')
            {
                m_GroundExt.push_back(sf::Vector2f(positiony * 64.f, positionx * 64.f));                
            }
            else if(lettre == 'b')
            {
                m_WallInt.push_back(sf::Vector2f(positiony * 64.f, positionx * 64.f));                
            }
            else if(lettre == 'c')
            {
                m_GroundInt.push_back(sf::Vector2f(positiony * 64.f, positionx * 64.f));                
            }
        }
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

void MapGenerator::openMap()
{
    std::string name = "data/maping/" + std::to_string(m_y) + "_" + std::to_string(m_x) + ".xsb";
    this -> m_map -> open(name);
}