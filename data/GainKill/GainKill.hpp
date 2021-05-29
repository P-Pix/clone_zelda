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
#include <cstdlib>

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
            bool thereGain();

        // Chose element gain
            void choseGain(sf::Vector2f);
            void isGet();

    private:
        // Variable
            bool    m_gain = false;

            const char  *m_heartname = "skin/heartgain.png",
                        *m_bluerubisname = "skin/bluerubis.png",
                        *m_greenrubisname = "skin/greenrubis.png",
                        *m_redrubisname = "skin/redrubis.png",
                        *m_emptyname = "skin/empty.png";
            
            int m_valorgainrubis = 0,
                m_valorgainlife = 0;
                
            sf::Texture m_Texture;

            sf::Sprite m_Sprite;

        // Function
            void loadSprite(const char *name_image);
            void loadTexture(const char *name_image);
            void setPostionSprite(sf::Vector2f);
};

#endif