/**
 * @file JoueurPublicSwitchOrientation.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Joueur.hpp"

void Joueur::setOrientationDown()
{
    m_orientationdown = true;
    m_orientationleft = false;
    m_orientationright = false;
    m_orientationup = false;
}
void Joueur::setOrientationLeft()
{
    m_orientationdown = false;
    m_orientationleft = true;
    m_orientationright = false;
    m_orientationup = false;            
}
void Joueur::setOrientationUp()
{
    m_orientationdown = false;
    m_orientationleft = false;
    m_orientationright = false;
    m_orientationup = true;            
}
void Joueur::setOrientationRight()
{
    m_orientationdown = false;
    m_orientationleft = false;
    m_orientationright = true;
    m_orientationup = false;            
}