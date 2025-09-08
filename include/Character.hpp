/**
 * @file Character.hpp
 * @author Guillaume LEMONNIER
 * @brief Classe de base pour tous les personnages (joueur, monstres)
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Entity.hpp"
#include "Config.hpp"
#include <memory>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

enum class CharacterState {
    IDLE,
    WALKING,
    ATTACKING,
    DAMAGED,
    DEAD
};

/**
 * @class Character
 * @brief Classe de base pour les personnages mobiles du jeu
 * 
 * Cette classe hérite d'Entity et ajoute les fonctionnalités communes
 * aux personnages comme le mouvement, les animations, les points de vie
 */
class Character : public Entity {
public:
    Character();
    Character(EntityType type, const std::string& texturePath, float maxHealth = 100.0f);
    virtual ~Character() = default;

    // Interface IUpdatable
    void update(float deltaTime) override;

    // Interface ICollidable
    bool isCollidingWith(const sf::FloatRect& bounds) const override;
    sf::FloatRect getBounds() const override;

    // Mouvement
    virtual void move(Direction direction, float deltaTime);
    virtual void setSpeed(float speed) { m_speed = speed; }
    float getSpeed() const { return m_speed; }

    // Animation
    virtual void updateAnimation(float deltaTime);
    void setCurrentDirection(Direction direction) { m_currentDirection = direction; }
    Direction getCurrentDirection() const { return m_currentDirection; }

    // Vie et combat
    virtual void takeDamage(float damage);
    virtual void heal(float healAmount);
    bool isDead() const { return m_currentHealth <= 0.0f; }
    
    float getHealth() const { return m_currentHealth; }
    float getMaxHealth() const { return m_maxHealth; }
    void setMaxHealth(float maxHealth);

    // États
    void setState(CharacterState state) { m_state = state; }
    CharacterState getState() const { return m_state; }

    // Position et collision
    sf::Vector2f getNextPosition(Direction direction, float deltaTime) const;
    bool canMoveTo(const sf::Vector2f& position) const;

protected:
    // Propriétés du personnage
    float m_speed;
    float m_maxHealth;
    float m_currentHealth;
    
    // Animation et mouvement
    Direction m_currentDirection;
    CharacterState m_state;
    float m_animationTimer;
    int m_currentFrame;
    
    // Méthodes virtuelles pour les spécialisations
    virtual void onDeath() {}
    virtual void onDamage(float damage) {}
    virtual void onStateChange(CharacterState oldState, CharacterState newState) {}
    
    // Helpers pour les animations
    void updateAnimationFrame();
    sf::IntRect getTextureRect() const;
};

#endif // CHARACTER_HPP
