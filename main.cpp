#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/GamesWindow.hpp"

int main()
{
    GamesWindow Window;

    Window.limitFramerate(60);  // nombre de fram limite
    std::cout << "Window Open" << std::endl;

    while(Window.isRunning())
    {
        Window.controlWindow(); // Controls User
        Window.updateWindow();  // Update Window
        Window.tchecWindow();   // Multi test
    }

    std::cout << "Window Close" << std::endl;
    return 0;
}