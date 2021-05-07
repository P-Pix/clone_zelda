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
        Window.tchecWindow();   // Multi test
        Window.updateWindow();  // Update Window
    }

    cout << "Window Close" << endl;
    return 0;
}