/**
 * @file Entity.hpp
 * @author Guillaume LEMONNIER
 * @brief Classe de base abstraite pour toutes les entités du jeu
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Config.hpp"

/**
 * @brief Énumération des types d'entités
 */
enum class EntityType {
    PLAYER,
    MONSTER,
    WALL,
    GROUND,
    ITEM,
    WEAPON,
    PROJECTILE
};

/**
 * @brief Interface pour les objets qui peuvent être dessinés
 */
class IDrawable {
public:
    virtual ~IDrawable() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual sf::Sprite getSprite() const = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual sf::Vector2f getPosition() const = 0;
};

/**
 * @brief Interface pour les objets qui peuvent être mis à jour
 */
class IUpdatable {
public:
    virtual ~IUpdatable() = default;
    virtual void update(float deltaTime) = 0;
};

/**
 * @brief Interface pour les objets qui peuvent entrer en collision
 */
class ICollidable {
public:
    virtual ~ICollidable() = default;
    virtual bool isCollidingWith(const sf::FloatRect& bounds) const = 0;
    virtual sf::FloatRect getBounds() const = 0;
};

/**
 * @brief Classe de base abstraite pour toutes les entités du jeu
 */
class Entity : public IDrawable, public IUpdatable, public ICollidable {
protected:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;
    EntityType m_type;
    bool m_active;
    std::string m_texturePath;
    
    /**
     * @brief Charge la texture depuis un fichier
     * @param texturePath Chemin vers la texture
     * @return true si le chargement a réussi
     */
    virtual bool loadTexture(const std::string& texturePath);
    
    /**
     * @brief Initialise le sprite avec la texture
     */
    virtual void setupSprite();

public:
    /**
     * @brief Constructeur par défaut
     */
    Entity();
    
    /**
     * @brief Constructeur avec type et texture
     * @param type Type de l'entité
     * @param texturePath Chemin vers la texture
     */
    Entity(EntityType type, const std::string& texturePath);
    
    /**
     * @brief Destructeur virtuel
     */
    virtual ~Entity() = default;
    
    // Implémentation de IDrawable
    void draw(sf::RenderWindow& window) override;
    sf::Sprite getSprite() const override;
    void setPosition(const sf::Vector2f& position) override;
    sf::Vector2f getPosition() const override;
    
    // Implémentation de ICollidable
    bool isCollidingWith(const sf::FloatRect& bounds) const override;
    sf::FloatRect getBounds() const override;
    
    // Getters
    EntityType getType() const { return m_type; }
    bool isActive() const { return m_active; }
    const std::string& getTexturePath() const { return m_texturePath; }
    
    // Setters
    void setActive(bool active) { m_active = active; }
    
    /**
     * @brief Clone l'entité (patron de conception Prototype)
     * @return Pointeur unique vers la copie
     */
    virtual std::unique_ptr<Entity> clone() const = 0;
    
    /**
     * @brief Sérialise l'entité (pour sauvegarde)
     * @return Données sérialisées
     */
    virtual std::string serialize() const;
    
    /**
     * @brief Désérialise l'entité (pour chargement)
     * @param data Données sérialisées
     */
    virtual void deserialize(const std::string& data);
};

#endif // _ENTITY_HPP_
