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
            // iostream
                const int   m_WindowWidth = 1088,
                            m_WindowHeight = 704;
                
                const char  *m_bloc = "skin/bloc.png",
                            *m_cavern = "skin/cavern.png";

            // SFML            
                sf::RenderWindow    *m_Window;
                sf::Event   event;
                sf::VideoMode   m_VideoMode;

            // class
                Joueur  m_Player;

                Heart   m_Heart;

                Monster m_M, 
                        m_M2, 
                        m_M3;

                Wall    m_Tree,
                        m_Bloc;

                Ground  m_Ground, 
                        m_Cavern;
                
                MapGenerator m_Map;

                Sword m_Sword;


        //Function
            void drawSword();
            void setMapUpdate(); 
            void switchMap();
            void loadNewMap();
            void setBackground();
            void drawElement(sf::Sprite SPRITE);
            void pollEvent();
            void drawVector(std::vector<sf::Sprite> vector);
            void modifiHeart();
            void allDrawWindow();
};

#endif