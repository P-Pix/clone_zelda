#include "Monster.hpp"

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