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

#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "Heart.hpp"
#include "Rubis.hpp"
class Joueur
{
    private:
        // Varible
            // iostream / Standar
                const char  *m_ncf0 = "image/heros10.png",
                            *m_ncf1 = "image/heros11.png",
                            *m_ncf2 = "image/heros12.png",
                            *m_ncf3 = "image/heros13.png",
                            *m_ncf4 = "image/heros14.png",
                            *m_ncf5 = "image/heros15.png",
                            *m_ncf6 = "image/heros16.png",
                            *m_ncf7 = "image/heros17.png";
                
                int m_movedown = 0,
                    m_moveup = 0,
                    m_moveleft = 0,
                    m_moveright = 0,
                    m_vitesse = 5;
                
                bool    m_orientationright = false,
                        m_orientationup = false,
                        m_orientationleft = false,
                        m_orientationdown = false;

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

            void moveUp(void);
            void moveDown(void);
            void moveRight(void);
            void moveLeft(void);

            void makeListeAnimation(void);
            void moveAniamtion(int frame, std::vector<const char * > liste);
            
    public:
        // Constructor / Destructor
            Joueur(void);
            ~Joueur(void);
        
        // Accessor 
            sf::Sprite getSprite(void);
            sf::Vector2f getPosition(void);
            sf::Vector2f getPositionSword(void);

            Joueur* getAdress(void);

            int getLife(void);
            int getMaxLife(void);
            bool isAlive(void);
            bool isInvulnerable(void);

            int getSpeed(void);

            bool getOrientationUp(void);
            bool getOrientationDown(void);
            bool getOrientationLeft(void);
            bool getOrientationRight(void);
            int getOrientationValue(void);
            
            // Heart
                std::vector<sf::Sprite> getListSpriteHeart(void);
                sf::Sprite getSpriteHeart(int number);

            // Rubis
                sf::Sprite getLogoRubis(void);
                sf::Text getRubisHundred(void);
                sf::Text getRubisTen(void);
                sf::Text getRubisUnit(void);
                int getTotalRubis(void);
        
        // Function
            void setOrientationUp(void);
            void setOrientationDown(void);
            void setOrientationRight(void);
            void setOrientationLeft(void);

            void setMaxLifeUp(void);
            void setHeart(int life);
            void setDamage(int power);
            void frameInvulnerable(void);
            
            void setPositionUp(void);
            void setPositionDown(void);
            void setPositionLeft(void);
            void setPositionRight(void);

            void animationMoveDown(void);
            void animationMoveUp(void);
            void animationMoveLeft(void);
            void animationMoveRight(void);

            void recoilDown(void);
            void recoilUp(void);
            void recoilRight(void);
            void recoilLeft(void);

            void updateRubis(int valor);
};

#endif