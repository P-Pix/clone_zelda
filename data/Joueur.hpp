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
            Joueur* getAdress();
            int getLife();
            int getMaxLife();
        
        // Function
            void setMaxLifeUp();
            void setHeart();
            void setDamage(int power);
            void animationMoveDown();
            void animationMoveUp();
            void animationMoveLeft();
            void animationMoveRight();
        
    private:
        // Varible
            // iostream / Standar
                const char  *m_NCF0 = "skin/heros10.png",
                            *m_NCF1 = "skin/heros11.png",
                            *m_NCF2 = "skin/heros12.png",
                            *m_NCF3 = "skin/heros13.png",
                            *m_NCF4 = "skin/heros14.png",
                            *m_NCF5 = "skin/heros15.png",
                            *m_NCF6 = "skin/heros16.png",
                            *m_NCF7 = "skin/heros17.png";
                
                int m_MoveDown = 0,
                    m_MoveUp = 0,
                    m_MoveLeft = 0,
                    m_MoveRight = 0,
                    m_Vitesse = 10,
                    m_MaxLife = 12,
                    m_Life = 12;

            // SFML/Graphics
                sf::Texture m_Thero;
                sf::Sprite  m_Shero;
                sf::Vector2f    m_Spown;

        //Function
            sf::Sprite loadSprite(const char *NAME, sf::Vector2f VECTOR);
            void loadTexture(const char *NAME);
};

#endif