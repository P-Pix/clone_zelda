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

#include "../../include/Joueur.hpp"

bool Joueur::getOrientationDown(void)
{
    return m_orientationdown;
}
bool Joueur::getOrientationLeft(void)
{
    return m_orientationleft;
}
bool Joueur::getOrientationRight(void)
{
    return m_orientationright;
}
bool Joueur::getOrientationUp(void)
{
    return m_orientationup;
}
int Joueur::getOrientationValue(void)
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