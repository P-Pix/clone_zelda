#include "Ground.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Constructor / Destructor

    // Constructor
        Ground::Ground()
        {
            initSprite();
            //std::cout << "Ground create " << this << std::endl;
        }
        Ground::Ground(const char *name)
        {
            this -> m_name = name;
            initSprite();
            //std::cout << "Ground create " << this << std::endl;
        }

    // Destructor
        Ground::~Ground()
        {
            //std::cout << "Ground deete " << this << std::endl;
        }

// Accessor

    // Sprite
        std::vector<sf::Sprite> Ground::getListSprite()
        {
            return m_ListeSprite;
        }
        sf::Sprite Ground::getSprite()
        {
            return m_Sprite;
        }

    // Adress
        Ground* Ground::getAdress()
        {
            return this;
        }

// Function public

    // Position
        void Ground::setPosition(sf::Vector2f position)
        {
            this -> m_Sprite.setPosition(position);
        }
        void Ground::setPositionVector(std::vector<sf::Vector2f> vector)
        {
            int size = 0;
            this -> m_ListeSprite.clear();

            for(size = 0; size < vector.size(); size ++)
            {
                setPosition(vector[size]);
                m_ListeSprite.push_back(getSprite());
            }
        }

// Function private

    // make Sprite
        void Ground::initSprite()
        {
            loadTexture();
            loadSprite();
        }
        void Ground::loadSprite()
        {
            m_Sprite.setTexture(m_Texture);
        }
        void Ground::loadTexture()
        {
            if(!m_Texture.loadFromFile(m_name))
            {
                std::cout << "error image " << m_name << std::endl;
            }
        }