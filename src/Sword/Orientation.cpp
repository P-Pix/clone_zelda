/**
 * @file SwordPublicOrientation.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Sword.hpp"

void Sword::setOrientationDown(bool playerdown) {
    m_animationdown = playerdown;
}

void Sword::setOrientationLeft(bool playerleft) {
    m_animationleft = playerleft;
}

void Sword::setOrientationRight(bool playerright) {
    m_animationright = playerright;
}

void Sword::setOrientationUp(bool playerup) {
    m_animationup = playerup;
}