/**
 * @file SimpleConfig.hpp
 * @author Guillaume LEMONNIER
 * @brief Configuration simple pour les classes de transition
 * @version 1.0
 * @date 2025-07-26
 */

#ifndef SIMPLE_CONFIG_HPP
#define SIMPLE_CONFIG_HPP

namespace SimpleConfig {
    namespace Window {
        constexpr float WIDTH = 800.0f;
        constexpr float HEIGHT = 600.0f;
    }

    namespace Game {
        constexpr float PLAYER_SPEED = 100.0f;
        constexpr int SPRITE_SIZE = 32;
    }
}

#endif // SIMPLE_CONFIG_HPP
