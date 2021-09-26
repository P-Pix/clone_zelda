/**
 * @file GamePublic.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Game.hpp"

void Game::executionGame(void) {
    allDrawWindow();
    mooveMonster();
    switchMap();
    swordAttack();
    collideMonster();
    gainChest();
    if (m_Player.isInvulnerable()) {
        m_Player.frameInvulnerable();
    }
    if (m_Mob1.isInvulnerable()) {
        m_Mob1.frameInvulnerable();
    }
}

void Game::keyDown(void) {
    if (!m_Sword.getExecution()) {
        if (!previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, m_Player.getSpeed() * 1.f))) {
            m_Player.animationMoveDown();
        }
        if (!m_Player.getOrientationDown()) {
            m_Player.setOrientationDown();
        }
    }
}

void Game::keyLeft(void) {
    if (!m_Sword.getExecution()) {
        if (!previewCollide(m_Player.getPosition(), sf::Vector2f(m_Player.getSpeed() * -1.f, 0.f))) {
            m_Player.animationMoveLeft();
        }
        if (!m_Player.getOrientationLeft()) {
            m_Player.setOrientationLeft();
        }
    }
}

void Game::keyRight(void) {
    if (!m_Sword.getExecution()) {
        if (!previewCollide(m_Player.getPosition(), sf::Vector2f(m_Player.getSpeed() * 1.f, 0.f))) {
            m_Player.animationMoveRight();
        }
        if (!m_Player.getOrientationRight()) {
            m_Player.setOrientationRight();
        }
    }
}

void Game::keyUp(void) {
    if (!m_Sword.getExecution()) {
        if (!previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, m_Player.getSpeed() * -1.f))) {
            m_Player.animationMoveUp();
        }
        if (!m_Player.getOrientationUp()) {
            m_Player.setOrientationUp();
        }
    }
}

void Game::keySpace(void) {
    if (!m_Sword.getExecution()) {
        m_Sword.setOrientationUp(m_Player.getOrientationUp());
        m_Sword.setOrientationDown(m_Player.getOrientationDown());
        m_Sword.setOrientationRight(m_Player.getOrientationRight());
        m_Sword.setOrientationLeft(m_Player.getOrientationLeft());
        m_Sword.startAnimation(m_Player.getPositionSword(), m_Player.getOrientationValue());
    }
}