/**
 * @file JoueurPublicAnimation.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/JoueurLegacy.hpp"

void Joueur::animationMoveRight(void) {
    moveAniamtion(m_moveright, m_AnimationRight);
    if (m_moveright == 32) {
        m_moveright = 0;
    }
    m_moveright++;
    moveRight();
}

void Joueur::animationMoveLeft(void) {
    moveAniamtion(m_moveleft, m_AnimationLeft);
    if (m_moveleft == 32) {
        m_moveleft = 0;
    }
    m_moveleft++;
    moveLeft();
}

void Joueur::animationMoveUp(void) {
    moveAniamtion(m_moveup, m_AnimationUp);
    if (m_moveup == 32) {
        m_moveup = 0;
    }
    m_moveup++;
    moveUp();
}

void Joueur::animationMoveDown(void) {
    moveAniamtion(m_movedown, m_AnimationDown);
    if (m_movedown == 32) {
        m_movedown = 0;
    }
    m_movedown++;
    moveDown();
}