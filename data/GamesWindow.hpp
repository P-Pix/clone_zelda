#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Joueur.hpp"
#include "Heart.hpp"
#include "Wall.hpp"
#include "Ground.hpp"
#include "Monster.hpp"
#include "MapGenerator.hpp"
#include "Sword.hpp"

class GamesWindow
{
    public:
        
        // Constructor /Destructor
            GamesWindow();
            ~GamesWindow();
        
        // Accessor
            bool isRunning();

        // function
            void limitFramerate(int frame);
            void controlWindow();
            void updateWindow();
            void tchecWindow();
    
    private:

        //Variable
            // basic
                const int   m_windowwidth = 1088,
                            m_windowheight = 704;
                
                const char  *m_blocname = "skin/bloc.png",
                            *m_cavernname = "skin/cavern.png";

            // SFML            
                sf::RenderWindow    *m_Window;
                sf::Event   m_Event;
                sf::VideoMode   m_VideoMode;

            // class
                Joueur  m_Player;

                Heart   m_Heart;

                Monster m_Mob1;

                Wall    m_Tree,
                        m_Bloc;

                Ground  m_Ground, 
                        m_Cavern;
                
                MapGenerator m_Map;

                Sword m_Sword;


        //Function
            // Map
                void setMapUpdate(); 
                void switchMap();
                void loadNewMap();
                void setBackground();

            // control
                void pollEvent();

            // draw
                void drawSword();
                void drawElement(sf::Sprite sprite);
                void drawVector(std::vector<sf::Sprite> vector);
                void allDrawWindow();
            
            // modification
                void modifiHeart();
                void modifMonster();

            // collide
                bool collideUser(sf::Sprite sprite);
                void collidePosition(sf::Sprite sprite1, sf::Sprite sprite2);
                bool collideSword(sf::Sprite sprite);
};

#endif