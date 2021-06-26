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

#ifndef _CHEST_HPP_
#define _CHEST_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Gain.hpp"

class Chest
{
    private:
        /// Variable
            const char  *m_namechestclose = "image/chestclose.png",
                        *m_namechestopen = "image/chestopen.png";
            
            bool    m_spawnchest = false,
                    m_open = false;
            
            sf::Sprite m_Sprite;
            sf::Texture m_Texture;

            Gain m_Gain;
        
        /// Function
            void loadSprite(const char *name);
    public:
        ////////////////////////////////////////
        
        /// Default Constructor
        Chest(void);

        /// Destructor
        ~Chest(void);

        ////////////////////////////////////////
        
        /// Accessor
        /// \return Chest sprite
        sf::Sprite getSprite(void);

        /// Accessor
        /// \return True if the chest there is a chest, False if not
        bool getChest(void);

        /// Accessor
        /// \return Rubis value : 0, 1, 5, 20
        int getValorRubis(void);

        /// Accessor
        /// \return Life value : 0, 4
        int getValorLife(void);

        /// Accessor
        /// \return 
        sf::Sprite getSpriteGain(void);
    
        void generateChest(void);
        void openChest(void);
        void isGet(void);
};

#endif