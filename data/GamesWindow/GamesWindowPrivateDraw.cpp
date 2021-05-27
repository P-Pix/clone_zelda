/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::drawSprite(sf::Sprite sprite)
{
    this -> m_Window -> draw(sprite);
}
void GamesWindow::drawText(sf::Text text)
{
    this -> m_Window -> draw(text);
}
void GamesWindow::allDrawWindow()
{
    drawVector(m_Player.getListSpriteHeart());

    drawMap();
    drawRubis();

    drawSprite(m_Mob1.getSprite());
    drawSprite(m_Player.getSprite());
    drawSword();
}
void GamesWindow::drawVector(std::vector<sf::Sprite> vector)
{
    for(int number = 0;  number < vector.size(); number ++)
    {
        drawSprite(vector[number]);
    }
}
void GamesWindow::drawSword()
{
    if(m_Sword.getExecution())
    {
        m_Sword.animateAttack();
        drawSprite(m_Sword.getSprite());
    }
}
void GamesWindow::drawRubis()
{
    drawSprite(m_Player.getLogoRubis());
    drawText(m_Player.getRubisHundred());
    drawText(m_Player.getRubisTen());
    drawText(m_Player.getRubisUnit());
}
void GamesWindow::drawMap()
{
    drawVector(m_Bloc.getListSprite());
    drawVector(m_Cavern.getListSprite());
    drawVector(m_Tree.getListSprite());
    drawVector(m_Ground.getListSprite());
}