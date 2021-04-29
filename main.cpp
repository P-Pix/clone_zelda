#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/GamesWindow.hpp"

int main()
{
    GamesWindow WINDOW;

    WINDOW.limitFramerate(60);  // nombre de fram limite
    std::cout << "Window Open" << std::endl;

    while(WINDOW.isRunning())
    {
        WINDOW.controlWindow(); // Controls User
        WINDOW.updateWindow();  // Update Window
        WINDOW.tchecWindow();   // Multi test
    }

    std::cout << "Window Close" << std::endl;
    return 0;
}