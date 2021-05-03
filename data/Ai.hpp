#if !defined(__AI__)
#define __AI__

#include <SFML/Graphics.hpp>
#include <vector>

class Ai
{
    public:
        // Constructor / Destructor
            // Constructor
                Ai();
                Ai(sf::Vector2f positionuser, sf::Vector2f positiontarget);

            // Destructor
                ~Ai();
        
        // Accessor
            sf::Vector2f getMove(); //receve the first element to std::vector<sf::Sprite>

        // Function

    private:
        // Variable
            // basic
                int m_xtarget = 0,
                    m_ytarget = 0,
                    
                    m_xuser = 0,
                    m_yuser = 0,

                    m_valuecompare = 0;

            // std
                std::vector<sf::Vector2f> m_OpenList;

            // sfml
        
        // structur
            struct Noeud
            {
                int x;
                int y;
                int cout;
                int heuristique;
            };

        // class
            Noeud   m_Target,
                    m_User;

        // Function
            // A*
                void compare(Noeud noeud1, Noeud noeud2);
                void aStarExe();
            
            // Djikstra
            void djikstraMin(std::vector<Noeud> road);
            void djikstraInit(std::vector<Noeud> listenoeud);
            void djikstraExe();
            void djikstraUpdate();
};

#endif