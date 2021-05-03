#if !defined(__JOUEUR__)
#define __JOUEUR__

#include <iostream>
#include <SFML/Graphics.hpp>

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

            bool getOrientationUp();
            bool getOrientationDown();
            bool getOrientationLeft();
            bool getOrientationRight();
            int getOrientationValue();
        
        // Function
            void setOrientationUp();
            void setOrientationDown();
            void setOrientationRight();
            void setOrientationLeft();

            void setMaxLifeUp();
            void setHeart();
            void setDamage(int power);
            
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
                    m_vitesse = 10,
                    m_maxlife = 80,
                    m_life = 69;
                
                bool    m_orientationright = false,
                        m_orientationup = false,
                        m_orientationleft = false,
                        m_orientationdown = true;

            // SFML/Graphics
                sf::Texture m_Thero;
                sf::Sprite  m_Shero;
                sf::Vector2f    m_Spown;

        //Function
            sf::Sprite loadSprite(const char *name, sf::Vector2f vector);
            void loadTexture(const char *name);
};

#endif