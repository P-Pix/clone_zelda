#include "GamesWindow.hpp"

void GamesWindow::modifiHeart()
{
    this -> m_Heart.updateHeart(m_Player.getLife(), m_Player.getMaxLife());
}