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