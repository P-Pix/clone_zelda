/**
 * @file Logger.cpp
 * @author Guillaume LEMONNIER
 * @brief Implémentation du système de logging
 * @version 1.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include "../include/Logger.hpp"

// Définitions des membres statiques
LogLevel Logger::m_minLevel = LogLevel::LOG_INFO;
std::ofstream Logger::m_logFile;
bool Logger::m_fileLogging = false;
