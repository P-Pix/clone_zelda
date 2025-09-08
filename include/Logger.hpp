/**
 * @file Logger.hpp
 * @author Guillaume LEMONNIER
    static const char* getLevelColor(LogLevel level) {
        switch (level) {
            case LogLevel::LOG_DEBUG: return "\033[36m";    // Cyan
            case LogLevel::LOG_INFO: return "\033[32m";     // Green
            case LogLevel::LOG_WARNING: return "\033[33m";  // Yellow
            case LogLevel::LOG_ERROR: return "\033[31m";    // Red
            default: return "\033[0m";                      // Reset
        }
    } Système de logging améliore
 * @version 1.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

enum class LogLevel {
    LOG_DEBUG = 0,
    LOG_INFO = 1,
    LOG_WARNING = 2,
    LOG_ERROR = 3
};

class Logger {
private:
    static LogLevel m_minLevel;
    static std::ofstream m_logFile;
    static bool m_fileLogging;
    
    static std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()) % 1000;
        
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
        ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
        return ss.str();
    }
    
    static const char* getLevelString(LogLevel level) {
        switch (level) {
            case LogLevel::LOG_DEBUG: return "DEBUG";
            case LogLevel::LOG_INFO: return "INFO";
            case LogLevel::LOG_WARNING: return "WARN";
            case LogLevel::LOG_ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }
    
    static const char* getLevelColor(LogLevel level) {
        switch (level) {
            case LogLevel::LOG_DEBUG: return "\033[36m";    // Cyan
            case LogLevel::LOG_INFO: return "\033[32m";     // Green
            case LogLevel::LOG_WARNING: return "\033[33m";  // Yellow
            case LogLevel::LOG_ERROR: return "\033[31m";    // Red
            default: return "\033[0m";                      // Reset
        }
    }

public:
    static void setMinLevel(LogLevel level) {
        m_minLevel = level;
    }
    
    static void enableFileLogging(const std::string& filename) {
        if (m_logFile.is_open()) {
            m_logFile.close();
        }
        m_logFile.open(filename, std::ios::app);
        m_fileLogging = m_logFile.is_open();
    }
    
    static void disableFileLogging() {
        if (m_logFile.is_open()) {
            m_logFile.close();
        }
        m_fileLogging = false;
    }
    
    template<typename... Args>
    static void log(LogLevel level, const std::string& message, Args&&... args) {
        if (level < m_minLevel) return;
        
        // Format message if arguments provided
        std::string formattedMessage = message;
        if constexpr (sizeof...(args) > 0) {
            char buffer[1024];
            snprintf(buffer, sizeof(buffer), message.c_str(), args...);
            formattedMessage = std::string(buffer);
        }
        
        std::string timestamp = getCurrentTime();
        std::string levelStr = getLevelString(level);
        
        // Console output with colors
        std::cout << getLevelColor(level) 
                  << "[" << timestamp << "] "
                  << "[" << levelStr << "] "
                  << formattedMessage 
                  << "\033[0m" << std::endl;
        
        // File output (no colors)
        if (m_fileLogging && m_logFile.is_open()) {
            m_logFile << "[" << timestamp << "] "
                      << "[" << levelStr << "] "
                      << formattedMessage << std::endl;
            m_logFile.flush();
        }
    }
    
    // Convenience methods
    template<typename... Args>
    static void debug(const std::string& message, Args&&... args) {
        log(LogLevel::LOG_DEBUG, message, std::forward<Args>(args)...);
    }
    
    template<typename... Args>
    static void info(const std::string& message, Args&&... args) {
        log(LogLevel::LOG_INFO, message, std::forward<Args>(args)...);
    }
    
    template<typename... Args>
    static void warning(const std::string& message, Args&&... args) {
        log(LogLevel::LOG_WARNING, message, std::forward<Args>(args)...);
    }
    
    template<typename... Args>
    static void error(const std::string& message, Args&&... args) {
        log(LogLevel::LOG_ERROR, message, std::forward<Args>(args)...);
    }
    
    ~Logger() {
        if (m_logFile.is_open()) {
            m_logFile.close();
        }
    }
};

#endif // _LOGGER_HPP_
