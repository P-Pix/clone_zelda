#if !defined(__JOUEUR__)
#define __JOUEUR__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Loader.hpp"

class Joueur
{
    public:
        // Constructor / Destructor
            Joueur();
            ~Joueur();
        
    private:
        // Varible
            // iostream
                const char 
                    *m_NCF1 = "../skin/heros11.png",
                    *m_NCF2 = "../skin/heros12.png",
                    *m_NCF3 = "../skin/heros13.png",
                    *m_NCF4 = "../skin/heros14.png";

            //SFML
                sf::Texture *m_Thero;
                sf::Sprite m_Shero;
                sf::Vector2f m_Spown;

        //Function
            


};

#endif