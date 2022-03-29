#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{

    int counter=0,x=0;
    Texture t1;
    Sprite miner;
    t1.loadFromFile("miner.png");
    miner.setTexture(t1);


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

            if(counter%5==0){
                miner.setTextureRect(IntRect(x, 0, 60, 60));
                x+=60;
            }



        window.clear(); //clears the screen
        window.draw(miner); //draws the circle to the video card
        window.display();   //displays everything on the video card to the monitor

            if (x>=360){
              x=0;
            }

        counter++;
    }   //ends the game loop


    return 0;
}






