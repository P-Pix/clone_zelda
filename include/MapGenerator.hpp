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

#if !defined(__MAPGENERATOR__)
#define __MAPGENERATOR__

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Chest.hpp"

class MapGenerator
    {
    private:
        int m_x = 7,
            m_y = 8;

        bool    m_booltree          = false,
                m_boolwall          = false,
                m_boolorangetree    = false,
                m_boolwater         = false,
                m_boolwhitetree     = false,

                m_boolbridge        = false,
                m_boolslad          = false,
                m_booldust          = false;

        // std
        std::vector<sf::Vector2f> 
            m_Tree,
            m_OrangeTree,
            m_WhiteTree,
            m_Water,
            m_Wall,

            m_Bridge,
            m_Dust,
            m_Slad;

        std::vector<std::vector<char>> 
            m_map;

        std::string *m_String;
        std::fstream *m_Fmap;

        // class
        Chest m_Chest;

    public:
        ////////////////////////////////////////

        /// add the position the Dust list
        /// \param position x and y coord
        void addDust(sf::Vector2f position);

        /// add the position the Slad list
        /// \param position x and y coord
        void addSlad(sf::Vector2f position);

        /// add the position the Bridge list
        /// \param position x and y coord
        void addBridge(sf::Vector2f position);

        ////////////////////////////////////////

        /// add the position the Wall list
        /// \param position x and y coord
        void addWall(sf::Vector2f position);

        /// add the position the Water list
        /// \param position x and y coord
        void addWater(sf::Vector2f position);

        /// add the position the Orange Tree list
        /// \param position x and y coord
        void addOrangeTree(sf::Vector2f position);

        /// add the position the White Tree list
        /// \param position x and y coord
        void addWhiteTree(sf::Vector2f position);

        /// add the position the Tree list
        /// \param position x and y coord
        void addTree(sf::Vector2f position);
    
    private:
        ////////////////////////////////////////

        /// function pointer
        void *(*ptr[8])(sf::Vector2f position);

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

        /// \return map matrix 
        std::vector<std::vector<char>> getMap(void);

        ////////////////////////////////////////

        /// \return True if the map has Dust
        bool hasDust(void);

        /// \return True if the map has Sald
        bool hasSlad(void);

        /// \return True if the map has Bridge
        bool hasBridge(void);

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