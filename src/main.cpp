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

/// execution function
int main(void);

int main(void) {
    __cplusplus;
    GamesWindow Window;

    Window.limitFramerate(60);
    std::cout << "Window \e[33mOpen" << std::endl;

    while (Window.isRunning()) {
        Window.controlWindow();
        Window.verificationWindow();
        Window.updateWindow();
    }

    std::cout << "\033[0mWindow \x1B[33mClose" << std::endl;
    return EXIT_SUCCESS;
}