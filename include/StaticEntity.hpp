/**
 * @file StaticEntity.hpp
 * @author Guillaume LEMONNIER
 * @brief Classe de base pour les entités statiques (murs, sol, objets)
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef STATIC_ENTITY_HPP
#define STATIC_ENTITY_HPP

#include "Entity.hpp"
#include <vector>

enum class StaticEntityType {
    WALL,
    GROUND,
    OBSTACLE,
    DECORATION,
    CHEST,
    DOOR,
    TRIGGER
};

/**
 * @class StaticEntity
 * @brief Classe de base pour les entités statiques du jeu
 * 
 * Les entités statiques ne bougent pas mais peuvent avoir des interactions
 * comme les collisions, l'activation, etc.
 */
class StaticEntity : public Entity {
public:
    StaticEntity();
    StaticEntity(StaticEntityType type, const std::string& texturePath);
    virtual ~StaticEntity() = default;

    // Interface IUpdatable (généralement vide pour les entités statiques)
    void update(float deltaTime) override {}

    // Interface ICollidable
    bool isCollidingWith(const sf::FloatRect& bounds) const override;
    sf::FloatRect getBounds() const override;

    // Propriétés des entités statiques
    StaticEntityType getStaticType() const { return m_staticType; }
    
    bool isSolid() const { return m_isSolid; }
    void setSolid(bool solid) { m_isSolid = solid; }
    
    bool isInteractable() const { return m_isInteractable; }
    void setInteractable(bool interactable) { m_isInteractable = interactable; }

    // Interaction
    virtual void onInteract() {}
    virtual void onCollision(Entity* other) {}

    // Gestion de sprites multiples (pour les murs avec différentes orientations)
    void addSprite(const sf::Sprite& sprite);
    void clearSprites();
    const std::vector<sf::Sprite>& getSprites() const { return m_additionalSprites; }

    // Surcharge du dessin pour les sprites multiples
    void draw(sf::RenderWindow& window) override;

protected:
    StaticEntityType m_staticType;
    bool m_isSolid;
    bool m_isInteractable;
    
    // Sprites additionnels pour des entités complexes
    std::vector<sf::Sprite> m_additionalSprites;
    std::vector<sf::Texture> m_additionalTextures;
    
    // Méthodes utilitaires
    void loadMultipleTextures(const std::vector<std::string>& texturePaths);
};

#endif // STATIC_ENTITY_HPP
