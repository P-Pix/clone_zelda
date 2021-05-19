/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Ground.hpp"

void Ground::setPosition(sf::Vector2f position)
{
    this -> m_Sprite.setPosition(position);
}
void Ground::setPositionVector(std::vector<sf::Vector2f> vector)
{
    int size = 0;
    this -> m_ListeSprite.clear();

    for(size = 0; size < vector.size(); size ++)
    {
        setPosition(vector[size]);
        m_ListeSprite.push_back(getSprite());
    }
}