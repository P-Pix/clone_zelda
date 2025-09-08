/**
 * @file Monster.hpp
 * @author Guillaume LEMONNIER
 * @brief Classe Monster modernisée avec héritage
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"
#include "Gain.hpp"
#include "Heart.hpp"
#include <vector>
#include <memory>
#include <random>

enum class MonsterType {
    BASIC,
    FAST,
    STRONG,
    BOSS
};

enum class AIState {
    PATROLLING,
    CHASING,
    ATTACKING,
    RETURNING,
    STUNNED
};

/**
 * @class Monster
 * @brief Classe représentant un monstre ennemi
 * 
 * Hérite de Character et ajoute l'IA, les patterns de mouvement,
 * et la gestion des gains
 */
class Monster : public Character {
public:
    // Constructeurs / Destructeur
    Monster();
    Monster(MonsterType type, const sf::Vector2f& position = sf::Vector2f(0, 0));
    Monster(const std::string& texturePath, float health = 50.0f);
    virtual ~Monster() = default;

    // Interface Entity
    std::unique_ptr<Entity> clone() const override;

    // Interface IUpdatable 
    void update(float deltaTime) override;

    // Accesseurs modernes
    int getPower() const { return m_power; }
    void setPower(int power) { m_power = power; }
    
    MonsterType getMonsterType() const { return m_monsterType; }
    AIState getAIState() const { return m_aiState; }

    // IA et mouvement
    void setTarget(const sf::Vector2f& targetPosition);
    void setPatrolPattern(const std::vector<sf::Vector2f>& pattern);
    float getDetectionRange() const { return m_detectionRange; }
    void setDetectionRange(float range) { m_detectionRange = range; }

    // Combat
    void attack();
    bool canAttack() const;
    float getAttackCooldown() const { return m_attackCooldown; }

    // Gains et récompenses
    bool hasGain() const { return m_hasGain; }
    void dropGains();
    int getRubisValue() const;
    int getLifeValue() const;

    // Invulnérabilité
    bool isInvulnerable() const { return m_invulnerabilityTimer > 0.0f; }
    void makeInvulnerable(float duration = 1.0f);

    // Recul après dégâts
    void applyKnockback(Direction direction, float force = 50.0f);

protected:
    // Surcharges Character
    void onDeath() override;
    void onDamage(float damage) override;
    void onStateChange(CharacterState oldState, CharacterState newState) override;

private:
    // Propriétés du monstre
    MonsterType m_monsterType;
    int m_power;
    
    // IA
    AIState m_aiState;
    sf::Vector2f m_targetPosition;
    std::vector<sf::Vector2f> m_patrolPattern;
    size_t m_currentPatrolIndex;
    float m_detectionRange;
    float m_returnToPatrolTimer;
    
    // Combat
    float m_attackCooldown;
    float m_attackTimer;
    
    // Effets temporaires
    float m_invulnerabilityTimer;
    sf::Vector2f m_knockbackVelocity;
    float m_knockbackTimer;
    
    // Gains
    bool m_hasGain;
    std::unique_ptr<Gain> m_gain;
    std::unique_ptr<Heart> m_heart;
    
    // Générateur aléatoire pour l'IA
    mutable std::mt19937 m_randomEngine;
    
    // Méthodes privées
    void initializeByType(MonsterType type);
    void updateAI(float deltaTime);
    void updatePatrolling(float deltaTime);
    void updateChasing(float deltaTime);
    void updateAttacking(float deltaTime);
    void updateReturning(float deltaTime);
    void updateStunned(float deltaTime);
    
    void updateTimers(float deltaTime);
    void updateKnockback(float deltaTime);
    
    bool isPlayerInRange(const sf::Vector2f& playerPosition) const;
    sf::Vector2f getDirectionToTarget() const;
    void moveTowardsTarget(float deltaTime);
    void patrolMove(float deltaTime);
    
    void createRandomGain();
    sf::Vector2f getRandomPatrolPoint() const;

};

#endif