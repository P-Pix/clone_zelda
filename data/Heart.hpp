#if !defined(__HEART__)
#define __HEART__

#include <SFML/Graphics.hpp>

#include <vector>
#include <list>

class Heart
{
    public:
        // Constructor / Destructor
            Heart();
            ~Heart();

        // Accessor
            std::vector<sf::Sprite> getListSprite();
            sf::Sprite getSprite(int number);

        // Function
            void updateHeart(int life, int maxlife);
            void setPosition(sf::Sprite sprite, sf::Vector2f position);

    private:
        // Variable
            // basic
                const char  *m_name0 = "skin/heart04.png",
                            *m_name1 = "skin/heart14.png",
                            *m_name2 = "skin/heart24.png",
                            *m_name3 = "skin/heart34.png",
                            *m_name4 = "skin/heart44.png";
            
            // std
                std::vector<sf::Sprite> m_List;

            // SFML
                sf::Texture m_T0Heart,
                            m_T1Heart,
                            m_T2Heart,
                            m_T3Heart,
                            m_T4Heart;
                
                sf::Sprite  m_S0Heart,
                            m_S1Heart,
                            m_S2Heart,
                            m_S3Heart,
                            m_S4Heart;

        
        // Function
            sf::Sprite setSpritePosition(sf::Sprite sprite, sf::Vector2f position);
            void listeHeartConstructor(int life);
            void heartConstructor(int partie);
            void initConstructor();

};

#endif