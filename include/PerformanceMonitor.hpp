/**
 * @file PerformanceMonitor.hpp
 * @author Guillaume LEMONNIER
 * @brief Moniteur de performances pour optimisation
 * @version 1.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _PERFORMANCE_MONITOR_HPP_
#define _PERFORMANCE_MONITOR_HPP_

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include <string>
#include <unordered_map>
#include "Logger.hpp"
#include "Config.hpp"

class PerformanceMonitor {
private:
    struct FrameData {
        float frameTime;
        float renderTime;
        float updateTime;
        std::chrono::high_resolution_clock::time_point timestamp;
    };
    
    std::vector<FrameData> m_frameHistory;
    std::unordered_map<std::string, std::chrono::high_resolution_clock::time_point> m_timers;
    
    sf::Clock m_frameClock;
    sf::Clock m_totalClock;
    
    static constexpr size_t MAX_FRAME_HISTORY = 120; // 2 secondes à 60 FPS
    static constexpr float WARNING_FRAME_TIME = 20.0f; // ms
    static constexpr float CRITICAL_FRAME_TIME = 33.0f; // ms
    
    float m_averageFrameTime = 0.0f;
    float m_minFrameTime = 1000.0f;
    float m_maxFrameTime = 0.0f;
    int m_totalFrames = 0;
    
public:
    PerformanceMonitor() {
        m_frameHistory.reserve(MAX_FRAME_HISTORY);
        Logger::debug("PerformanceMonitor initialized");
    }
    
    /**
     * @brief Démarre un timer nommé
     * @param name Nom du timer
     */
    void startTimer(const std::string& name) {
        m_timers[name] = std::chrono::high_resolution_clock::now();
    }
    
    /**
     * @brief Arrête un timer et retourne le temps écoulé
     * @param name Nom du timer
     * @return Temps écoulé en millisecondes
     */
    float endTimer(const std::string& name) {
        auto it = m_timers.find(name);
        if (it == m_timers.end()) {
            Logger::warning("Timer '%s' not found", name.c_str());
            return 0.0f;
        }
        
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            now - it->second).count();
        
        float timeMs = duration / 1000.0f;
        m_timers.erase(it);
        
        return timeMs;
    }
    
    /**
     * @brief Marque le début d'une nouvelle frame
     */
    void beginFrame() {
        m_frameClock.restart();
        startTimer("frame");
    }
    
    /**
     * @brief Marque la fin d'une frame et collecte les métriques
     */
    void endFrame() {
        float frameTime = endTimer("frame");
        
        FrameData data;
        data.frameTime = frameTime;
        data.renderTime = 0.0f; // À implémenter si nécessaire
        data.updateTime = 0.0f; // À implémenter si nécessaire
        data.timestamp = std::chrono::high_resolution_clock::now();
        
        // Ajouter à l'historique
        if (m_frameHistory.size() >= MAX_FRAME_HISTORY) {
            m_frameHistory.erase(m_frameHistory.begin());
        }
        m_frameHistory.push_back(data);
        
        // Mettre à jour les statistiques
        updateStatistics(frameTime);
        
        // Alertes de performance
        if (frameTime > CRITICAL_FRAME_TIME) {
            Logger::warning("Critical frame time: %.2fms (target: <%.2fms)", 
                          frameTime, CRITICAL_FRAME_TIME);
        } else if (frameTime > WARNING_FRAME_TIME) {
            Logger::debug("Slow frame: %.2fms", frameTime);
        }
        
        m_totalFrames++;
    }
    
    /**
     * @brief Obtient le FPS moyen
     * @return FPS moyen
     */
    float getAverageFPS() const {
        return m_averageFrameTime > 0.0f ? 1000.0f / m_averageFrameTime : 0.0f;
    }
    
    /**
     * @brief Obtient le temps de frame moyen
     * @return Temps de frame moyen en ms
     */
    float getAverageFrameTime() const {
        return m_averageFrameTime;
    }
    
    /**
     * @brief Obtient le temps de frame minimum
     * @return Temps de frame minimum en ms
     */
    float getMinFrameTime() const {
        return m_minFrameTime;
    }
    
    /**
     * @brief Obtient le temps de frame maximum
     * @return Temps de frame maximum en ms
     */
    float getMaxFrameTime() const {
        return m_maxFrameTime;
    }
    
    /**
     * @brief Génère un rapport de performance
     */
    void printReport() const {
        Logger::info("=== Performance Report ===");
        Logger::info("Total frames: %d", m_totalFrames);
        Logger::info("Average FPS: %.1f", getAverageFPS());
        Logger::info("Average frame time: %.2fms", m_averageFrameTime);
        Logger::info("Min frame time: %.2fms", m_minFrameTime);
        Logger::info("Max frame time: %.2fms", m_maxFrameTime);
        Logger::info("Total uptime: %.2fs", m_totalClock.getElapsedTime().asSeconds());
        
        if (!m_frameHistory.empty()) {
            int slowFrames = 0;
            int criticalFrames = 0;
            
            for (const auto& frame : m_frameHistory) {
                if (frame.frameTime > CRITICAL_FRAME_TIME) {
                    criticalFrames++;
                } else if (frame.frameTime > WARNING_FRAME_TIME) {
                    slowFrames++;
                }
            }
            
            float slowPercentage = (slowFrames * 100.0f) / m_frameHistory.size();
            float criticalPercentage = (criticalFrames * 100.0f) / m_frameHistory.size();
            
            Logger::info("Slow frames: %d (%.1f%%)", slowFrames, slowPercentage);
            Logger::info("Critical frames: %d (%.1f%%)", criticalFrames, criticalPercentage);
        }
        Logger::info("========================");
    }
    
    /**
     * @brief Réinitialise les statistiques
     */
    void reset() {
        m_frameHistory.clear();
        m_timers.clear();
        m_averageFrameTime = 0.0f;
        m_minFrameTime = 1000.0f;
        m_maxFrameTime = 0.0f;
        m_totalFrames = 0;
        m_totalClock.restart();
        Logger::debug("PerformanceMonitor reset");
    }

private:
    void updateStatistics(float frameTime) {
        // Mettre à jour min/max
        if (frameTime < m_minFrameTime) {
            m_minFrameTime = frameTime;
        }
        if (frameTime > m_maxFrameTime) {
            m_maxFrameTime = frameTime;
        }
        
        // Calculer la moyenne mobile
        if (m_frameHistory.size() > 1) {
            float sum = 0.0f;
            for (const auto& frame : m_frameHistory) {
                sum += frame.frameTime;
            }
            m_averageFrameTime = sum / m_frameHistory.size();
        } else {
            m_averageFrameTime = frameTime;
        }
    }
};

#endif // _PERFORMANCE_MONITOR_HPP_
