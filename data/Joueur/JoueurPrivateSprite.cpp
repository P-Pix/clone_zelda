/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

sf::Sprite Joueur::loadSprite(const char *name, sf::Vector2f vector)
{
    sf::Sprite sprite;
    loadTexture(name);
    sprite.setTexture(m_Thero);
    sprite.setPosition(vector);
    sprite.setScale(2, 2);
    return sprite;
}
void Joueur::loadTexture(const char *name)
{
    if(!m_Thero.loadFromFile(name))
    {
        std::cout << "error image " << name << std::endl;
    }
}