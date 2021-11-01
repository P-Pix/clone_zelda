/**
 * @file MapGeneratorPublicChest.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/MapGenerator.hpp"

void MapGenerator::oprenChest(void) {
    m_Chest.openChest();
}

void MapGenerator::gainIsGet(void) {
    m_Chest.isGet();
}