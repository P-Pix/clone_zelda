#if !defined(__HEART__)
#define __HEART__

#include <SFML/Graphics.hpp>
#include <list>

class Heart
{
    public:
        // Constructor / Destructor
            Heart();
            ~Heart();

        // Accessor
            std::list<sf::Sprite> getListHeart();

        // Function
            void updateHeart(int life, int maxlife);

    private:
        // Variable
            // iostream
                const char  *m_name0 = "skin/heart04.png",
                            *m_name1 = "skin/heart14.png",
                            *m_name2 = "skin/heart24.png",
                            *m_name3 = "skin/heart34.png",
                            *m_name4 = "skin/heart44.png";

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

                std::list<sf::Sprite> m_list[];
        
        // Function
            void listeHeartConstructor(int life);
            void heartConstructor(int partie);
            void loadSprite(sf::Texture texture, sf::Sprite sprite, const char *name);
            void loadTexture(sf::Texture texture, const char *name);

};

#endif