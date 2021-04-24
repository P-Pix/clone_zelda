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
    SPRITE.setScale(2, 2);
    return SPRITE;
}

void Joueur::loadTexture(const char *NAME)
{
    if(!m_Thero.loadFromFile(NAME))
    {
        std::cout << "error image " << NAME << std::endl;
    }
}

void Joueur::animationMoveDown()
{
    if(m_MoveDown % 4 == 0)
    {
        loadTexture(m_NCF1);
    }
    else if(m_MoveDown % 4 == 1)
    {
        loadTexture(m_NCF2);
    }
    else if(m_MoveDown % 4 == 2)
    {
        loadTexture(m_NCF3);
    }
    else
    {
        loadTexture(m_NCF4);
    }
    m_MoveDown ++;
    std::cout << m_MoveDown << std::endl;
}