/**
 * @file GamesWindowAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GamesWindow.hpp"

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}