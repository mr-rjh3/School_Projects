#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>
#include <ctime>

using namespace std;
using namespace sf; //for graphics

int main()
{
    int counter=1;
    int x[5000], y[5000];

    RectangleShape pixx(Vector2f(1,1));
    srand(time(0));



    RenderWindow window(VideoMode(800,600),"SFML Works");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        x[counter]=rand()%800;
        y[counter]=rand()%600;
        pixx.setPosition(x[counter],y[counter]);

        window.clear(); //clears the screen
        window.draw(pixx); //draws the circle to the video card
        window.display();   //displays everything on the video card to the monitor

        cout<<x[counter]<<", "<<y[counter]<<"  "<<counter<<endl;

        if(counter==5000) counter=0;
        counter++;

    }   //ends the game loop
    return 0;
}
