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

#ifndef _GAINKILL_HPP_
#define _GAINKILL_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>

class Gain
{
    public:
        // Constructor / Destructor
            Gain(void);
            ~Gain(void);
        
        // Accessor
            sf::Sprite getSpriteGain(void);
            int getValorGainLife(void);
            int getValorGainRubis(void);
            bool thereGain(void);

        // Chose element gain
            void choseGain(sf::Vector2f positionmonster);
            void isGet(void);

    private:
        // Variable
            bool    m_gain = false;

            const char  *m_heartname = "image/heartgain.png",
                        *m_bluerubisname = "image/bluerubis.png",
                        *m_greenrubisname = "image/greenrubis.png",
                        *m_redrubisname = "image/redrubis.png",
                        *m_emptyname = "image/empty.png";
            
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