#include "Joueur.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

Joueur::Joueur()
{
    this -> m_Shero = loadSprite(m_NCF1, m_Spown);
    std::cout << "player create " << this << std::endl;
}

Joueur::~Joueur()
{
    std::cout << "player delete " << this << std::endl;
}

// Accessor

sf::Sprite Joueur::getSprite()
{
    return m_Shero;
}

Joueur *Joueur::getAdress()
{
    return this;
}

int Joueur::getLife()
{
    return m_Life;
}

int Joueur::getMaxLife()
{
    return m_MaxLife;
}

// Function public

void Joueur::setDamage(int power)
{
    m_Life -= power;
}

void Joueur::animationMoveRight()
{
    if(m_MoveRight % 4 == 0)
    {
        loadTexture(m_NCF1);
    }
    else if(m_MoveRight % 4 == 1)
    {
        loadTexture(m_NCF2);
    }
    else if(m_MoveRight % 4 == 2)
    {
        loadTexture(m_NCF3);
    }
    else
    {
        loadTexture(m_NCF4);
    }
    m_MoveRight ++;
    this -> m_Shero.move(sf::Vector2f(m_Vitesse * 1.f, 0.f));
}

void Joueur::animationMoveLeft()
{
    if(m_MoveLeft % 4 == 0)
    {
        loadTexture(m_NCF1);
    }
    else if(m_MoveLeft % 4 == 1)
    {
        loadTexture(m_NCF2);
    }
    else if(m_MoveLeft % 4 == 2)
    {
        loadTexture(m_NCF3);
    }
    else
    {
        loadTexture(m_NCF4);
    }
    m_MoveLeft ++;
    this -> m_Shero.move(sf::Vector2f(m_Vitesse * -1.f, 0.f));
}

void Joueur::animationMoveUp()
{
    if(m_MoveUp % 4 == 0)
    {
        loadTexture(m_NCF1);
    }
    else if(m_MoveUp % 4 == 1)
    {
        loadTexture(m_NCF2);
    }
    else if(m_MoveUp % 4 == 2)
    {
        loadTexture(m_NCF3);
    }
    else
    {
        loadTexture(m_NCF4);
    }
    m_MoveUp ++;
    this -> m_Shero.move(sf::Vector2f(0.f, m_Vitesse * -1.f));
}

void Joueur::animationMoveDown()
{
    if(m_MoveDown % 8 == 0)
    {
        loadTexture(m_NCF0);
        m_MoveDown = 0;
    }
    else if(m_MoveDown % 8 == 1)
    {
        loadTexture(m_NCF1);
    }
    else if(m_MoveDown % 8 == 2)
    {
        loadTexture(m_NCF2);
    }
    else if(m_MoveDown % 8 == 3)
    {
        loadTexture(m_NCF3);
    }
    else if(m_MoveDown % 8 == 4)
    {
        loadTexture(m_NCF4);
    }
    else if(m_MoveDown % 8 == 5)
    {
        loadTexture(m_NCF5);
    }
    else if(m_MoveDown % 8 == 6)
    {
        loadTexture(m_NCF6);
    }
    else
    {
        loadTexture(m_NCF7);
    }
    m_MoveDown ++;
    this -> m_Shero.move(sf::Vector2f(0.f, m_Vitesse * 1.f));
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
