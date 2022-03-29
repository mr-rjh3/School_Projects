#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>

using namespace std;
using namespace sf; //for graphics

int main()
{

    Texture t1;
    t1.loadFromFile("Drake.png");
    Sprite drake;
    drake.setTexture(t1);
    drake.setOrigin(99.5,154);
    drake.setPosition(400,300);
    float i=1;


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



        ///Moving Drake
        if(Keyboard::isKeyPressed(Keyboard::W)){
                drake.move(0,-5);
        }
        if(Keyboard::isKeyPressed(Keyboard::A)){
                drake.move(-5,0);

        }
        if(Keyboard::isKeyPressed(Keyboard::S)){
                drake.move(0,5);

        }
        if(Keyboard::isKeyPressed(Keyboard::D)){
                drake.move(5,0);
        }


        ///Rotating Drake
        if(Keyboard::isKeyPressed(Keyboard::Left)){
                drake.rotate(5);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
                drake.rotate(-5);
        }


        ///Changing Drake's Size
        if(Keyboard::isKeyPressed(Keyboard::Up)){
                i+=0.1;
                drake.setScale(i,i);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
                if(i>=0){
                    i-=0.1;
                    drake.setScale(i,i);
                }
        }


        window.clear(); //clears the screen
        window.draw(drake); //draws the circle to the video card
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}

