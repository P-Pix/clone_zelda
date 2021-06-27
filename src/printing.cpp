/**
 * @file printing.cpp
 * @author Guillaume LEMONNIER
 * @date 2021-06-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
#include <iostream>

std::ostream &operator<<(std::ostream &flux, std::vector<std::vector<char>> map)
{
    for(int y = 0; y < map.size(); y ++)
    {
        for(int x = 0; x < map[y].size(); x ++)
        {
            flux << " ";
            flux << map[y][x];
        }
    }
    return flux;
}