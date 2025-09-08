/**
 * @file GamePrivateCollide.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Game.hpp"

void Game::collideMonster(void) {
    if (collideTwoSprite64x64(m_Player.getPosition(), m_Mob1.getPosition())) {
        if (m_Mob1.isAlive()) {
            m_Player.setDamage(m_Mob1.getPower());
            int collide = collidePosition(m_Player.getPosition(), m_Mob1.getPosition());
            if (!m_Sword.getExecution()) {
                if (collide == DOWN_COLLIDE && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, -64.f)) &&
                    !previewLimitMap(m_Player.getPosition(), sf::Vector2f(0.f, -64.f))) {
                    m_Player.recoilUp();
                } else if (collide == UP_COLLIDE && !previewCollide(m_Player.getPosition(), sf::Vector2f(0.f, 64.f)) &&
                           !previewLimitMap(m_Player.getPosition(), sf::Vector2f(0.f, 64.f))) {
                    m_Player.recoilDown();
                } else if (collide == RIGHT_COLLIDE &&
                           !previewCollide(m_Player.getPosition(), sf::Vector2f(-64.f, 0.f)) &&
                           !previewLimitMap(m_Player.getPosition(), sf::Vector2f(-64.f, 0.f))) {
                    m_Player.recoilLeft();
                } else if (collide == LEFT_COLLIDE &&
                           !previewCollide(m_Player.getPosition(), sf::Vector2f(64.f, 0.f)) &&
                           !previewLimitMap(m_Player.getPosition(), sf::Vector2f(64.f, 0.f))) {
                    m_Player.recoilRight();
                }
            }
        } else if (m_Mob1.thereGain()) {
            m_Player.setHeart(m_Mob1.getGainLifeValor());
            m_Player.updateRubis(m_Mob1.getGainRubisValor());
            m_Mob1.gainIsGet();
        }
    }
}

bool Game::collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2) {
    float sprite1x = sprite1.x,
            sprite1y = sprite1.y,

            sprite2x = sprite2.x,
            sprite2y = sprite2.y;

    return (sprite1x + 5 <= sprite2x + SPRITE_SIZE && sprite1x + 59 >= sprite2x &&
            sprite1y + 32 <= sprite2y + SPRITE_SIZE && sprite1y + SPRITE_SIZE > sprite2y);
}

int Game::collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2) {
    float sprite1x = sprite1.x,
            sprite1y = sprite1.y,

            sprite2x = sprite2.x,
            sprite2y = sprite2.y;

    if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
        sprite1y + 32 > sprite2y) {
        return UP_COLLIDE;
    } else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x + SPRITE_SIZE &&
               sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
        return LEFT_COLLIDE;
    } else if (sprite1x < sprite2x && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
               sprite1y + SPRITE_SIZE > sprite2y) {
        return RIGHT_COLLIDE;
    } else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x &&
               sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
        return DOWN_COLLIDE;
    }
    return NO_COLLIDE;
}

bool Game::collideSword(sf::Vector2f target) {
    float sprite1x = m_Sword.getPosition().x,
            sprite1y = m_Sword.getPosition().y,

            sprite2x = target.x,
            sprite2y = target.y;

    if (m_Sword.getAttackDown()) {
        return (sprite1x >= sprite2x && sprite1x - SPRITE_SIZE <= sprite2x + SPRITE_SIZE &&
                sprite1y + SPRITE_SIZE >= sprite2y && sprite1y + SPRITE_SIZE <= sprite2y + SPRITE_SIZE);
    } else if (m_Sword.getAttackLeft()) {
        return (sprite1x - SPRITE_SIZE <= sprite2x + SPRITE_SIZE && sprite1x - SPRITE_SIZE >= sprite2x &&
                sprite1y >= sprite2y && sprite1y - SPRITE_SIZE <= sprite2y + SPRITE_SIZE);
    } else if (m_Sword.getAttackRight()) {
        return (sprite1x <= sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE >= sprite2x &&
                sprite1y <= sprite2y + SPRITE_SIZE && sprite1y + SPRITE_SIZE > sprite2y);
    } else if (m_Sword.getAttackUp()) {
        return (sprite1x + SPRITE_SIZE >= sprite2x && sprite1x <= sprite2x + SPRITE_SIZE &&
                sprite1y - SPRITE_SIZE <= sprite2y + SPRITE_SIZE && sprite1y - SPRITE_SIZE >= sprite2y);
    }
    return false;
}

bool Game::collideWall(sf::Vector2f sprite, std::vector <sf::Vector2f> wall) {
    for (size_t x = 0; x < wall.size(); x++) {
        if (collideTwoSprite64x64(sprite, wall[x])) {
            return true;
        }
    }
    return false;
}

bool Game::previewCollide(sf::Vector2f user, sf::Vector2f moove) {
    float nextx = user.x + moove.x,
            nexty = user.y + moove.y;

    bool collide = false;

    if (m_Map.hasTree()) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionTree());
    }
    if (m_Map.hasWall() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWall());
    }
    if (m_Map.hasOrangeTree() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionOrangeTree());
    }
    if (m_Map.hasWater() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWater());
    }
    if (m_Map.hasWhiteTree() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWhiteTree());
    }
    if (m_Map.hasRock() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionRock());
    }
    if (m_Map.hasRedRock() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionRedRock());
    }
    if (m_Map.hasWhiteRock() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), m_Map.getListPositionWhiteRock());
    }
    if (m_Map.thereChest() && !collide) {
        collide = collideTwoSprite64x64(sf::Vector2f(nextx, nexty), m_Map.getChestSprite().getPosition());
    }
    return collide;
}

bool Game::previewLimitMap(sf::Vector2f user, sf::Vector2f moove) {
    float nextx = user.x + moove.x,
            nexty = user.y + moove.y;

    if (nextx > LIMIT_RIGHT_GAME || nextx < LIMIT_LEFT_GAME || nexty > LIMIT_DOWN_GAME || nexty < LIMIT_UP_GAME) {
        return true;
    }
    return false;
}