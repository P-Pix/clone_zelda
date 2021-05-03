#include "Monster.hpp"
#include <iostream>

// Constructor / Desttructor
    // Constructor
        Monster::Monster()
        {
            //std::cout << "Monster create " << this << std::endl;
            createPatern();
            initSprite();
        }

    // Destructeur
        Monster::~Monster()
        {
            //std::cout << "Monster delete " << this << std::endl;
        }

// Accessor
    // Sprite
        sf::Sprite Monster::getSprite()
        {
            return m_Sprite;
        }
        sf::Vector2f Monster::getPosition()
        {
            return m_Sprite.getPosition();
        }

    // power
        int Monster::getPower()
        {
            return m_power;
        }

// Function public
    // moove
        void Monster::moove()
        {
            m_Sprite.move(m_Patern[m_moveaction]);
            m_moveaction ++;
            if(m_moveaction == m_Patern.size())
            {
                m_moveaction = 0;
            }
        }

// Function private
    // Patern
        void Monster::createPatern()
        {
            for(int counter = 0; counter < 200; counter ++)
            {
                m_Patern.push_back(sf::Vector2f(-1.f, 0.f));
            }
            for(int counter = 0; counter < 200; counter ++)
            {
                m_Patern.push_back(sf::Vector2f(1.f, 0.f));
            }        
        }

    // make Sprite
        void Monster::initSprite()
        {
            loadTexture(m_monster);
            loadSprite();
            loadPosition();
        }
        void Monster::loadSprite()
        {
            m_Sprite.setTexture(m_Texture);
        }
        void Monster::loadTexture(const char *name)
        {
            if(!m_Texture.loadFromFile(name))
            {
                std::cout << "error image " << name << std::endl;
            }
        }
        void Monster::loadPosition()
        {
            m_Sprite.setPosition(sf::Vector2f(300.f, 300.f));
        }