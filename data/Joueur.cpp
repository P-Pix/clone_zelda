#include "Joueur.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "opening.cpp"

Joueur::Joueur()
{
    this -> m_Shero = Loader::loadSprite(m_NCF1, m_Spown, m_Thero);
    std::cout << "perso create " << this << std::endl;
}

Joueur::~Joueur()
{
    std::cout << "perso delete " << this << std::endl;
}