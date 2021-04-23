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
            sf::Sprite sprite();
        
        // Function
            void animationMoveDown();
            void animationMoveUp();
            void animationMoveLeft();
            void animationMoveRight();
        
    private:
        // Varible
            // iostream
                const char 
                    *m_NCF1 = "skin/heros11.png",
                    *m_NCF2 = "skin/heros12.png",
                    *m_NCF3 = "skin/heros13.png",
                    *m_NCF4 = "skin/heros14.png";
                
                int 
                    m_MoveDown = 0,
                    m_MoveUp = 0,
                    m_MoveLeft = 0,
                    m_MoveRight = 0;

            // SFML/Graphics
                sf::Texture m_Thero;
                sf::Sprite m_Shero;
                sf::Vector2f m_Spown;

        //Function
        sf::Sprite loadSprite(const char *NAME, sf::Vector2f VECTOR);
        void loadTexture(const char *NAME);
            


};

#endif