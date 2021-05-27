/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Rubis.hpp"

sf::Sprite Rubis::getLogoRubis()
{
    return m_Sprite;
}
sf::Text Rubis::getRubisHundred()
{
    return m_Text100;
}
sf::Text Rubis::getRubisTen()
{
    return m_Text10;
}
sf::Text Rubis::getRubisUnit()
{
    return m_Text1;
}
int Rubis::getTotalRubis()
{
    return m_totalrubis;
}