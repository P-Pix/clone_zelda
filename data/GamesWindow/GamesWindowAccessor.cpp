/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}