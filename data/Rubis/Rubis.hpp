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

class Rubis
{
    public:
        // Constructor / Destructor
            Rubis();
            ~Rubis();
        
        // Accessor
            sf::Sprite getLogoRubis();
            int getRubisHundred();
            int getRubisTen();
            int getRubisUnit();
        
        // Function
            void updateRubis(int valorrubis);

    private:
        // Variable
            unsigned short  m_hunderedrubis = 0,
                            m_tenrubis = 0,
                            m_unitrubis = 0;
            
            unsigned int    m_totalrubis = 0;

            const char *m_nameimage = "skin/greenrubis.png";

            sf::Sprite m_Sprite;
            sf::Texture m_Texture;
};

#endif