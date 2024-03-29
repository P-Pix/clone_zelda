/**
 * @file JoueurPublicMove.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Joueur.hpp"

void Joueur::setPositionDown(void) {
    float x = m_Shero.getPosition().x,
            y = m_Shero.getPosition().y - 704;
    m_Shero.setPosition(sf::Vector2f(x, y));
}

void Joueur::setPositionUp(void) {
    float x = m_Shero.getPosition().x,
            y = m_Shero.getPosition().y + 704;
    m_Shero.setPosition(sf::Vector2f(x, y));
}

void Joueur::setPositionRight(void) {
    float x = m_Shero.getPosition().x - 1024,
            y = m_Shero.getPosition().y;
    m_Shero.setPosition(sf::Vector2f(x, y));
}

void Joueur::setPositionLeft(void) {
    float x = m_Shero.getPosition().x + 1024,
            y = m_Shero.getPosition().y;
    m_Shero.setPosition(sf::Vector2f(x, y));
}

void Joueur::recoilDown(void) {
    m_Shero.move(sf::Vector2f(0.f, 64.f));
}

void Joueur::recoilLeft(void) {
    m_Shero.move(sf::Vector2f(-64.f, 0.f));
}

void Joueur::recoilRight(void) {
    m_Shero.move(sf::Vector2f(64.f, 0.f));
}

void Joueur::recoilUp(void) {
    m_Shero.move(sf::Vector2f(0.f, -64.f));
}

void Joueur::moveLeft(void) {
    m_Shero.move(sf::Vector2f(m_vitesse * -1.f, 0.f));
}

void Joueur::moveRight(void) {
    m_Shero.move(sf::Vector2f(m_vitesse * 1.f, 0.f));
}

void Joueur::moveUp(void) {
    m_Shero.move(sf::Vector2f(0.f, m_vitesse * -1.f));
}

void Joueur::moveDown(void) {
    m_Shero.move(sf::Vector2f(0.f, m_vitesse * 1.f));
}

void Joueur::makeListeAnimation(void) {
    // Liste aniamtion Down
    m_AnimationDown.push_back(m_ncf0);
    m_AnimationDown.push_back(m_ncf1);
    m_AnimationDown.push_back(m_ncf2);
    m_AnimationDown.push_back(m_ncf3);
    m_AnimationDown.push_back(m_ncf4);
    m_AnimationDown.push_back(m_ncf5);
    m_AnimationDown.push_back(m_ncf6);
    m_AnimationDown.push_back(m_ncf7);

    // Liste aniamtion Left
    m_AnimationLeft.push_back(m_ncf0);
    m_AnimationLeft.push_back(m_ncf1);
    m_AnimationLeft.push_back(m_ncf2);
    m_AnimationLeft.push_back(m_ncf3);
    m_AnimationLeft.push_back(m_ncf4);
    m_AnimationLeft.push_back(m_ncf5);
    m_AnimationLeft.push_back(m_ncf6);
    m_AnimationLeft.push_back(m_ncf7);

    // Liste aniamtion Right
    m_AnimationRight.push_back(m_ncf0);
    m_AnimationRight.push_back(m_ncf1);
    m_AnimationRight.push_back(m_ncf2);
    m_AnimationRight.push_back(m_ncf3);
    m_AnimationRight.push_back(m_ncf4);
    m_AnimationRight.push_back(m_ncf5);
    m_AnimationRight.push_back(m_ncf6);
    m_AnimationRight.push_back(m_ncf7);

    // Liste aniamtion Up
    m_AnimationUp.push_back(m_ncf0);
    m_AnimationUp.push_back(m_ncf1);
    m_AnimationUp.push_back(m_ncf2);
    m_AnimationUp.push_back(m_ncf3);
    m_AnimationUp.push_back(m_ncf4);
    m_AnimationUp.push_back(m_ncf5);
    m_AnimationUp.push_back(m_ncf6);
    m_AnimationUp.push_back(m_ncf7);
}

void Joueur::moveAniamtion(int frame, std::vector<const char *> liste) {
    if (frame % 32 == 0) {
        loadTexture(liste[0]);
    } else if (frame % 32 == 4) {
        loadTexture(liste[1]);
    } else if (frame % 32 == 8) {
        loadTexture(liste[2]);
    } else if (frame % 32 == 12) {
        loadTexture(liste[3]);
    } else if (frame % 32 == 16) {
        loadTexture(liste[4]);
    } else if (frame % 32 == 20) {
        loadTexture(liste[5]);
    } else if (frame % 32 == 24) {
        loadTexture(liste[6]);
    } else if (frame % 32 == 28) {
        loadTexture(liste[7]);
    }
}