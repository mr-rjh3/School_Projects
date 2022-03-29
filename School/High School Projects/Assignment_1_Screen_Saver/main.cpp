#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>

using namespace std;
using namespace sf; //for graphics

int main()
{
    srand(time(0));

    vector<Vertex> v1;
    vector<int> nx, ny, nr, ng, nb, r, g, b, o;
    vector<int> x, y;

    Clock clo;
    Time t;

    RenderWindow window(VideoMode(800,600),"SFML Works");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    v1.push_back(Vertex());
    v1.back().position = Vector2f(400, 300);
    v1.back().color = Color::Black;


    for(int i = 1; i < 15; i++)
    {
        x.push_back(rand()%800);
        y.push_back(rand()%600);

        r.push_back(rand()%256);
        g.push_back(rand()%256);
        b.push_back(rand()%256);
        o.push_back(rand()%256);

        nx.push_back(1);
        ny.push_back(1);

        nr.push_back(1);
        ng.push_back(1);
        nb.push_back(1);

        v1.push_back(Vertex());
        v1.back().position = Vector2f(x.back(), y.back());
        v1.back().color = Color(r.back(), g.back(), b.back(), o.back());
    }

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        for(int i = 1; i < 15; i++)
    {
        if(x[i] < 0)
            nx[i] = 1;
        if(x[i] >= 800)
            nx[i] = -1;

        if(y[i] < 0)
            ny[i] = 1;
        if(y[i] >= 600)
            ny[i] = -1;

            x[i]+=nx[i];
            y[i]+=ny[i];
        v1[i].position = Vector2f(x[i], y[i]);
    }

            for(int i = 1; i < 15; i++)
            {
                if(r[i] < 100)
                    nr[i] = 1;
                if(r[i] >= 255)
                    nr[i] = -1;

                if(g[i] < 100)
                    ng[i] = 1;
                if(g[i] >= 255)
                    ng[i] = -1;

                if(b[i] < 100)
                    nb[i] = 1;
                if(b[i] >= 255)
                    nb[i] = -1;

                    r[i] += nr[i];
                    g[i] += ng[i];
                    b[i] += nb[i];

                v1[i].color = Color(r[i], g[i], b[i], o[i]);
            }
        clo.restart();

        window.clear(); //clears the screen
        window.draw(&v1[0], v1.size(), TriangleFan);
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}

