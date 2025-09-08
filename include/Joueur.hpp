/**
 * @file Player.hpp (anciennement Joueur.hpp)
 * @author Guillaume LEMONNIER
 * @brief Classe Player modernisée avec héritage
 * @version 2.0
 * @date 2025-07-26
 *
 * @copyright Copyright (c) 2021-2025
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Heart.hpp"
#include "Rubis.hpp"
#include <array>
#include <memory>

enum class PlayerState {
    IDLE = static_cast<int>(CharacterState::IDLE),
    WALKING = static_cast<int>(CharacterState::WALKING),
    ATTACKING = static_cast<int>(CharacterState::ATTACKING),
    DAMAGED = static_cast<int>(CharacterState::DAMAGED),
    DEAD = static_cast<int>(CharacterState::DEAD),
    INTERACTING
};

/**
 * @class Player
 * @brief Classe représentant le joueur contrôlé par l'utilisateur
 * 
 * Hérite de Character et ajoute les fonctionnalités spécifiques au joueur :
 * - Gestion des entrées clavier
 * - Système d'inventaire (rubis, coeurs)
 * - Animations complexes
 * - Attaques avec épée
 */
class Player : public Character {
public:
    // Constructeurs / Destructeur
    Player();
    Player(const sf::Vector2f& spawnPosition);
    virtual ~Player() = default;

    // Interface Entity
    std::unique_ptr<Entity> clone() const override;

    // Interface IUpdatable
    void update(float deltaTime) override;

    // Gestion des entrées
    void handleInput(const sf::Event& event);
    void processMovement(float deltaTime);

    // Position et épée
    sf::Vector2f getSwordPosition() const;
    sf::FloatRect getSwordBounds() const;

    // Système de coeurs/vie
    int getMaxLife() const { return static_cast<int>(getMaxHealth()); }
    void increaseMaxLife();
    std::vector<sf::Sprite> getHeartSprites() const;
    sf::Sprite getHeartSprite(int index) const;

    // Système de rubis
    sf::Sprite getRubisLogo() const;
    sf::Text getRubisHundreds() const;
    sf::Text getRubisTens() const;
    sf::Text getRubisUnits() const;
    int getTotalRubis() const { return m_totalRubis; }
    void addRubis(int amount);

    // Combat et invulnérabilité
    void attack();
    bool canAttack() const;
    void makeInvulnerable(float duration = 2.0f);
    bool isInvulnerable() const { return m_invulnerabilityTimer > 0.0f; }

    // Orientations (pour compatibilité)
    bool getOrientationUp() const { return getCurrentDirection() == Direction::UP; }
    bool getOrientationDown() const { return getCurrentDirection() == Direction::DOWN; }
    bool getOrientationLeft() const { return getCurrentDirection() == Direction::LEFT; }
    bool getOrientationRight() const { return getCurrentDirection() == Direction::RIGHT; }
    int getOrientationValue() const { return static_cast<int>(getCurrentDirection()); }

    // Animation
    void updatePlayerAnimation(float deltaTime);

protected:
    // Surcharges Character
    void onDeath() override;
    void onDamage(float damage) override;
    void onStateChange(CharacterState oldState, CharacterState newState) override;

private:
    // Textures d'animation
    static constexpr size_t ANIMATION_FRAMES = 8;
    std::array<std::string, ANIMATION_FRAMES> m_animationTextures;
    
    // Animation
    std::vector<sf::Texture> m_animationTexturesUp;
    std::vector<sf::Texture> m_animationTexturesDown;
    std::vector<sf::Texture> m_animationTexturesLeft;
    std::vector<sf::Texture> m_animationTexturesRight;
    
    // Position de spawn
    sf::Vector2f m_spawnPosition;
    
    // Système de coeurs et rubis
    std::unique_ptr<Heart> m_heartSystem;
    std::unique_ptr<Rubis> m_rubisSystem;
    int m_totalRubis;
    
    // Combat
    float m_attackCooldown;
    float m_attackTimer;
    sf::Vector2f m_swordOffset;
    
    // Invulnérabilité
    float m_invulnerabilityTimer;
    float m_invulnerabilityBlink;
    
    // État des touches
    struct InputState {
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        bool attack = false;
        bool interact = false;
    } m_inputState;
    
    // Méthodes privées
    void initializeAnimationTextures();
    void loadAnimationTextures();
    void initializeSystems();
    
    void updateTimers(float deltaTime);
    void updateInvulnerability(float deltaTime);
    
    // Animation
    void setAnimationDirection(Direction direction);
    void updateAnimationTexture();
    
    // Mouvement avec collisions
    bool canMoveInDirection(Direction direction, float deltaTime) const;
    void applyKnockback(Direction direction, float force = 40.0f);
    
    // Combat
    void performAttack();
    void updateSwordPosition();
    
    // Utilitaires
    sf::Vector2f getDirectionVector(Direction direction) const;
};

// Alias pour la compatibilité avec l'ancien code
using Joueur = Player;

#endif // PLAYER_HPP