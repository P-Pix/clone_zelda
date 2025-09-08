/**
 * @file SimpleMonster.hpp
 * @author Guillaume LEMONNIER
 * @brief Version simplifiée du Monster pour la transition
 * @version 2.0
 * @date 2025-07-26
 */

#ifndef SIMPLE_MONSTER_HPP
#define SIMPLE_MONSTER_HPP

#include <SFML/Graphics.hpp>
#include "Gain.hpp"
#include "Heart.hpp"
#include "SimpleConfig.hpp"
#include <vector>

class Monster {
public:
    // Constructeurs / Destructeur
    Monster();
    Monster(const char* name);
    ~Monster() = default;

    // Accesseurs (compatibilité)
    Monster* getAdress() { return this; }
    Monster getMonster() { return *this; }
    
    sf::Sprite getSprite() const { return m_sprite; }
    sf::Vector2f getPosition() const { return m_position; }
    sf::Vector2f getNextPosition() const;
    
    int getPower() const { return m_power; }
    bool isAlive() const { return m_currentHealth > 0; }
    
    int getGainRubisValor() const;
    int getGainLifeValor() const;
    bool thereGain() const { return m_hasGain; }
    bool isInvulnerable() const { return m_invulnerabilityTimer > 0.0f; }

    // Méthodes de modification
    void setPower(int power) { m_power = power; }
    void moove();
    void nextPosition();
    void setDamage(int power);
    
    void recoilUp();
    void recoilDown();
    void recoilRight();
    void recoilLeft();
    
    void createPaternRelative();
    void gainIsGet();
    void frameInvulnerable();

private:
    // Variables de base
    sf::Vector2f m_position;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    
    int m_power;
    float m_currentHealth;
    float m_invulnerabilityTimer;
    bool m_hasGain;
    
    // Pattern de mouvement
    std::vector<sf::Vector2f> m_pattern;
    int m_currentPatternIndex;
    
    // Systèmes de gain (simplifiés)
    Gain m_gain;
    
    // Méthodes privées
    void loadTexture(const char* name);
    void initSprite();
    void dropGain();
};

#endif // SIMPLE_MONSTER_HPP
