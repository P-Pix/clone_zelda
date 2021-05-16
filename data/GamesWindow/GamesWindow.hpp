/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Joueur/Joueur.hpp"
#include "../Heart/Heart.hpp"
#include "../Wall/Wall.hpp"
#include "../Ground/Ground.hpp"
#include "../Monster/Monster.hpp"
#include "../MapGenerator/MapGenerator.hpp"
#include "../Sword/Sword.hpp"

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
            void verificationWindow();

    private:
        //Variable
            // basic
                bool    m_canmove       = true,

                        m_collidedown   = false,
                        m_collideup     = false,
                        m_collideright  = false,
                        m_collideleft   = false;

                const int   m_windowwidth   = 1088,
                            m_windowheight  = 704;

                const char  *m_blocname     = "skin/bloc.png",
                            *m_cavernname   = "skin/cavern.png";
            
            // std
                std::vector<Monster> m_listmob;

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
                void canMove();
                void swordAttack();

            // draw
                void drawSword();
                void drawElement(sf::Sprite sprite);
                void drawVector(std::vector<sf::Sprite> vector);
                void allDrawWindow();

            // modification
                void modifiHeart();
                void modifMonster();
                void makeListMonster();

            // collide
                bool collideUser(sf::Vector2f sprite);
                void collidePosition(sf::Sprite sprite1, sf::Sprite sprite2);
                bool collideSword(sf::Sprite sprite);
                bool collideWall(std::vector<sf::Vector2f> wall);
                void collideMonster();
};

#endif