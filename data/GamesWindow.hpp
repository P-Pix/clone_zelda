#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Joueur.hpp"
#include "Heart.hpp"
#include "Wall.hpp"
#include "Ground.hpp"
#include "Monster.hpp"

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
            void renderWindow();
            void setDrawing(sf::Sprite SPRITE);
    
    private:

        //Variable
            // iostream
                const int   m_WindowWidth = 1088,
                            m_WindowHeight = 704;
                
                const char  *m_Bloc = "skin/bloc.png",
                            *m_Cavern = "skin/cavern.png";

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

                Wall    m_tree,
                        m_bloc;

                Ground  m_ground, 
                        m_cavern; 


        //Function
            void setPosition();
            void drawElement(sf::Sprite SPRITE);
            void pollEvent();
            void drawLife();
            void modifiHeart();
            void allDrawWindow();
};

#endif