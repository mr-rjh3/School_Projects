#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>
#include <vector>

using namespace std;
using namespace sf; //for graphics





int main()
{

    srand(time(0));
    int counter=0, leti;
    vector<Text> txt;
    txt.push_back(sf::Text());
    Font fnt;

    string lets;
    fnt.loadFromFile("matrix.ttf");


    //txt.setFillColor(Color::Green);



    RenderWindow window(VideoMode(800,600),"SFML Works");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        cout<<txt.size()<<endl;
        //lets=(char)rand()%25+97;
        txt.push_back(sf::Text());

        //txt.back().setFillColor(Color::Green);
        //txt.back().setPosition(rand()%800,0);
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop


        //for(int i=0; i<txt.size();i++){
           // txt[i].move(0,1);
       // }
       //txt.move(0,1);


        counter++;

        window.clear(); //clears the screen
        //for(auto i:txt)window.draw(i);

        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}
