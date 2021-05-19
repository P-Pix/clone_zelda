/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}