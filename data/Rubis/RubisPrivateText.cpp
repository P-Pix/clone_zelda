  /**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Rubis.hpp"

void Rubis::generateText()
{    
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
void Rubis::changeText100()
{
    m_Text100.setString(std::to_string(m_hunderedrubis));
}
void Rubis::changeText10()
{
    m_Text10.setString(std::to_string(m_tenrubis));
}
void Rubis::changeText1()
{
    m_Text1.setString(std::to_string(m_unitrubis));
}