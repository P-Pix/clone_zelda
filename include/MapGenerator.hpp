/**
 * @file MapGenerator.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _MAPGENERATOR_HPP_
#define _MAPGENERATOR_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Chest.hpp"

#define NUMBER_ELEMENT  9
#define TILE_X          17
#define TILE_Y          11

class MapGenerator
{
    private:
        int m_x = 7, // 7 start / 0 area test
            m_y = 8; // 8 start / 0 area test

        std::vector<std::vector<char>> 
            m_map;

        std::string *m_String;
        std::fstream *m_Fmap;

        // class
        Chest m_Chest;

        /// add the position the Dust list
        /// \param list vector2f list
        /// \param position x and y coord
        std::vector<sf::Vector2f> addVector2f(std::vector<sf::Vector2f> list, sf::Vector2f position);

        void positionLetter(char letter, int positionx, int positiony, int x);

        bool    m_booltree          = false,
                m_boolwall          = false,
                m_boolorangetree    = false,
                m_boolwater         = false,
                m_boolwhitetree     = false,

                m_boolbridge        = false,
                m_boolslad          = false,
                m_booldust          = false,
                m_boolgreydust      = false;
                
        std::vector<sf::Vector2f> 
            m_Bridge,
            m_Dust,
            m_Slad,

            m_Tree,
            m_OrangeTree,
            m_WhiteTree,
            m_Water,
            m_Wall,
            m_GreyDust;

        std::vector<sf::Vector2f> m_listvector[NUMBER_ELEMENT] = 
        {
            MapGenerator::m_Bridge,
            MapGenerator::m_Dust,
            MapGenerator::m_Slad,

            MapGenerator::m_OrangeTree,
            MapGenerator::m_Tree,
            MapGenerator::m_Wall,
            MapGenerator::m_Water,
            MapGenerator::m_WhiteTree,
            MapGenerator::m_GreyDust
        };

        bool m_listbool[NUMBER_ELEMENT] = 
        {
            MapGenerator::m_boolbridge,
            MapGenerator::m_booldust,
            MapGenerator::m_boolslad,

            MapGenerator::m_boolorangetree,
            MapGenerator::m_booltree,
            MapGenerator::m_boolwall,
            MapGenerator::m_boolwater,
            MapGenerator::m_boolwhitetree,
            MapGenerator::m_boolgreydust
        };

        char m_listletter[NUMBER_ELEMENT] = 
        {
            'p', // Bridge      0
            'g', // Dust        1
            's', // Slad        2

            'o', // Orange Tree 3
            't', // Tree        4
            'b', // Wall        5
            'e', // Water       6
            'w', // White Tree  7
            'x'  // Grey Dust   8
        };

    public:
        /// Default constructor
        MapGenerator(void);

        /// Destructor
        ~MapGenerator(void);

        ////////////////////////////////////////

        /// \return position Tree list
        std::vector<sf::Vector2f> getListPositionTree(void);

        /// \return position Orange Tree list
        std::vector<sf::Vector2f> getListPositionOrangeTree(void);

        /// \return position White Tree list
        std::vector<sf::Vector2f> getListPositionWhiteTree(void);

        /// \return position Water list
        std::vector<sf::Vector2f> getListPositionWater(void);

        /// \return position Wall list
        std::vector<sf::Vector2f> getListPositionWall(void);

        ////////////////////////////////////////

        /// \return position Bridge list
        std::vector<sf::Vector2f> getListPositionBridge(void);

        /// \return position Dust list
        std::vector<sf::Vector2f> getListPositionDust(void);

        /// \return position Slad list
        std::vector<sf::Vector2f> getListPositionSlad(void);

        std::vector<sf::Vector2f> getListPositionGreyDust(void);

        /// \return map matrix 
        std::vector<std::vector<char>> getMap(void);

        ////////////////////////////////////////

        /// \return True if the map has Dust
        bool hasDust(void);

        /// \return True if the map has Sald
        bool hasSlad(void);

        /// \return True if the map has Bridge
        bool hasBridge(void);

        /// \return True if the maphas Grey Dust
        bool hasGreyDust(void);

        ////////////////////////////////////////

        /// \return True if the map has Wall
        bool hasWall(void);

        /// \return True if the map has Water
        bool hasWater(void);

        /// \return True if the map has Orange Tree
        bool hasOrangeTree(void);

        /// \return True if the map has White Tree
        bool hasWhiteTree(void);

        /// \return True if the map has Tree
        bool hasTree(void);

        ////////////////////////////////////////

        /// \return the X map value
        int getMapX(void);

        /// \return the Y map value
        int getMapY(void);

        ////////////////////////////////////////

        /// 
        sf::Sprite getChestSprite(void);
        bool thereChest(void);

        sf::Sprite getGainSprite(void);
        int getGainLife(void);
        int getGainRubis(void);

        // Function
        void generateMap(void);
        void setMapUp(void);
        void setMapDown(void);
        void setMapRight(void);
        void setMapLeft(void);

        void oprenChest(void);
        void gainIsGet(void);
};

#endif