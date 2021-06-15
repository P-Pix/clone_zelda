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
    public:
        // Constructor / Destructor
            MapGenerator(void);
            ~MapGenerator(void);
        
        // Accessor
            std::vector<sf::Vector2f> getListPositionWallExt(void);
            std::vector<sf::Vector2f> getListPositionGroundExt(void);

            std::vector<sf::Vector2f> getListPositionWallInt(void);
            std::vector<sf::Vector2f> getListPositionGroundInt(void);

            std::vector<std::vector<char>> getMap(void);
        
            bool hasTree(void);
            bool hasGround(void);
            bool hasCavern(void);
            bool hasBloc(void);

            int getMapX(void);
            int getMapY(void);

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