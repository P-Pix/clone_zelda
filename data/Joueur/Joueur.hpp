/**
 * @file Joueur.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__JOUEUR__)
#define __JOUEUR__

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "../Heart/Heart.hpp"
#include "../Rubis/Rubis.hpp"
class Joueur
{
    public:
        // Constructor / Destructor
            Joueur();
            ~Joueur();
        
        // Accessor 
            sf::Sprite getSprite();
            sf::Vector2f getPosition();
            sf::Vector2f getPositionSword();

            Joueur* getAdress();

            int getLife();
            int getMaxLife();
            bool isAlive();
            bool isInvulnerable();

            int getSpeed();

            bool getOrientationUp();
            bool getOrientationDown();
            bool getOrientationLeft();
            bool getOrientationRight();
            int getOrientationValue();
            
            // Heart
                std::vector<sf::Sprite> getListSpriteHeart();
                sf::Sprite getSpriteHeart(int number);

            // Rubis
                sf::Sprite getLogoRubis();
                sf::Text getRubisHundred();
                sf::Text getRubisTen();
                sf::Text getRubisUnit();
                int getTotalRubis();
        
        // Function
            void setOrientationUp();
            void setOrientationDown();
            void setOrientationRight();
            void setOrientationLeft();

            void setMaxLifeUp();
            void setHeart(int life);
            void setDamage(int power);
            void frameInvulnerable();
            
            void setPositionUp();
            void setPositionDown();
            void setPositionLeft();
            void setPositionRight();

            void animationMoveDown();
            void animationMoveUp();
            void animationMoveLeft();
            void animationMoveRight();

            void recoilDown();
            void recoilUp();
            void recoilRight();
            void recoilLeft();

            void updateRubis(int valor);
        
    private:
        // Varible
            // iostream / Standar
                const char  *m_ncf0 = "skin/heros10.png",
                            *m_ncf1 = "skin/heros11.png",
                            *m_ncf2 = "skin/heros12.png",
                            *m_ncf3 = "skin/heros13.png",
                            *m_ncf4 = "skin/heros14.png",
                            *m_ncf5 = "skin/heros15.png",
                            *m_ncf6 = "skin/heros16.png",
                            *m_ncf7 = "skin/heros17.png";
                
                int m_movedown = 0,
                    m_moveup = 0,
                    m_moveleft = 0,
                    m_moveright = 0,
                    m_vitesse = 5,
                    m_maxlife = 80,
                    m_life = 20,
                    m_invulnerability = 0;
                
                bool    m_orientationright = false,
                        m_orientationup = false,
                        m_orientationleft = false,
                        m_orientationdown = true,

                        m_alive = true,
                        m_invulnerable = false;
            // std
                std::vector<const char * >  m_AnimationUp,
                                            m_AnimationDown,
                                            m_AnimationRight,
                                            m_AnimationLeft;
            
            // SFML/Graphics
                sf::Texture m_Thero;
                sf::Sprite  m_Shero;
                sf::Vector2f    m_Spown;
            
            // class
                Heart m_Heart;
                Rubis m_Rubis;

        //Function
            sf::Sprite loadSprite(const char *name, sf::Vector2f vector);
            void loadTexture(const char *name);

            void moveUp();
            void moveDown();
            void moveRight();
            void moveLeft();

            void makeListeAnimation();
            void moveAniamtion(int frame, std::vector<const char * > liste);
};

#endif