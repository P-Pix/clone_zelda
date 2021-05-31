/**
 * @file JoueurAccessorRubis.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Joueur.hpp"

sf::Sprite Joueur::getLogoRubis()
{
    return m_Rubis.getLogoRubis();
}
sf::Text Joueur::getRubisHundred()
{
    return m_Rubis.getRubisHundred();
}
sf::Text Joueur::getRubisTen()
{
    return m_Rubis.getRubisTen();
}
sf::Text Joueur::getRubisUnit()
{
    return m_Rubis.getRubisUnit();
}
int Joueur::getTotalRubis()
{
    return m_Rubis.getTotalRubis();
}