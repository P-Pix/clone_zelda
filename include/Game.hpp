/**
 * @file Game.hpp
 * @author Guiallaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__GAME__)
#define __GAME__

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "Joueur.hpp"
#include "Wall.hpp"
#include "Ground.hpp"
#include "Monster.hpp"
#include "MapGenerator.hpp"
#include "Sword.hpp"

class Game
{
    private:
        // Variable
            const char  *m_blocname         = "skin/bloc.png",
                        *m_cavernname       = "skin/cavern.png",
                        *m_orangetreename   = "skin/orangetree.png",
                        *m_whitetreename    = "skin/whitetree.png",
                        *m_bridgename       = "skin/bridge.png",
                        *m_greygroundname   = "skin/greyground.png",
                        *m_watername        = "skin/water.png",
                        *m_groundname       = "skin/ground.png",

                        *m_fontname         = "font/SuperLegendBoy.ttf";


            bool    m_collidedown   = false,
                    m_collideup     = false,
                    m_collideright  = false,
                    m_collideleft   = false;

            std::vector<sf::Sprite> m_vectorsprite;
            std::vector<sf::Text> m_vectortext;

            std::vector<Monster*> m_listmob;

        // Class
            Joueur  m_Player;

            Monster m_Mob1;

            Wall    m_Tree,
                    m_OrangeTree,
                    m_WhiteTree,
                    m_Water,
                    m_Bloc;

            Ground  m_Ground,
                    m_GreyGround,
                    m_Bridge,
                    m_Cavern;

            MapGenerator m_Map;

            Sword m_Sword;
        
        // Function
            // Map
                void setMapUpdate(void);
                void switchMap(void);
                void loadNewMap(void);
                void setBackground(void);
                void gainChest(void);

            ////////////////////////////////////
            
            /// Chek if two sprite are in contact
            /// \param sprite1 First sprite
            /// \param sprite2 Second sprite
            /// \return True if the two sprite are in contact
            bool collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2);

            /// Chec if the player's sword is in conctact with the target
            /// \param target the sprite in contact with the sword
            /// \return True if the sprite is in constact with the sword
            bool collideSword(sf::Vector2f target);

            /// Chek if the sprite is in contact with a list of sprite
            /// \param user The sprite cheked
            /// \param wall List of sprite
            /// \return True if the sprite is in constact with at least one
            bool collideWall(sf::Vector2f user, std::vector<sf::Vector2f> wall);
                bool previewCollide(sf::Vector2f user, sf::Vector2f moove);
                bool previewLimitMap(sf::Vector2f user, sf::Vector2f moove);

                void collideMonster(void);
                void collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2);
            
            // Sword
                void swordAttack(void);

            // Monster
                void mooveMonster(void);
                void makeListMonster(void);
            
            // Draw
                void drawSword(void);
                void drawRubis(void);
                void drawMap(void);
                void drawChestGain(void);
                void drawChest(void);
                void allDrawWindow(void);

                void extractSpriteFromVector(std::vector<sf::Sprite> vector);

    public:
        // Constructor / Destructor
            Game(void);
            ~Game(void);
        
        // Accessor
            std::vector<sf::Sprite> getDrawingSprite(void) const;
            std::vector<sf::Text> getDrawingText(void) const;

            bool playerIsAlive(void);
        
        // Function
            void executionGame(void);
            
            void keyDown(void);
            void keyLeft(void);
            void keyRight(void);
            void keyUp(void);
            void keySpace(void);
};

#endif