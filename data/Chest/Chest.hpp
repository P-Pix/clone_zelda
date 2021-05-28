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

#include "../GainKill/GainKill.hpp"

class Chest
{
    public:
        // Constructor / Destructor
            Chest();
            ~Chest();
        
        // Accessor
            sf::Sprite getSprite();
            bool getChest();
            int getValorRubis();
            int getValorLife();
            sf::Sprite getSpriteGain();
        
        // Function
            void generateChest();
            void openChest();

    private:
        // Variable
            const char  *m_namechestclose = "skin/chestclose.png",
                        *m_namechestopen = "skin/chestopen.png";
            
            bool    m_spawnchest = false;
            
            sf::Sprite m_Sprite;
            sf::Texture m_Texture;

            GainKill m_Gain;
        
        // Function
            void loadSprite(const char *name);
};

#endif