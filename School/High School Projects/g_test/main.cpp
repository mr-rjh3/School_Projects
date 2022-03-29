#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
using namespace sf; //for graphics


int main()
{

    srand(time(0));
    int counter=0, counter2=0;
    vector<Text> txt;
    vector<RectangleShape> rec;
    int x=rand()%800;
    Font fnt;
    string lets;
    fnt.loadFromFile("matrix.ttf");

    RenderWindow window(VideoMode(800,600),"Matrix");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {


        ///*
        if(counter%1==0){
            cout<<rec.size()<<endl;
            rec.push_back(RectangleShape(Vector2f(5,5)));
            rec.back().setFillColor(Color::Green);
            rec.back().setPosition(rand()%800,0);
        }
        //*/

        /*
        if(counter%1==0){
            cout<<txt.size()<<endl;
            lets=(char)((rand()%25)+97);
            txt.push_back(Text(lets,fnt,15));
            txt.back().setFillColor(Color::Green);
            txt.back().setPosition(rand()%800,-15);
        }
        */

        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        counter++;

        window.clear(); //clears the screen

        ///*
        for(int i=0;i<rec.size();i++) {
            rec[i].move(0,1);
            window.draw(rec[i]);
            if(rec[i].getPosition().y>=600) {
                rec.erase(rec.begin()+i);
           }
        }
        //*/

        ///*
        for(int i=0;i<txt.size();i++) {
            txt[i].move(0,1);
            window.draw(txt[i]);
            lets=(char)rand()%25+97;
            if(counter%10==0){
                txt[rand()%txt.size()].setString(lets);
            }
            if(txt[i].getPosition().y>=600) {
                txt.erase(txt.begin()+i);
           }
        }
        //*/

        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}

