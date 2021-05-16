#include "Heart.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#include <queue>
#include <list>
#include <vector>

// Consructor / Destructor

    // Constructor
        Heart::Heart()
        {
            initConstructor();
            //std::cout << "heart create " << this << std::endl;
        }

    // Destructor
        Heart::~Heart()
        {
            //std::cout << "heart delete " << this << std::endl;
        }

// Accessor

    // Sprite
        std::vector<sf::Sprite> Heart::getListSprite()
        {
            return m_List;
        }
        sf::Sprite Heart::getSprite(int number)
        {
            return m_List[number];
        }

// Function public

    // update life barre
        void Heart::updateHeart(int life, int maxlife)
        {
            int numberheart = life / 4,
                lastheart = life % 4,
                taillist = maxlife / 4,
                positionx = 0,
                positiony = 0,
                size = 0;

            this -> m_List.clear();

            std::vector<sf::Sprite> listelife(numberheart, m_S0Heart),
                                    listeheart(taillist, m_S0Heart);

            // full heart
            for(size = 0; size < listelife.size(); size ++)
            {
                this -> m_List.push_back(setSpritePosition(m_S4Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
                positionx ++;
                if(positionx == 10)
                {
                    positionx = 0;
                    positiony ++;
                }
            }
            
            // quart heart
            if(lastheart == 1)
            {
                this -> m_List.push_back(setSpritePosition(m_S1Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
            }
            else if(lastheart == 2)
            {
                this -> m_List.push_back(setSpritePosition(m_S2Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
            }
            else if(lastheart == 3)
            {
                this -> m_List.push_back(setSpritePosition(m_S3Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
            }

            // empty heart
            for(size = size; size < listeheart.size(); size ++)
            {
                this -> m_List.push_back(setSpritePosition(m_S0Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
                positionx ++;
                if(positionx == 10)
                {
                    positionx = 0;
                    positiony ++;
                }
            }
        }
        void Heart::setPosition(sf::Sprite sprite, sf::Vector2f position)
        {
            sprite.setPosition(position);
        }

// Function private

    // Position Heart
        sf::Sprite Heart::setSpritePosition(sf::Sprite sprite, sf::Vector2f position)
        {
            sprite.setPosition(position);
            return sprite;
        }

    // make sprite
        void Heart::initConstructor()
        {
            m_T0Heart.loadFromFile(m_name0);
            m_S0Heart.setTexture(m_T0Heart);

            m_T1Heart.loadFromFile(m_name1);
            m_S1Heart.setTexture(m_T1Heart);
            
            m_T2Heart.loadFromFile(m_name2);
            m_S2Heart.setTexture(m_T2Heart);

            m_T3Heart.loadFromFile(m_name3);
            m_S3Heart.setTexture(m_T3Heart);

            m_T4Heart.loadFromFile(m_name4);
            m_S4Heart.setTexture(m_T4Heart);
        }