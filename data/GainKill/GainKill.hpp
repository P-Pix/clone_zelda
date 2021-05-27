/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__GAINKILL__)
#define __GAINKILL__

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>

class GainKill
{
    public:
        // Constructor / Destructor
            GainKill();
            ~GainKill();
        
        // Accessor
            sf::Sprite getSpriteGain();
            int getValorGainLife();
            int getValorGainRubis();

        // Chose element gain
            void choseGain(sf::Vector2f positionmonster);

    private:
        // Variable
            const char  *m_heartname = "skin/heartgain.png",
                        *m_bluerubisname = "skin/bluerubis.png",
                        *m_greenrubisname = "skin/greenrubis.png",
                        *m_redrubisname = "skin/redrubis.png";
            
            int m_valorgainrubis = 0,
                m_valorgainlife = 0;
                
            sf::Texture m_Texture;

            sf::Sprite m_Sprite;

        // Function
            void loadSprite(const char *name);
            void loadTexture(const char *name);
            void setPostionSprite(sf::Vector2f position);
};

#endif