/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::drawElement(sf::Sprite sprite)
{
    this -> m_Window -> draw(sprite);
}
void GamesWindow::allDrawWindow()
{
    drawVector(m_Player.getListSpriteHeart());

    drawVector(m_Bloc.getListSprite());
    drawVector(m_Cavern.getListSprite());
    drawVector(m_Tree.getListSprite());
    drawVector(m_Ground.getListSprite());

    drawElement(m_Mob1.getSprite());
    drawElement(m_Player.getSprite());
    drawSword();
}
void GamesWindow::drawVector(std::vector<sf::Sprite> vector)
{
    for(int number = 0;  number < vector.size(); number ++)
    {
        drawElement(vector[number]);
    }
}
void GamesWindow::drawSword()
{
    if(m_Sword.getExecution())
    {
        m_Sword.animateAttack();
        drawElement(m_Sword.getSprite());
    }
}