/**
 * @file RubisAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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