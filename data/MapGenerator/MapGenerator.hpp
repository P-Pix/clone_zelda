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

#include "../Chest/Chest.hpp"

class MapGenerator
{
    public:
        // Constructor / Destructor
            MapGenerator();
            ~MapGenerator();
        
        // Accessor
            std::vector<sf::Vector2f> getListPositionWallExt();
            std::vector<sf::Vector2f> getListPositionGroundExt();

            std::vector<sf::Vector2f> getListPositionWallInt();
            std::vector<sf::Vector2f> getListPositionGroundInt();

            std::vector<std::vector<char>> getMap();
        
            bool hasTree();
            bool hasGround();
            bool hasCavern();
            bool hasBloc();

            int getMapX();
            int getMapY();

            sf::Sprite getChestSprite();
            bool thereChest();

            sf::Sprite getGainSprite();
            int getGainLife();
            int getGainRubis();
            
        // Function
            void generateMap();
            void setMapUp();
            void setMapDown();
            void setMapRight();
            void setMapLeft();

            void oprenChest();
            void gainIsGet();


    private:
        // Variables 
            // basic
                int m_x = 7,
                    m_y = 8;
                
                bool    m_tree = false,
                        m_cavern = false,
                        m_bloc = false,
                        m_ground = false;

            // std
                std::vector<sf::Vector2f>   m_WallExt,
                                            m_WallInt,
                                            m_GroundInt,
                                            m_GroundExt;

                std::vector<std::vector<char>> m_map;
        
                std::string *m_String;
                std::fstream    *m_Fmap;

            // class
                Chest m_Chest;

        // Function
};

#endif