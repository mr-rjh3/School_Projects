#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>

using namespace std;
using namespace sf; //for graphics

int main()
{
    int speed = 200;
    int Spacing = 1;
    int size_p = 1;

    RenderWindow window(VideoMode(800,600),"SFML Works");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(speed); //sets the game loop to run 60 times per second

    RectangleShape Pix_0(Vector2f(1,1));
    vector<Vector2f> Pix_Pos;
    Pix_0.setPosition(400,200);
    Pix_Pos.push_back(Pix_0.getPosition());


    vector<RectangleShape> pix;

    pix.push_back(RectangleShape(Vector2f(size_p,size_p)));
    pix.back().setPosition(Pix_Pos.back());
    pix.back().setFillColor(Color(255 - Pix_0.getPosition().x, 255 -Pix_0.getPosition().y, 255));



    srand(time(0));

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop



            ///Random Movement

            for(int i = 0; i < speed; i++)
            {
                if(rand()%2 == 1)
                {
                    Pix_Pos.push_back(Pix_0.getPosition());
                    Pix_0.move(0,Spacing);
                }


                else
                {
                    Pix_Pos.push_back(Pix_0.getPosition());
                    Pix_0.move(0,-Spacing);
                }


                if(rand()%2 == 1)
                {
                    Pix_Pos.push_back(Pix_0.getPosition());
                    Pix_0.move(Spacing,0);
                }

                else
                {
                    Pix_Pos.push_back(Pix_0.getPosition());
                    Pix_0.move(-Spacing,0);
                }

                //for(int i = 0; i < Pix_Pos.size(); i++)
                //{
                    if(Pix_0.getPosition() != Pix_Pos.back())
                    {
                        pix.push_back(RectangleShape(Vector2f(1,1)));
                        pix.back().setPosition(Pix_Pos.back());
                        pix.back().setFillColor(Color(Pix_0.getPosition().x, Pix_0.getPosition().y, 255));
                    }
                //}


                ///Going off Screen
                if(Pix_0.getPosition().x >= 800)
                    Pix_0.setPosition(0, Pix_0.getPosition().y);
                else if(Pix_0.getPosition().x <= 0)
                    Pix_0.setPosition(800, Pix_0.getPosition().y);

                if(Pix_0.getPosition().y >= 600)
                    Pix_0.setPosition(Pix_0.getPosition().x, 0);
                else if(Pix_0.getPosition().y <= 0)
                    Pix_0.setPosition(Pix_0.getPosition().x, 600);
            }




        ///Position of All Pixels
        cout<<Pix_Pos.back().x<<" , "<<Pix_Pos.back().y<<endl;





    window.clear(); //clears the screen

    for(int i = 0; i < pix.size(); i++)
    {
        window.draw(pix[i]); //draws the circle to the video card
    }


    window.display();   //displays everything on the video card to the monitor
}   //ends the game loop

return 0;
}

