#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/GamesWindow.hpp"

using namespace std;

int main()
{
    GamesWindow Window;

    Window.limitFramerate(60);  // nombre de fram limite
    cout << "Window Open" << endl;

    while(Window.isRunning())
    {
        Window.controlWindow(); // Controls User
        Window.updateWindow();  // Update Window
        Window.tchecWindow();   // Multi test
    }

    cout << "Window Close" << endl;
    return 0;
}