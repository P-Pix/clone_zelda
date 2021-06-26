/**
 * @file Rubis.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _RUBIS_HPP_
#define _RUBIS_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Rubis
{
    public:
        // Constructor / Destructor
            Rubis(void);
            ~Rubis(void);
        
        // Accessor
            sf::Sprite getLogoRubis(void);
            sf::Text getRubisHundred(void);
            sf::Text getRubisTen(void);
            sf::Text getRubisUnit(void);

            int getTotalRubis(void);
        
        // Function
            void updateRubis(int valorrubis);

    private:
        // Variable
            unsigned short  m_hunderedrubis = 0,
                            m_tenrubis = 0,
                            m_unitrubis = 0;
            
            unsigned int    m_totalrubis = 0;

            const char  *m_nameimage = "image/greenrubis.png",
                        *m_namefont = "font/SuperLegendBoy.ttf";

            sf::Sprite m_Sprite;
            sf::Texture m_Texture;
            sf::Font m_Font;
            sf::Text    m_Text100,
                        m_Text10,
                        m_Text1;
        // Function
            void generateText(void);

            void changeText100(void);
            void changeText10(void);
            void changeText1(void);
};

#endif