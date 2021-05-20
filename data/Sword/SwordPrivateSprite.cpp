#include "Sword.hpp"

void Sword::loadTexture()
{
    if(!m_Texture.loadFromFile(m_picture))
    {
        std::cout << "error load " << m_picture << std::endl;
    }
}
void Sword::loadSprite()
{
    m_Sprite.setTexture(m_Texture);
}