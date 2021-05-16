#include "GamesWindow.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}