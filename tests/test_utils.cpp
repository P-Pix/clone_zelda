/**
 * @file test_utils.cpp
 * @author Guillaume LEMONNIER
 * @brief Tests unitaires basiques pour les utilitaires
 * @version 1.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include "../include/Utils.hpp"
#include "../include/Logger.hpp"
#include "../include/Config.hpp"

// Simple test framework
#define TEST(name) \
    void test_##name(); \
    void test_##name()

#define ASSERT_EQ(expected, actual) \
    do { \
        if ((expected) != (actual)) { \
            Logger::error("Assertion failed: expected %s, got %s", \
                         std::to_string(expected).c_str(), \
                         std::to_string(actual).c_str()); \
            assert(false); \
        } \
    } while(0)

#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            Logger::error("Assertion failed: expected true, got false"); \
            assert(false); \
        } \
    } while(0)

#define ASSERT_FALSE(condition) \
    do { \
        if (condition) { \
            Logger::error("Assertion failed: expected false, got true"); \
            assert(false); \
        } \
    } while(0)

#define ASSERT_NEAR(expected, actual, tolerance) \
    do { \
        if (std::abs((expected) - (actual)) > (tolerance)) { \
            Logger::error("Assertion failed: expected %f ± %f, got %f", \
                         (expected), (tolerance), (actual)); \
            assert(false); \
        } \
    } while(0)

// Tests pour les utilitaires
TEST(distance_calculation) {
    sf::Vector2f p1(0.0f, 0.0f);
    sf::Vector2f p2(3.0f, 4.0f);
    
    float dist = Utils::distance(p1, p2);
    ASSERT_NEAR(5.0f, dist, 0.001f);
    
    Logger::info("✅ Distance calculation test passed");
}

TEST(vector_normalization) {
    sf::Vector2f vec(3.0f, 4.0f);
    sf::Vector2f normalized = Utils::normalize(vec);
    
    float length = std::sqrt(normalized.x * normalized.x + normalized.y * normalized.y);
    ASSERT_NEAR(1.0f, length, 0.001f);
    
    // Test vecteur nul
    sf::Vector2f zero(0.0f, 0.0f);
    sf::Vector2f normalizedZero = Utils::normalize(zero);
    ASSERT_EQ(0.0f, normalizedZero.x);
    ASSERT_EQ(0.0f, normalizedZero.y);
    
    Logger::info("✅ Vector normalization test passed");
}

TEST(clamp_function) {
    ASSERT_EQ(5, Utils::clamp(10, 0, 5));
    ASSERT_EQ(0, Utils::clamp(-5, 0, 5));
    ASSERT_EQ(3, Utils::clamp(3, 0, 5));
    
    ASSERT_NEAR(2.5f, Utils::clamp(2.5f, 0.0f, 5.0f), 0.001f);
    
    Logger::info("✅ Clamp function test passed");
}

TEST(point_in_rect) {
    sf::FloatRect rect(10.0f, 10.0f, 50.0f, 30.0f);
    
    ASSERT_TRUE(Utils::pointInRect(sf::Vector2f(30.0f, 20.0f), rect));
    ASSERT_FALSE(Utils::pointInRect(sf::Vector2f(5.0f, 5.0f), rect));
    ASSERT_TRUE(Utils::pointInRect(sf::Vector2f(10.0f, 10.0f), rect)); // Border case
    
    Logger::info("✅ Point in rectangle test passed");
}

TEST(config_constants) {
    ASSERT_EQ(1024, Config::WINDOW_WIDTH);
    ASSERT_EQ(768, Config::WINDOW_HEIGHT);
    ASSERT_EQ(64, Config::SPRITE_SIZE);
    ASSERT_EQ(60, Config::FRAMERATE_LIMIT);
    
    Logger::info("✅ Config constants test passed");
}

// Test runner
void runAllTests() {
    Logger::info("🧪 Starting unit tests...");
    
    try {
        test_distance_calculation();
        test_vector_normalization();
        test_clamp_function();
        test_point_in_rect();
        test_config_constants();
        
        Logger::info("🎉 All tests passed successfully!");
        
    } catch (const std::exception& e) {
        Logger::error("❌ Test failed with exception: %s", e.what());
        throw;
    }
}

int main() {
    // Setup logging pour les tests
    Logger::setMinLevel(LogLevel::DEBUG);
    Logger::info("=== ZeldaLike Unit Tests ===");
    
    try {
        runAllTests();
        return 0;
    } catch (...) {
        Logger::error("Tests failed");
        return 1;
    }
}
