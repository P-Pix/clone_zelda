/**
 * @file main.cpp
 * @author Guillaume LEMONNIER
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "include/GamesWindow.hpp"

using namespace std;

/// execution function
int main(void);

int main(void)
{
    GamesWindow Window;

    Window.limitFramerate(60);
    cout << "Window Open" << endl;

    while(Window.isRunning())
    {
        Window.controlWindow();
        Window.verificationWindow();
        Window.updateWindow();
    }

    cout << "Window Close" << endl;
    return 0;
}