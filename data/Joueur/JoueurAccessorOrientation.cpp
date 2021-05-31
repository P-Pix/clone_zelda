/**
 * @file JoueurAccessorOrientation.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Joueur.hpp"

bool Joueur::getOrientationDown()
{
    return m_orientationdown;
}
bool Joueur::getOrientationLeft()
{
    return m_orientationleft;
}
bool Joueur::getOrientationRight()
{
    return m_orientationright;
}
bool Joueur::getOrientationUp()
{
    return m_orientationup;
}
int Joueur::getOrientationValue()
{
    if(m_orientationdown)
    {
        return 90;
    }
    else if(m_orientationleft)
    {
        return 180;
    }
    else if(m_orientationright)
    {
        return 0;
    }
    else if(m_orientationup)
    {
        return 270;
    }
    return 0;
}