/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__CHEST__)
#define __CHEST__

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Chest
{
    public:
        // Constructor / Destructor
            Chest();
            ~Chest();
        
        // Accessor
            sf::Sprite getSprite();

    private:
        // Variable
            const char  *m_namechestclose = "skin/chestclose.png",
                        *m_namechestopen = "skin/chestopen.png";
            
            sf::Sprite m_Sprite;
            sf::Texture m_Texture;
        
        // Function
};

#endif