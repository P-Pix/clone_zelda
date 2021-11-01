/**
 * @file RubisPrivateText.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Rubis.hpp"

void Rubis::generateText(void) {
    m_Text100.setFont(m_Font);
    m_Text10.setFont(m_Font);
    m_Text1.setFont(m_Font);

    m_Text100.setString(std::to_string(m_hunderedrubis));
    m_Text10.setString(std::to_string(m_tenrubis));
    m_Text1.setString(std::to_string(m_unitrubis));

    m_Text100.setPosition(sf::Vector2f(670.f, 13.f));
    m_Text10.setPosition(sf::Vector2f(700.f, 13.f));
    m_Text1.setPosition(sf::Vector2f(730.f, 13.f));
}

void Rubis::changeText100(void) {
    m_Text100.setString(std::to_string(m_hunderedrubis));
}

void Rubis::changeText10(void) {
    m_Text10.setString(std::to_string(m_tenrubis));
}

void Rubis::changeText1(void) {
    m_Text1.setString(std::to_string(m_unitrubis));
}