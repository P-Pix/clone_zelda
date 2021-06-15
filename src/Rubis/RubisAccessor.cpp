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

#include "../../include/Rubis.hpp"

sf::Sprite Rubis::getLogoRubis(void)
{
    return m_Sprite;
}
sf::Text Rubis::getRubisHundred(void)
{
    return m_Text100;
}
sf::Text Rubis::getRubisTen(void)
{
    return m_Text10;
}
sf::Text Rubis::getRubisUnit(void)
{
    return m_Text1;
}
int Rubis::getTotalRubis(void)
{
    return m_totalrubis;
}