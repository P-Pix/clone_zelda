/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Ground.hpp"

// Sprite
    std::vector<sf::Sprite> Ground::getListSprite()
    {
        return m_ListeSprite;
    }
    sf::Sprite Ground::getSprite()
    {
        return m_Sprite;
    }

// Adress
    Ground* Ground::getAdress()
    {
        return this;
    }