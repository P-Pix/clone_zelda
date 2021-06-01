/**
 * @file Gain.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__GAINKILL__)
#define __GAINKILL__

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>

class Gain
{
    public:
        // Constructor / Destructor
            Gain();
            ~Gain();
        
        // Accessor
            sf::Sprite getSpriteGain();
            int getValorGainLife();
            int getValorGainRubis();
            bool thereGain();

        // Chose element gain
            void choseGain(sf::Vector2f positionmonster);
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
            void loadSprite(const char *name);
            void loadTexture(const char *name);
            void setPostionSprite(sf::Vector2f position);
};

#endif