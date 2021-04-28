#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/Monster.hpp"
#include "data/GamesWindow.hpp"
#include "data/Wall.hpp"
#include "data/Ground.hpp"

int main()
{
    GamesWindow WINDOW;
    WINDOW.limitFramerate(60);

    std::cout << "Window Open" << std::endl;
    while(WINDOW.isRunning())
    {
        // Controls
        WINDOW.controlWindow();

        // Update Window
        WINDOW.updateWindow();
    }
    std::cout << "Window Close" << std::endl;
    return 0;
}