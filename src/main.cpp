/**
 * @file main.cpp
 * @author Guillaume LEMONNIER
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "../include/GamesWindow.hpp"

using namespace std;

/// execution function
int main(void);

int main(void) {
    __cplusplus;
    GamesWindow Window;

    Window.limitFramerate(60);
    cout << "Window \x1B[33mOpen" << endl;

    while (Window.isRunning()) {
        Window.controlWindow();
        Window.verificationWindow();
        Window.updateWindow();
    }

    cout << "\x1B[0mWindow \x1B[33mClose" << endl;
    return EXIT_SUCCESS;
}