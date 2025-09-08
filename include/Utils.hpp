/**
 * @file Utils.hpp
 * @author Guillaume LEMONNIER
 * @brief Utilitaires et fonctions d'aide
 * @version 1.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <filesystem>
#include "Logger.hpp"

namespace Utils {
    /**
     * @brief Vérifie si un fichier existe
     * @param path Chemin vers le fichier
     * @return true si le fichier existe
     */
    inline bool fileExists(const std::string& path) {
        return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
    }
    
    /**
     * @brief Charge une texture avec vérification d'erreur
     * @param texture Texture SFML à charger
     * @param path Chemin vers l'image
     * @return true si le chargement a réussi
     */
    inline bool loadTexture(sf::Texture& texture, const std::string& path) {
        if (!fileExists(path)) {
            Logger::error("Texture file not found: %s", path.c_str());
            return false;
        }
        
        if (!texture.loadFromFile(path)) {
            Logger::error("Failed to load texture: %s", path.c_str());
            return false;
        }
        
        Logger::debug("Texture loaded successfully: %s", path.c_str());
        return true;
    }
    
    /**
     * @brief Charge une police avec vérification d'erreur
     * @param font Police SFML à charger
     * @param path Chemin vers la police
     * @return true si le chargement a réussi
     */
    inline bool loadFont(sf::Font& font, const std::string& path) {
        if (!fileExists(path)) {
            Logger::error("Font file not found: %s", path.c_str());
            return false;
        }
        
        if (!font.loadFromFile(path)) {
            Logger::error("Failed to load font: %s", path.c_str());
            return false;
        }
        
        Logger::debug("Font loaded successfully: %s", path.c_str());
        return true;
    }
    
    /**
     * @brief Calcule la distance entre deux points
     * @param pos1 Premier point
     * @param pos2 Deuxième point
     * @return Distance entre les points
     */
    inline float distance(const sf::Vector2f& pos1, const sf::Vector2f& pos2) {
        float dx = pos2.x - pos1.x;
        float dy = pos2.y - pos1.y;
        return std::sqrt(dx * dx + dy * dy);
    }
    
    /**
     * @brief Normalise un vecteur
     * @param vector Vecteur à normaliser
     * @return Vecteur normalisé
     */
    inline sf::Vector2f normalize(const sf::Vector2f& vector) {
        float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
        if (length != 0.0f) {
            return sf::Vector2f(vector.x / length, vector.y / length);
        }
        return sf::Vector2f(0.0f, 0.0f);
    }
    
    /**
     * @brief Vérifie si un point est dans un rectangle
     * @param point Point à vérifier
     * @param rect Rectangle de vérification
     * @return true si le point est dans le rectangle
     */
    inline bool pointInRect(const sf::Vector2f& point, const sf::FloatRect& rect) {
        return rect.contains(point);
    }
    
    /**
     * @brief Convertit un temps en millisecondes en chaîne lisible
     * @param ms Temps en millisecondes
     * @return Chaîne formatée
     */
    inline std::string formatTime(float ms) {
        if (ms < 1000.0f) {
            return std::to_string(static_cast<int>(ms)) + "ms";
        } else {
            return std::to_string(ms / 1000.0f) + "s";
        }
    }
    
    /**
     * @brief Clamp une valeur entre min et max
     * @param value Valeur à clamper
     * @param min Valeur minimale
     * @param max Valeur maximale
     * @return Valeur clampée
     */
    template<typename T>
    inline T clamp(T value, T min, T max) {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }
}

#endif // _UTILS_HPP_
