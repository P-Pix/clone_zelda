/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__RUBIS__)
#define __RUBIS__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Rubis
{
    public:
        // Constructor / Destructor
            Rubis();
            ~Rubis();
        
        // Accessor
            sf::Sprite getLogoRubis();
            sf::Text getRubisHundred();
            sf::Text getRubisTen();
            sf::Text getRubisUnit();

            int getTotalRubis();
        
        // Function
            void updateRubis(int valorrubis);

    private:
        // Variable
            unsigned short  m_hunderedrubis = 0,
                            m_tenrubis = 0,
                            m_unitrubis = 0;
            
            unsigned int    m_totalrubis = 0;

            const char  *m_nameimage = "skin/greenrubis.png",
                        *m_namefont = "font/SuperLegendBoy.ttf";

            sf::Sprite m_Sprite;
            sf::Texture m_Texture;
            sf::Font m_Font;
            sf::Text    m_Text100,
                        m_Text10,
                        m_Text1;
        // Function
            void generateText();

            void changeText100();
            void changeText10();
            void changeText1();
};

#endif