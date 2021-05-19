/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Heart.hpp"

std::vector<sf::Sprite> Heart::getListSprite()
{
    return m_List;
}
sf::Sprite Heart::getSprite(int number)
{
    return m_List[number];
}