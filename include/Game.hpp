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
        ////////////////////////////////////////

            /// Picture's adress for sprite
            const char  *m_blocname         = "image/bloc.png",
                        *m_cavernname       = "image/cavern.png",
                        *m_orangetreename   = "image/orangetree.png",
                        *m_whitetreename    = "image/whitetree.png",
                        *m_bridgename       = "image/bridge.png",
                        *m_greygroundname   = "image/greyground.png",
                        *m_watername        = "image/water.png",
                        *m_groundname       = "image/ground.png",

                        *m_fontname         = "font/SuperLegendBoy.ttf";
            
            /// Orientation of the collide
            bool    m_collidedown   = false,
                    m_collideup     = false,
                    m_collideright  = false,
                    m_collideleft   = false;

            /// Vector sprite for draw in the window
            std::vector<sf::Sprite> m_vectorsprite;

            /// Vector text for draw in the window
            std::vector<sf::Text> m_vectortext;

            /// Vector monster for all monster test
            std::vector<Monster> m_listmob;

        ////////////////////////////////////////

            /// Class Joueur
            Joueur  m_Player;

            /// Class Monster
            Monster m_Mob1;

            /// Class Wall
            Wall    m_Tree,
                    m_OrangeTree,
                    m_WhiteTree,
                    m_Water,
                    m_Bloc;

            /// Class Ground 
            Ground  m_Ground,
                    m_GreyGround,
                    m_Bridge,
                    m_Cavern;

            /// Class MapGenerator
            MapGenerator m_Map;

            /// Class Sword
            Sword m_Sword;
        
        ////////////////////////////////////////
            
            ////////////////////////////////////////

            /// Call all function for create a new map
            void setMapUpdate(void);

            /// Check if the player is in the limit of the map and where
            void switchMap(void);

            /// Combine the list of vector2 with their sprite
            void setBackground(void);

            /// 
            void gainChest(void);

            ////////////////////////////////////////
            
            /// Check if two sprite are in contact
            /// \param sprite1 First sprite
            /// \param sprite2 Second sprite
            /// \return True if the two sprite are in contact
            bool collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2);

            /// Chec if the player's sword is in conctact with the target
            /// \param target the sprite in contact with the sword
            /// \return True if the sprite is in constact with the sword
            bool collideSword(sf::Vector2f target);

            /// Check if the sprite is in contact with a list of sprite
            /// \param user The sprite Checked
            /// \param wall List of sprite
            /// \return True if the sprite is in constact with at least one
            bool collideWall(sf::Vector2f user, std::vector<sf::Vector2f> wall);
            
            /// Check if the next move is possible
            /// \param user The sprite who will move
            /// \param moove His deplacement
            /// \return True if he can't move
            bool previewCollide(sf::Vector2f user, sf::Vector2f moove);
            
            /// Check if the sprite will go out the map
            /// \param user The sprite Check
            /// \param moove His deplacement
            /// \return True if he go out the map
            bool previewLimitMap(sf::Vector2f user, sf::Vector2f moove);

            /// 
            void collideMonster(void);
            
            /// Check where the the sprite if in contact
            /// \param sprite1 The sprite who suffered the contact
            /// \param sprite2 The sprite who afflict the contact
            void collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2);
            
            ////////////////////////////////////////
            
            /// Check for all Monster if they are in contact with the Sword
            void swordAttack(void);

            /// Afflict damage at the mob in conatct with the sword
            /// \param mob position in the vector
            void monsterReceveAttack(unsigned int mob);

            ////////////////////////////////////////
            
            /// Move and check if the mob can move
            void mooveMonster(void);

            /// Make the list of the mob
            void makeListMonster(void);
            
            ////////////////////////////////////////
            
            /// Continue the animation of the Sword and add it in the list Sprite
            void drawSword(void);

            ///
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