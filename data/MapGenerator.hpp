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

    private:
        // Variables 
            // iostream
                int m_x = 1,
                    m_y = 1;

                std::string *m_string;
                std::fstream    *m_map;

            // SFML
                std::vector<sf::Vector2f>   m_WallExt,
                                            m_WallInt,
                                            m_GroundInt,
                                            m_GroundExt;
        
        // Function
            void openMap();
};

#endif