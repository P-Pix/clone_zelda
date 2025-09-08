/**
 * @file Player.cpp (anciennement Joueur.cpp)
 * @author Guillaume LEMONNIER
 * @brief Implémentation modernisée de la classe Player
 * @version 2.0
 * @date 2025-07-26
 *
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/Joueur.hpp" // Garde le nom original pour la compatibilité
#include "../include/Logger.hpp"
#include "../include/Config.hpp"
#include "../include/Utils.hpp"

Player::Player()
    : Character(EntityType::PLAYER, "image/heros10.png", 100.0f)
    , m_spawnPosition(Window::WIDTH / 2.0f, Window::HEIGHT / 2.0f)
    , m_totalRubis(0)
    , m_attackCooldown(0.5f)
    , m_attackTimer(0.0f)
    , m_swordOffset(0, 0)
    , m_invulnerabilityTimer(0.0f)
    , m_invulnerabilityBlink(0.0f) {
    
    setSpeed(Game::PLAYER_SPEED);
    setPosition(m_spawnPosition);
    
    initializeAnimationTextures();
    loadAnimationTextures();
    initializeSystems();
}

Player::Player(const sf::Vector2f& spawnPosition)
    : Character(EntityType::PLAYER, "image/heros10.png", 100.0f)
    , m_spawnPosition(spawnPosition)
    , m_totalRubis(0)
    , m_attackCooldown(0.5f)
    , m_attackTimer(0.0f)
    , m_swordOffset(0, 0)
    , m_invulnerabilityTimer(0.0f)
    , m_invulnerabilityBlink(0.0f) {
    
    setSpeed(Game::PLAYER_SPEED);
    setPosition(spawnPosition);
    
    initializeAnimationTextures();
    loadAnimationTextures();
    initializeSystems();
}

std::unique_ptr<Entity> Player::clone() const {
    auto player = std::make_unique<Player>(m_spawnPosition);
    player->setMaxHealth(getMaxHealth());
    player->m_totalRubis = m_totalRubis;
    return std::move(player);
}

void Player::initializeAnimationTextures() {
    m_animationTextures = {
        "image/heros10.png", // Frame 0
        "image/heros11.png", // Frame 1
        "image/heros12.png", // Frame 2
        "image/heros13.png", // Frame 3
        "image/heros14.png", // Frame 4
        "image/heros15.png", // Frame 5
        "image/heros16.png", // Frame 6
        "image/heros17.png"  // Frame 7
    };
}

void Player::loadAnimationTextures() {
    // Charger les textures pour chaque direction
    // Note: Dans l'implémentation originale, les 8 textures représentent
    // différentes frames d'animation pour les 4 directions
    
    for (int i = 0; i < 2; ++i) {
        sf::Texture texture;
        if (Utils::loadTexture(texture, m_animationTextures[i])) {
            m_animationTexturesDown.push_back(std::move(texture));
        }
    }
    
    for (int i = 2; i < 4; ++i) {
        sf::Texture texture;
        if (Utils::loadTexture(texture, m_animationTextures[i])) {
            m_animationTexturesUp.push_back(std::move(texture));
        }
    }
    
    for (int i = 4; i < 6; ++i) {
        sf::Texture texture;
        if (Utils::loadTexture(texture, m_animationTextures[i])) {
            m_animationTexturesLeft.push_back(std::move(texture));
        }
    }
    
    for (int i = 6; i < 8; ++i) {
        sf::Texture texture;
        if (Utils::loadTexture(texture, m_animationTextures[i])) {
            m_animationTexturesRight.push_back(std::move(texture));
        }
    }
}

void Player::initializeSystems() {
    m_heartSystem = std::make_unique<Heart>();
    m_rubisSystem = std::make_unique<Rubis>();
    
    Logger::info("Player systems initialized");
}

void Player::update(float deltaTime) {
    if (!m_active) {
        return;
    }
    
    // Mise à jour de la classe parente
    Character::update(deltaTime);
    
    // Mise à jour des timers
    updateTimers(deltaTime);
    
    // Mise à jour de l'invulnérabilité
    updateInvulnerability(deltaTime);
    
    // Traitement du mouvement basé sur les entrées
    processMovement(deltaTime);
    
    // Mise à jour de l'animation
    updatePlayerAnimation(deltaTime);
    
    // Mise à jour de la position de l'épée
    updateSwordPosition();
}

void Player::updateTimers(float deltaTime) {
    if (m_attackTimer > 0.0f) {
        m_attackTimer -= deltaTime;
    }
    
    if (m_invulnerabilityTimer > 0.0f) {
        m_invulnerabilityTimer -= deltaTime;
    }
}

void Player::updateInvulnerability(float deltaTime) {
    if (m_invulnerabilityTimer > 0.0f) {
        m_invulnerabilityBlink += deltaTime;
        
        // Faire clignoter le sprite
        if (static_cast<int>(m_invulnerabilityBlink * 10) % 2 == 0) {
            sf::Uint8 alpha = 128; // Semi-transparent
            sf::Color color = m_sprite.getColor();
            color.a = alpha;
            m_sprite.setColor(color);
        } else {
            sf::Color color = m_sprite.getColor();
            color.a = 255; // Opaque
            m_sprite.setColor(color);
        }
    } else {
        // Restaurer l'opacité normale
        sf::Color color = m_sprite.getColor();
        color.a = 255;
        m_sprite.setColor(color);
    }
}

void Player::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Z:
            case sf::Keyboard::Up:
                m_inputState.up = true;
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                m_inputState.down = true;
                break;
            case sf::Keyboard::Q:
            case sf::Keyboard::Left:
                m_inputState.left = true;
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                m_inputState.right = true;
                break;
            case sf::Keyboard::Space:
                m_inputState.attack = true;
                break;
            case sf::Keyboard::E:
                m_inputState.interact = true;
                break;
            default:
                break;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::Z:
            case sf::Keyboard::Up:
                m_inputState.up = false;
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                m_inputState.down = false;
                break;
            case sf::Keyboard::Q:
            case sf::Keyboard::Left:
                m_inputState.left = false;
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                m_inputState.right = false;
                break;
            case sf::Keyboard::Space:
                m_inputState.attack = false;
                break;
            case sf::Keyboard::E:
                m_inputState.interact = false;
                break;
            default:
                break;
        }
    }
}

void Player::processMovement(float deltaTime) {
    if (isDead()) {
        return;
    }
    
    // Gestion de l'attaque
    if (m_inputState.attack && canAttack()) {
        attack();
    }
    
    // Déterminer la direction de mouvement
    Direction moveDirection = Direction::NONE;
    
    if (m_inputState.up && canMoveInDirection(Direction::UP, deltaTime)) {
        moveDirection = Direction::UP;
    } else if (m_inputState.down && canMoveInDirection(Direction::DOWN, deltaTime)) {
        moveDirection = Direction::DOWN;
    } else if (m_inputState.left && canMoveInDirection(Direction::LEFT, deltaTime)) {
        moveDirection = Direction::LEFT;
    } else if (m_inputState.right && canMoveInDirection(Direction::RIGHT, deltaTime)) {
        moveDirection = Direction::RIGHT;
    }
    
    // Effectuer le mouvement
    if (moveDirection != Direction::NONE) {
        move(moveDirection, deltaTime);
        setAnimationDirection(moveDirection);
    } else {
        setState(CharacterState::IDLE);
    }
}

bool Player::canMoveInDirection(Direction direction, float deltaTime) const {
    sf::Vector2f nextPos = getNextPosition(direction, deltaTime);
    return canMoveTo(nextPos);
}

void Player::setAnimationDirection(Direction direction) {
    setCurrentDirection(direction);
    updateAnimationTexture();
}

void Player::updateAnimationTexture() {
    Direction currentDir = getCurrentDirection();
    int frame = m_currentFrame;
    
    sf::Texture* textureToUse = nullptr;
    
    switch (currentDir) {
        case Direction::UP:
            if (frame < m_animationTexturesUp.size()) {
                textureToUse = &m_animationTexturesUp[frame];
            }
            break;
        case Direction::DOWN:
            if (frame < m_animationTexturesDown.size()) {
                textureToUse = &m_animationTexturesDown[frame];
            }
            break;
        case Direction::LEFT:
            if (frame < m_animationTexturesLeft.size()) {
                textureToUse = &m_animationTexturesLeft[frame];
            }
            break;
        case Direction::RIGHT:
            if (frame < m_animationTexturesRight.size()) {
                textureToUse = &m_animationTexturesRight[frame];
            }
            break;
        default:
            break;
    }
    
    if (textureToUse) {
        m_sprite.setTexture(*textureToUse, true);
    }
}

void Player::updatePlayerAnimation(float deltaTime) {
    updateAnimation(deltaTime);
    updateAnimationTexture();
}

void Player::attack() {
    if (!canAttack()) {
        return;
    }
    
    m_attackTimer = m_attackCooldown;
    setState(CharacterState::ATTACKING);
    
    performAttack();
    
    Logger::debug("Player attacked in direction %d", static_cast<int>(getCurrentDirection()));
}

bool Player::canAttack() const {
    return m_attackTimer <= 0.0f && !isDead() && m_active;
}

void Player::performAttack() {
    // Logique d'attaque - calculer la zone d'attaque basée sur la direction
    sf::FloatRect attackBounds = getSwordBounds();
    
    // Note: Dans une vraie implémentation, on vérifierait les collisions
    // avec les ennemis dans cette zone
}

sf::Vector2f Player::getSwordPosition() const {
    sf::Vector2f playerPos = getPosition();
    return playerPos + m_swordOffset;
}

sf::FloatRect Player::getSwordBounds() const {
    sf::Vector2f swordPos = getSwordPosition();
    float swordSize = Game::SPRITE_SIZE * 0.8f; // L'épée est un peu plus petite que le joueur
    
    return sf::FloatRect(swordPos.x, swordPos.y, swordSize, swordSize);
}

void Player::updateSwordPosition() {
    // Calculer la position de l'épée basée sur la direction
    float offset = Game::SPRITE_SIZE * 0.7f;
    
    switch (getCurrentDirection()) {
        case Direction::UP:
            m_swordOffset = sf::Vector2f(0, -offset);
            break;
        case Direction::DOWN:
            m_swordOffset = sf::Vector2f(0, offset);
            break;
        case Direction::LEFT:
            m_swordOffset = sf::Vector2f(-offset, 0);
            break;
        case Direction::RIGHT:
            m_swordOffset = sf::Vector2f(offset, 0);
            break;
        default:
            m_swordOffset = sf::Vector2f(0, 0);
            break;
    }
}

void Player::makeInvulnerable(float duration) {
    m_invulnerabilityTimer = duration;
    m_invulnerabilityBlink = 0.0f;
}

void Player::increaseMaxLife() {
    float currentMax = getMaxHealth();
    setMaxHealth(currentMax + 10.0f); // Augmenter de 10 points de vie
    heal(10.0f); // Soigner aussi
    
    Logger::info("Player max life increased to %.1f", getMaxHealth());
}

void Player::addRubis(int amount) {
    m_totalRubis += amount;
    Logger::info("Player gained %d rubis, total: %d", amount, m_totalRubis);
}

std::vector<sf::Sprite> Player::getHeartSprites() const {
    if (m_heartSystem) {
        // Retourner la liste des sprites de coeurs basée sur la vie actuelle
        // Note: Implementation dépendante de la classe Heart
        return std::vector<sf::Sprite>(); // Placeholder
    }
    return std::vector<sf::Sprite>();
}

sf::Sprite Player::getHeartSprite(int index) const {
    if (m_heartSystem) {
        // Retourner un sprite de coeur spécifique
        // Note: Implementation dépendante de la classe Heart
        return sf::Sprite(); // Placeholder
    }
    return sf::Sprite();
}

sf::Sprite Player::getRubisLogo() const {
    if (m_rubisSystem) {
        // Retourner le logo des rubis
        // Note: Implementation dépendante de la classe Rubis
        return sf::Sprite(); // Placeholder
    }
    return sf::Sprite();
}

sf::Text Player::getRubisHundreds() const {
    if (m_rubisSystem) {
        // Retourner le texte des centaines
        // Note: Implementation dépendante de la classe Rubis
        return sf::Text(); // Placeholder
    }
    return sf::Text();
}

sf::Text Player::getRubisTens() const {
    if (m_rubisSystem) {
        // Retourner le texte des dizaines
        return sf::Text(); // Placeholder
    }
    return sf::Text();
}

sf::Text Player::getRubisUnits() const {
    if (m_rubisSystem) {
        // Retourner le texte des unités
        return sf::Text(); // Placeholder
    }
    return sf::Text();
}

void Player::applyKnockback(Direction direction, float force) {
    sf::Vector2f knockbackVector = getDirectionVector(direction) * force;
    sf::Vector2f newPosition = getPosition() + knockbackVector;
    
    if (canMoveTo(newPosition)) {
        setPosition(newPosition);
    }
}

sf::Vector2f Player::getDirectionVector(Direction direction) const {
    switch (direction) {
        case Direction::UP: return sf::Vector2f(0, -1);
        case Direction::DOWN: return sf::Vector2f(0, 1);
        case Direction::LEFT: return sf::Vector2f(-1, 0);
        case Direction::RIGHT: return sf::Vector2f(1, 0);
        default: return sf::Vector2f(0, 0);
    }
}

void Player::onDeath() {
    setState(CharacterState::DEAD);
    Logger::info("Player died!");
}

void Player::onDamage(float damage) {
    makeInvulnerable(2.0f); // 2 secondes d'invulnérabilité
    setState(CharacterState::DAMAGED);
    
    Logger::info("Player took %.1f damage, health: %.1f/%.1f", 
                damage, getHealth(), getMaxHealth());
}

void Player::onStateChange(CharacterState oldState, CharacterState newState) {
    Logger::debug("Player state changed from %d to %d", 
                 static_cast<int>(oldState), static_cast<int>(newState));
}
