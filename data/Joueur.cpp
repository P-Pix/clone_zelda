#include "Joueur.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

Joueur::Joueur()
{
    this -> m_Shero = loadSprite(m_NCF1, m_Spown);
    std::cout << "perso create " << this << m_NCF1 << std::endl;
}

Joueur::~Joueur()
{
    std::cout << "perso delete " << this << std::endl;
}

// Accessor

sf::Sprite Joueur::sprite()
{
    return m_Shero;
}

// Fonction Private

sf::Sprite Joueur::loadSprite(const char *NAME, sf::Vector2f VECTOR)
{
    sf::Sprite SPRITE;
    loadTexture(NAME);
    SPRITE.setTexture(m_Thero);
    SPRITE.setPosition(VECTOR);
    return SPRITE;
}

void Joueur::loadTexture(const char *NAME)
{
    if(!m_Thero.loadFromFile(NAME))
    {
        std::cout << "error image " << NAME << std::endl;
    }
}