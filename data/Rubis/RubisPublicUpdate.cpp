/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Rubis.hpp"

void Rubis::updateRubis(int valorrubis)
{
    m_totalrubis += valorrubis;
    m_unitrubis += valorrubis;
    while(m_unitrubis >= 10)
    {
        m_unitrubis -= 10;
        m_tenrubis ++;
    }
    while(m_tenrubis >= 10)
    {
        m_tenrubis -= 10;
        m_hunderedrubis ++;
    }
    if(m_totalrubis >= 900)
    {
        m_hunderedrubis = 9;
        if(m_totalrubis >= 990)
        {
            m_tenrubis = 9;
            if(m_totalrubis >= 999)
            {
                m_unitrubis = 9;
                m_totalrubis = 999;
            }
        }
    }
    changeText100();
    changeText10();
    changeText1();
}