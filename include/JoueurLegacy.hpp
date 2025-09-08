/**
 * @file JoueurLegacy.hpp
 * @author Guillaume LEMONNIER  
 * @brief Déclarations legacy pour la classe Joueur (compatibilité temporaire)
 * @version 1.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _JOUEUR_LEGACY_HPP_
#define _JOUEUR_LEGACY_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

/**
 * @brief Classe Joueur legacy (ancienne implementation)
 * Cette classe maintient la compatibilité avec l'ancien code
 * pendant la transition vers l'architecture moderne
 */
class Joueur {
private:
    // Attributs principaux
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;
    
    // Stats du joueur
    int m_life;
    int m_maxLife;
    bool m_invulnerable;
    int m_invulnerableFrame;
    
    // Orientation
    bool m_orientationUp;
    bool m_orientationDown; 
    bool m_orientationLeft;
    bool m_orientationRight;
    int m_orientationValue;
    
    // Position et mouvement
    int m_speed;
    sf::Vector2f m_positionSword;
    
    // Rubis
    int m_totalRubis;
    sf::Sprite m_logoRubis;
    sf::Text m_rubisHundred;
    sf::Text m_rubisTen;
    sf::Text m_rubisUnit;
    
    // Coeurs/vie
    std::vector<sf::Sprite> m_listSpriteHeart;
    
    // Animation
    std::vector<const char*> m_listeAnimationDown;
    std::vector<const char*> m_listeAnimationUp;
    std::vector<const char*> m_listeAnimationLeft;
    std::vector<const char*> m_listeAnimationRight;

public:
    // Constructeur/Destructeur
    Joueur(void);
    ~Joueur(void);
    
    // Accesseurs vie
    int getLife(void);
    int getMaxLife(void);
    bool isAlive(void);
    bool isInvulnerable(void);
    std::vector<sf::Sprite> getListSpriteHeart(void);
    sf::Sprite getSpriteHeart(int number);
    
    // Accesseurs orientation
    bool getOrientationDown(void);
    bool getOrientationLeft(void);
    bool getOrientationRight(void);
    bool getOrientationUp(void);
    int getOrientationValue(void);
    
    // Accesseurs position
    sf::Vector2f getPosition(void);
    sf::Vector2f getPositionSword(void);
    int getSpeed(void);
    
    // Accesseurs rubis
    sf::Sprite getLogoRubis(void);
    sf::Text getRubisHundred(void);
    sf::Text getRubisTen(void);
    sf::Text getRubisUnit(void);
    int getTotalRubis(void);
    
    // Animation
    void animationMoveRight(void);
    void animationMoveLeft(void);
    void animationMoveUp(void);
    void animationMoveDown(void);
    
    // Mouvement
    void recoilDown(void);
    void recoilLeft(void);
    void recoilRight(void);
    void recoilUp(void);
    void moveLeft(void);
    void moveRight(void);
    void moveUp(void);
    void moveDown(void);
    void makeListeAnimation(void);
    void moveAniamtion(int frame, std::vector<const char*> liste);
    
    // Orientation
    void setOrientationDown(void);
    void setOrientationLeft(void);
    void setOrientationUp(void);
    void setOrientationRight(void);
    
    // Rubis
    void updateRubis(int valor);
    
    // Vie et combat
    void setMaxLifeUp(void);
    void setHeart(int life);
    void setDamage(int power);
    void frameInvulnerable(void);
    
    // Sprite
    sf::Sprite loadSprite(const char* name, sf::Vector2f vector);
    void loadTexture(const char* name);
    sf::Sprite getSprite(void);
    Joueur* getAdress(void);
    
    // Position et mouvement
    void setPositionDown(void);
    void setPositionUp(void);
    void setPositionRight(void);
    void setPositionLeft(void);
};

#endif // _JOUEUR_LEGACY_HPP_
