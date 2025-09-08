/**
 * @file Monster.cpp
 * @author Guillaume LEMONNIER
 * @brief Implémentation modernisée de la classe Monster
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/Monster.hpp"
#include "../include/Logger.hpp"
#include "../include/Config.hpp"
#include <random>
#include <cmath>
#include <algorithm>

Monster::Monster() 
    : Character(EntityType::MONSTER, "image/monster1.png", 50.0f)
    , m_monsterType(MonsterType::BASIC)
    , m_power(4)
    , m_aiState(AIState::PATROLLING)
    , m_targetPosition(0, 0)
    , m_currentPatrolIndex(0)
    , m_detectionRange(100.0f)
    , m_returnToPatrolTimer(0.0f)
    , m_attackCooldown(1.5f)
    , m_attackTimer(0.0f)
    , m_invulnerabilityTimer(0.0f)
    , m_knockbackVelocity(0, 0)
    , m_knockbackTimer(0.0f)
    , m_hasGain(true)
    , m_randomEngine(std::random_device{}()) {
    
    initializeByType(m_monsterType);
    createRandomGain();
}

Monster::Monster(MonsterType type, const sf::Vector2f& position)
    : Character(EntityType::MONSTER, "image/monster1.png", 50.0f)
    , m_monsterType(type)
    , m_power(4)
    , m_aiState(AIState::PATROLLING)
    , m_targetPosition(position)
    , m_currentPatrolIndex(0)
    , m_detectionRange(100.0f)
    , m_returnToPatrolTimer(0.0f)
    , m_attackCooldown(1.5f)
    , m_attackTimer(0.0f)
    , m_invulnerabilityTimer(0.0f)
    , m_knockbackVelocity(0, 0)
    , m_knockbackTimer(0.0f)
    , m_hasGain(true)
    , m_randomEngine(std::random_device{}()) {
    
    setPosition(position);
    initializeByType(type);
    createRandomGain();
}

Monster::Monster(const std::string& texturePath, float health)
    : Character(EntityType::MONSTER, texturePath, health)
    , m_monsterType(MonsterType::BASIC)
    , m_power(4)
    , m_aiState(AIState::PATROLLING)
    , m_targetPosition(0, 0)
    , m_currentPatrolIndex(0)
    , m_detectionRange(100.0f)
    , m_returnToPatrolTimer(0.0f)
    , m_attackCooldown(1.5f)
    , m_attackTimer(0.0f)
    , m_invulnerabilityTimer(0.0f)
    , m_knockbackVelocity(0, 0)
    , m_knockbackTimer(0.0f)
    , m_hasGain(true)
    , m_randomEngine(std::random_device{}()) {
    
    initializeByType(m_monsterType);
    createRandomGain();
}

std::unique_ptr<Entity> Monster::clone() const {
    auto monster = std::make_unique<Monster>();
    monster->m_monsterType = m_monsterType;
    monster->m_power = m_power;
    monster->setPosition(getPosition());
    monster->setMaxHealth(getMaxHealth());
    return std::move(monster);
}

void Monster::initializeByType(MonsterType type) {
    switch (type) {
        case MonsterType::BASIC:
            setSpeed(30.0f);
            setMaxHealth(50.0f);
            m_power = 4;
            m_detectionRange = 80.0f;
            m_attackCooldown = 1.5f;
            break;
            
        case MonsterType::FAST:
            setSpeed(60.0f);
            setMaxHealth(30.0f);
            m_power = 3;
            m_detectionRange = 120.0f;
            m_attackCooldown = 1.0f;
            break;
            
        case MonsterType::STRONG:
            setSpeed(20.0f);
            setMaxHealth(100.0f);
            m_power = 8;
            m_detectionRange = 60.0f;
            m_attackCooldown = 2.0f;
            break;
            
        case MonsterType::BOSS:
            setSpeed(40.0f);
            setMaxHealth(200.0f);
            m_power = 15;
            m_detectionRange = 150.0f;
            m_attackCooldown = 0.8f;
            break;
    }
    
    // Créer un pattern de patrouille par défaut
    sf::Vector2f startPos = getPosition();
    m_patrolPattern = {
        startPos,
        startPos + sf::Vector2f(50, 0),
        startPos + sf::Vector2f(50, 50),
        startPos + sf::Vector2f(0, 50)
    };
}

void Monster::update(float deltaTime) {
    if (!m_active || isDead()) {
        return;
    }
    
    // Mise à jour de la classe parente
    Character::update(deltaTime);
    
    // Mise à jour des timers
    updateTimers(deltaTime);
    
    // Mise à jour du knockback
    updateKnockback(deltaTime);
    
    // Mise à jour de l'IA si pas en knockback
    if (m_knockbackTimer <= 0.0f) {
        updateAI(deltaTime);
    }
}

void Monster::updateTimers(float deltaTime) {
    if (m_attackTimer > 0.0f) {
        m_attackTimer -= deltaTime;
    }
    
    if (m_invulnerabilityTimer > 0.0f) {
        m_invulnerabilityTimer -= deltaTime;
    }
    
    if (m_knockbackTimer > 0.0f) {
        m_knockbackTimer -= deltaTime;
    }
    
    if (m_returnToPatrolTimer > 0.0f) {
        m_returnToPatrolTimer -= deltaTime;
    }
}

void Monster::updateKnockback(float deltaTime) {
    if (m_knockbackTimer > 0.0f) {
        sf::Vector2f currentPos = getPosition();
        sf::Vector2f newPos = currentPos + m_knockbackVelocity * deltaTime;
        
        if (canMoveTo(newPos)) {
            setPosition(newPos);
        }
        
        // Réduire la vélocité avec le temps
        m_knockbackVelocity *= 0.9f;
    }
}

void Monster::updateAI(float deltaTime) {
    switch (m_aiState) {
        case AIState::PATROLLING:
            updatePatrolling(deltaTime);
            break;
        case AIState::CHASING:
            updateChasing(deltaTime);
            break;
        case AIState::ATTACKING:
            updateAttacking(deltaTime);
            break;
        case AIState::RETURNING:
            updateReturning(deltaTime);
            break;
        case AIState::STUNNED:
            updateStunned(deltaTime);
            break;
    }
}

void Monster::updatePatrolling(float deltaTime) {
    // Vérifier si le joueur est dans la zone de détection
    // Note: Dans une vraie implémentation, on passerait la position du joueur
    
    // Mouvement de patrouille
    patrolMove(deltaTime);
}

void Monster::updateChasing(float deltaTime) {
    // Poursuivre la cible
    moveTowardsTarget(deltaTime);
    
    // Vérifier si on peut attaquer
    float distanceToTarget = std::sqrt(
        std::pow(m_targetPosition.x - getPosition().x, 2) +
        std::pow(m_targetPosition.y - getPosition().y, 2)
    );
    
    if (distanceToTarget <= Game::SPRITE_SIZE && canAttack()) {
        m_aiState = AIState::ATTACKING;
        attack();
    }
    
    // Si trop loin, retourner en patrouille
    if (distanceToTarget > m_detectionRange * 1.5f) {
        m_aiState = AIState::RETURNING;
        m_returnToPatrolTimer = 3.0f;
    }
}

void Monster::updateAttacking(float deltaTime) {
    // Rester en mode attaque pendant un court moment
    if (m_attackTimer <= 0.0f) {
        m_aiState = AIState::CHASING;
    }
}

void Monster::updateReturning(float deltaTime) {
    // Retourner au point de patrouille le plus proche
    patrolMove(deltaTime);
    
    if (m_returnToPatrolTimer <= 0.0f) {
        m_aiState = AIState::PATROLLING;
    }
}

void Monster::updateStunned(float deltaTime) {
    // Ne rien faire, juste attendre
    if (m_invulnerabilityTimer <= 0.0f) {
        m_aiState = AIState::PATROLLING;
    }
}

void Monster::patrolMove(float deltaTime) {
    if (m_patrolPattern.empty()) {
        return;
    }
    
    sf::Vector2f currentPos = getPosition();
    sf::Vector2f targetPatrolPoint = m_patrolPattern[m_currentPatrolIndex];
    
    // Calculer la direction vers le point de patrouille
    sf::Vector2f direction = targetPatrolPoint - currentPos;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    
    if (distance < 10.0f) {
        // Passer au point suivant
        m_currentPatrolIndex = (m_currentPatrolIndex + 1) % m_patrolPattern.size();
    } else {
        // Se diriger vers le point actuel
        direction /= distance; // Normaliser
        
        Direction moveDir = Direction::NONE;
        if (std::abs(direction.x) > std::abs(direction.y)) {
            moveDir = (direction.x > 0) ? Direction::RIGHT : Direction::LEFT;
        } else {
            moveDir = (direction.y > 0) ? Direction::DOWN : Direction::UP;
        }
        
        move(moveDir, deltaTime);
    }
}

void Monster::moveTowardsTarget(float deltaTime) {
    sf::Vector2f direction = getDirectionToTarget();
    
    Direction moveDir = Direction::NONE;
    if (std::abs(direction.x) > std::abs(direction.y)) {
        moveDir = (direction.x > 0) ? Direction::RIGHT : Direction::LEFT;
    } else {
        moveDir = (direction.y > 0) ? Direction::DOWN : Direction::UP;
    }
    
    move(moveDir, deltaTime);
}

sf::Vector2f Monster::getDirectionToTarget() const {
    sf::Vector2f direction = m_targetPosition - getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    
    if (length > 0) {
        direction /= length; // Normaliser
    }
    
    return direction;
}

void Monster::setTarget(const sf::Vector2f& targetPosition) {
    m_targetPosition = targetPosition;
    
    // Si on était en patrouille et qu'une cible est détectée
    if (m_aiState == AIState::PATROLLING && isPlayerInRange(targetPosition)) {
        m_aiState = AIState::CHASING;
        Logger::debug("Monster started chasing target");
    }
}

void Monster::setPatrolPattern(const std::vector<sf::Vector2f>& pattern) {
    m_patrolPattern = pattern;
    m_currentPatrolIndex = 0;
}

bool Monster::isPlayerInRange(const sf::Vector2f& playerPosition) const {
    float distance = std::sqrt(
        std::pow(playerPosition.x - getPosition().x, 2) +
        std::pow(playerPosition.y - getPosition().y, 2)
    );
    
    return distance <= m_detectionRange;
}

void Monster::attack() {
    if (!canAttack()) {
        return;
    }
    
    m_attackTimer = m_attackCooldown;
    setState(CharacterState::ATTACKING);
    
    Logger::debug("Monster attacked with power %d", m_power);
}

bool Monster::canAttack() const {
    return m_attackTimer <= 0.0f && !isDead() && m_active;
}

void Monster::applyKnockback(Direction direction, float force) {
    switch (direction) {
        case Direction::UP:
            m_knockbackVelocity = sf::Vector2f(0, -force);
            break;
        case Direction::DOWN:
            m_knockbackVelocity = sf::Vector2f(0, force);
            break;
        case Direction::LEFT:
            m_knockbackVelocity = sf::Vector2f(-force, 0);
            break;
        case Direction::RIGHT:
            m_knockbackVelocity = sf::Vector2f(force, 0);
            break;
        default:
            m_knockbackVelocity = sf::Vector2f(0, 0);
            break;
    }
    
    m_knockbackTimer = 0.3f; // 300ms de knockback
}

void Monster::makeInvulnerable(float duration) {
    m_invulnerabilityTimer = duration;
    m_aiState = AIState::STUNNED;
}

void Monster::onDeath() {
    setState(CharacterState::DEAD);
    dropGains();
    Logger::info("Monster died and dropped gains");
}

void Monster::onDamage(float damage) {
    makeInvulnerable(1.0f);
    
    // Appliquer un petit knockback
    if (m_currentDirection != Direction::NONE) {
        // Knockback dans la direction opposée
        Direction oppositeDir = Direction::NONE;
        switch (m_currentDirection) {
            case Direction::UP: oppositeDir = Direction::DOWN; break;
            case Direction::DOWN: oppositeDir = Direction::UP; break;
            case Direction::LEFT: oppositeDir = Direction::RIGHT; break;
            case Direction::RIGHT: oppositeDir = Direction::LEFT; break;
            default: break;
        }
        
        if (oppositeDir != Direction::NONE) {
            applyKnockback(oppositeDir, 30.0f);
        }
    }
}

void Monster::onStateChange(CharacterState oldState, CharacterState newState) {
    Logger::debug("Monster state changed from %d to %d", 
                 static_cast<int>(oldState), static_cast<int>(newState));
}

void Monster::createRandomGain() {
    std::uniform_int_distribution<int> gainChance(1, 100);
    
    if (gainChance(m_randomEngine) <= 70) { // 70% chance de gain
        m_hasGain = true;
        
        // Créer un gain aléatoire
        if (gainChance(m_randomEngine) <= 50) {
            // Rubis
            m_gain = std::make_unique<Gain>();
        } else {
            // Coeur
            m_heart = std::make_unique<Heart>();
        }
    } else {
        m_hasGain = false;
    }
}

void Monster::dropGains() {
    if (!m_hasGain) {
        return;
    }
    
    // Placer les gains à la position du monstre
    sf::Vector2f dropPosition = getPosition();
    
    if (m_gain) {
        // Logique pour placer le gain dans le monde
        Logger::info("Dropped rubis at position (%.1f, %.1f)", 
                    dropPosition.x, dropPosition.y);
    }
    
    if (m_heart) {
        // Logique pour placer le coeur dans le monde
        Logger::info("Dropped heart at position (%.1f, %.1f)", 
                    dropPosition.x, dropPosition.y);
    }
    
    m_hasGain = false;
}

int Monster::getRubisValue() const {
    if (m_gain) {
        // Retourner la valeur du gain
        return 10; // Valeur par défaut
    }
    return 0;
}

int Monster::getLifeValue() const {
    if (m_heart) {
        // Retourner la valeur du coeur
        return 1; // Valeur par défaut
    }
    return 0;
}
