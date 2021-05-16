#if !defined(__MAPGENERATOR__)
#define __MAPGENERATOR__

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

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
        
        // Function
            void generateMap();
            void setMapUp();
            void setMapDown();
            void setMapRight();
            void setMapLeft();

            bool hasTree();
            bool hasGround();
            bool hasCavern();
            bool hasBloc();

    private:
        // Variables 
            // basic
                int m_x = 1,
                    m_y = 1;
                
                bool    m_tree = false,
                        m_cavern = false,
                        m_bloc = false,
                        m_ground = false;

            // std
                std::vector<sf::Vector2f>   m_WallExt,
                                            m_WallInt,
                                            m_GroundInt,
                                            m_GroundExt;
        
                std::string *m_String;
                std::fstream    *m_Fmap;

        // Function
};

#endif