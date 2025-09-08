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

#include "../../include/JoueurLegacy.hpp"

sf::Sprite Joueur::getLogoRubis(void) {
    return m_Rubis.getLogoRubis();
}

sf::Text Joueur::getRubisHundred(void) {
    return m_Rubis.getRubisHundred();
}

sf::Text Joueur::getRubisTen(void) {
    return m_Rubis.getRubisTen();
}

sf::Text Joueur::getRubisUnit(void) {
    return m_Rubis.getRubisUnit();
}

int Joueur::getTotalRubis(void) {
    return m_Rubis.getTotalRubis();
}