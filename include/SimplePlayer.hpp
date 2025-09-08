/**
 * @file SimplePlayer.hpp
 * @author Guillaume LEMONNIER
 * @brief Version simplifiée du Player pour la transition
 * @version 2.0
 * @date 2025-07-26
 */

#ifndef SIMPLE_PLAYER_HPP
#define SIMPLE_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Heart.hpp"
#include "Rubis.hpp"
#include "SimpleConfig.hpp"

class Joueur {
public:
    // Constructeurs / Destructeur
    Joueur();
    ~Joueur() = default;

    // Accesseurs de base (compatibilité)
    sf::Sprite getSprite() const { return m_sprite; }
    sf::Vector2f getPosition() const { return m_position; }
    sf::Vector2f getPositionSword() const;
    
    int getLife() const { return m_currentLife; }
    int getMaxLife() const { return m_maxLife; }
    bool isAlive() const { return m_currentLife > 0; }
    bool isInvulnerable() const { return m_invulnerabilityTimer > 0.0f; }
    
    int getSpeed() const { return m_speed; }
    
    // Orientations
    bool getOrientationUp() const { return m_orientationUp; }
    bool getOrientationDown() const { return m_orientationDown; }
    bool getOrientationLeft() const { return m_orientationLeft; }
    bool getOrientationRight() const { return m_orientationRight; }
    int getOrientationValue() const;
    
    // Heart system
    std::vector<sf::Sprite> getListSpriteHeart() const;
    sf::Sprite getSpriteHeart(int number) const;
    
    // Rubis system
    sf::Sprite getLogoRubis() const;
    sf::Text getRubisHundred() const;
    sf::Text getRubisTen() const;
    sf::Text getRubisUnit() const;
    int getTotalRubis() const { return m_totalRubis; }
    
    // Méthodes de modification
    void setOrientationUp();
    void setOrientationDown();
    void setOrientationRight();
    void setOrientationLeft();
    
    void setMaxLifeUp();
    void setHeart(int life);
    void setDamage(int power);
    void frameInvulnerable();
    
    void setPositionUp();
    void setPositionDown();
    void setPositionLeft();
    void setPositionRight();
    
    void animationMoveDown();
    void animationMoveUp();
    void animationMoveLeft();
    void animationMoveRight();
    
    void recoilDown();
    void recoilUp();
    void recoilRight();
    void recoilLeft();
    
    void updateRubis(int valor);

private:
    // Position et sprite
    sf::Vector2f m_position;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    
    // Vie et stats
    int m_currentLife;
    int m_maxLife;
    int m_speed;
    float m_invulnerabilityTimer;
    
    // Orientations
    bool m_orientationUp;
    bool m_orientationDown;
    bool m_orientationLeft;
    bool m_orientationRight;
    
    // Systèmes
    int m_totalRubis;
    
    // Méthodes privées
    void loadTexture();
    void updateTimers();
};

#endif // SIMPLE_PLAYER_HPP
