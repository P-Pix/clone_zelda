/**
 * @file main.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "data/GamesWindow/GamesWindow.hpp"

using namespace std;

int main()
{
    GamesWindow Window;

    Window.limitFramerate(60);          // nombre de fram limite
    cout << "Window Open" << endl;

    while(Window.isRunning())
    {
        Window.controlWindow();         // Controls User
        Window.verificationWindow();    // Multi test
        Window.updateWindow();          // Update Window
    }

    cout << "Window Close" << endl;
    return 0;
}