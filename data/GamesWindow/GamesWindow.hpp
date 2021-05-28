/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "../Joueur/Joueur.hpp"
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
                bool    m_collidedown   = false,
                        m_collideup     = false,
                        m_collideright  = false,
                        m_collideleft   = false;

                const int   m_windowwidth   = 1088,
                            m_windowheight  = 704;

                const char  *m_blocname     = "skin/bloc.png",
                            *m_cavernname   = "skin/cavern.png",
                            *m_fontname     = "font/SuperLegendBoy.ttf";
            
            // std
                std::vector<Monster> m_listmob;

            // SFML
                sf::RenderWindow    *m_Window;
                sf::Event   m_Event;
                sf::VideoMode   m_VideoMode;

            // class
                Joueur  m_Player;

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
                void gainChest();

            // control
                void pollEvent();
                void swordAttack();

            // draw
                void drawSword();
                void drawSprite(sf::Sprite sprite);
                void drawText(sf::Text Text);
                void drawVector(std::vector<sf::Sprite> vector);
                void drawRubis();
                void drawMap();
                void drawChestGain();
                void drawChest();
                void allDrawWindow();

            // modification
                void mooveMonster();
                void makeListMonster();

            // collide
                bool collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2);
                void collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2);
                bool collideSword(sf::Vector2f sprite);
                bool collideWall(sf::Vector2f user, std::vector<sf::Vector2f> wall);
                void collideMonster();
                bool previewCollide(sf::Vector2f user, sf::Vector2f moove);
};

#endif