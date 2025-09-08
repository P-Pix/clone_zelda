/**
 * @file MonsterLegacy.hpp
 * @author Guillaume LEMONNIER  
 * @brief Déclarations legacy pour la classe Monster (compatibilité temporaire)
 * @version 1.0
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _MONSTER_LEGACY_HPP_
#define _MONSTER_LEGACY_HPP_

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Classe Monster legacy (ancienne implementation)
 * Cette classe maintient la compatibilité avec l'ancien code
 * pendant la transition vers l'architecture moderne
 */
class Monster {
private:
    // Attributs principaux
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;
    sf::Vector2f m_nextPosition;
    
    // Stats
    int m_Heart;
    int m_power;
    bool m_invulnerable;
    int m_invulnerableFrame;
    bool m_alive;
    
    // Gains
    int m_gainLifeValor;
    int m_gainRubisValor;
    bool m_thereGain;
    
    // Pattern de mouvement
    std::vector<int> m_paternRelative;

public:
    // Constructeur/Destructeur
    Monster(void);
    Monster(const char* name);
    ~Monster(void);
    
    // Accesseurs
    sf::Sprite getSprite(void);
    sf::Vector2f getNextPosition(void);
    sf::Vector2f getPosition(void);
    int getPower(void);
    bool isAlive(void);
    int getGainLifeValor(void);
    int getGainRubisValor(void);
    bool thereGain(void);
    bool isInvulnerable(void);
    Monster* getAdress(void);
    Monster getMonster(void);
    
    // Méthodes de vie
    void setDamage(int power);
    void dropGain(void);
    void frameInvulnerable(void);
    
    // Méthodes de mouvement
    void moove(void);
    void recoilDown(void);
    void recoilLeft(void);
    void recoilUp(void);
    void recoilRight(void);
    void nextPosition(void);
    
    // Pattern
    void createPaternRelative(void);
    
    // Mouvement  
    void moove(void);
    void recoilDown(void);
    void recoilLeft(void);
    void recoilUp(void);
    void recoilRight(void);
    void nextPosition(void);
    
    // Pattern
    void createPaternRelative(void);
    
    // Sprite
    void initSprite(void);
    void loadSprite(void);
    void loadTexture(const char* name);
    void loadPosition(void);
    
    // Gain
    void gainIsGet(void);
};

#endif // _MONSTER_LEGACY_HPP_
