/**
 * @file Chest.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__CHEST__)
#define __CHEST__

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "../Gain/Gain.hpp"

class Chest
{
    public:
        // Constructor / Destructor
            Chest();
            ~Chest();
        
        // Accessor
            sf::Sprite getSprite();
            bool getChest();
            int getValorRubis();
            int getValorLife();
            sf::Sprite getSpriteGain();
        
        // Function
            void generateChest();
            void openChest();
            void isGet();

    private:
        // Variable
            const char  *m_namechestclose = "skin/chestclose.png",
                        *m_namechestopen = "skin/chestopen.png";
            
            bool    m_spawnchest = false,
                    m_open = false;
            
            sf::Sprite m_Sprite;
            sf::Texture m_Texture;

            Gain m_Gain;
        
        // Function
            void loadSprite(const char *name);
};

#endif