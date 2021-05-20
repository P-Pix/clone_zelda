#include "Sword.hpp"

void Sword::setOrientation()
{
    m_rotate -= 6;
    m_Sprite.setRotation(m_rotate);
}
void Sword::setBasicPosition()
{
    if(m_animationdown)
    {
        m_VectorAniamtor.x += 64;
        m_VectorAniamtor.y += 0 ;
    }
    else if(m_animationleft)
    {
        m_VectorAniamtor.x += 0;
        m_VectorAniamtor.y += 64;
    }
    else if(m_animationright)
    {
        m_VectorAniamtor.x += 0;
        m_VectorAniamtor.y -= 64;
    }
    else if(m_animationup)
    {
        m_VectorAniamtor.x -= 64;
        m_VectorAniamtor.y += 0;
    }
    m_Sprite.setPosition(m_VectorAniamtor);
}
void Sword::setPosition()
{
    if(m_animationdown)
    {
        m_VectorAniamtor.x += 4;
    }
    else if(m_animationleft)
    {
        m_VectorAniamtor.y += 4;
    }
    else if(m_animationright)
    {
        m_VectorAniamtor.y -= 4;
    }
    else if(m_animationup)
    {
        m_VectorAniamtor.x -= 4;
    }
    m_Sprite.setPosition(m_VectorAniamtor);
}
void Sword::endAnimation()
{
    m_aniamtionexe = false;
    m_animationdown = false;
    m_animationleft = false;
    m_animationright = false;
    m_animationup = false;
}