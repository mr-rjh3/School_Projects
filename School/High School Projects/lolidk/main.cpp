#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>

using namespace std;
using namespace sf; //for graphics

int main()
{
    Sprite lolll;
    Texture boi;
    boi.loadFromFile("EWgkJjP.jpg");
    lolll.setTexture(boi);

    RenderWindow window(VideoMode(480,615),"Samual");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        window.clear(); //clears the screen
        window.draw(lolll); //draws the circle to the video card
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}

