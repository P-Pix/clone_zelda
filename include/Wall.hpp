/**
 * @file Wall.hpp
 * @author Guillaume LEMONNIER
 * @brief Classe Wall modernisée avec héritage
 * @version 2.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef WALL_HPP
#define WALL_HPP

#include "StaticEntity.hpp"
#include <vector>
#include <memory>

enum class WallType {
    TREE,
    STONE,
    BRICK,
    WOODEN,
    METAL
};

/**
 * @class Wall
 * @brief Classe représentant un mur ou obstacle solide
 * 
 * Hérite de StaticEntity et ajoute la gestion de murs multiples
 * et différents types de murs
 */
class Wall : public StaticEntity {
public:
    // Constructeurs / Destructeur
    Wall();
    Wall(WallType type);
    Wall(const std::string& texturePath);
    Wall(WallType type, const std::vector<sf::Vector2f>& positions);
    virtual ~Wall() = default;

    // Interface Entity
    std::unique_ptr<Entity> clone() const override;

    // Gestion des murs multiples
    void setPositions(const std::vector<sf::Vector2f>& positions);
    void addWallAt(const sf::Vector2f& position);
    void removeWallAt(const sf::Vector2f& position);
    
    // Accesseurs
    WallType getWallType() const { return m_wallType; }
    size_t getWallCount() const { return m_wallPositions.size(); }
    const std::vector<sf::Vector2f>& getWallPositions() const { return m_wallPositions; }

    // Collision avec murs multiples
    bool isCollidingWith(const sf::FloatRect& bounds) const override;
    std::vector<sf::FloatRect> getAllBounds() const;

    // Dessin optimisé pour plusieurs murs
    void draw(sf::RenderWindow& window) override;

    // Interaction
    void onCollision(Entity* other) override;

protected:
    // Surcharges StaticEntity
    void setupSprite() override;

private:
    WallType m_wallType;
    std::vector<sf::Vector2f> m_wallPositions;
    
    // Cache des sprites pour performance
    mutable std::vector<sf::Sprite> m_wallSprites;
    mutable bool m_spritesNeedUpdate;
    
    // Méthodes privées
    void initializeByType(WallType type);
    void updateSpritesCache() const;
    std::string getTexturePathForType(WallType type) const;
    sf::Sprite createSpriteAt(const sf::Vector2f& position) const;
};

#endif // WALL_HPP