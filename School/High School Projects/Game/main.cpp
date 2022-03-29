#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
using namespace sf; //for graphics


int main()
{
    RenderWindow window(VideoMode(800,600),"SFML Works");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second
    Texture text;
    Texture text2;
    Texture backg;
    backg.loadFromFile("background.png");
    text.loadFromFile("ship.png");
    text2.loadFromFile("asteroid.png");
    Sprite player;
    Sprite background;
    background.setTexture(backg);
    player.setTexture(text);
    background.setScale(2,2);
    vector <RectangleShape> walls;
    vector <Sprite> badboi;
    vector <RectangleShape> bullet;
    vector <float> bangle;
    vector <CircleShape> bomb;
    bomb.push_back(CircleShape(5.0));
    bomb.back().setPosition(0,0);
    bomb.push_back(CircleShape(5.0));
    bomb.back().setPosition(0,10);
    bomb.push_back(CircleShape(5.0));
    bomb.back().setPosition(0,20);
    int x=4, y=4, counter=0, xt=0, yt=0;
    int bombi=3;
    float xdis, ydis, dis;
    float mdx,mdy;
    float delta;
    float speed = 5;
    int spn;
    float angle, eangle;
    int t1;
    bool die, wall = false;
    srand(time(0));
    Clock clo;
    Time t;

    vector <int> bx;
    vector <int> by;
    player.setPosition(400,300);
    player.setOrigin(95,95);
    player.setScale(0.15,0.15);




    ///Walls
    walls.push_back(RectangleShape(Vector2f(750,6)));
    walls.back().setOrigin(375,3);
    walls.back().setPosition(400,580);

    walls.push_back(RectangleShape(Vector2f(750,6)));
    walls.back().setOrigin(375,3);
    walls.back().setPosition(400,20);

    walls.push_back(RectangleShape(Vector2f(6,566)));
    walls.back().setOrigin(3,283);
    walls.back().setPosition(28,300);

    walls.push_back(RectangleShape(Vector2f(6,566)));
    walls.back().setOrigin(3,283);
    walls.back().setPosition(772,300);


    ///Entrances
    walls.push_back(RectangleShape(Vector2f(200,6)));
    walls.back().setOrigin(100,3);
    walls.back().setPosition(400,580);
    walls.back().setFillColor(Color::Black);

    walls.push_back(RectangleShape(Vector2f(200,6)));
    walls.back().setOrigin(100,3);
    walls.back().setPosition(400,20);
    walls.back().setFillColor(Color::Black);

    walls.push_back(RectangleShape(Vector2f(6,200)));
    walls.back().setOrigin(3,100);
    walls.back().setPosition(28,300);
    walls.back().setFillColor(Color::Black);

    walls.push_back(RectangleShape(Vector2f(6,200)));
    walls.back().setOrigin(3,100);
    walls.back().setPosition(772,300);
    walls.back().setFillColor(Color::Black);

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        t=clo.getElapsedTime();
        t1=t.asMilliseconds();



        if(die==false)
        {
            if(counter%15==0)
            {

                badboi.push_back(Sprite(text2, IntRect(xt, yt, 128, 128)));
                badboi.back().setScale(0.3, 0.3);

                spn=rand()%4;
                cout<<spn<<endl;
                if(spn==0)
                    badboi.back().setPosition(5,rand()%220+230);
                if(spn==1)
                    badboi.back().setPosition(rand()%320+230,595);
                if(spn==2)
                    badboi.back().setPosition(795,rand()%220+230);
                if(spn==3)
                    badboi.back().setPosition(rand()%320+230,5);

            }

            if(Keyboard::isKeyPressed(Keyboard::D))
            {
                if (player.getPosition().x + player.getGlobalBounds().width/2 >= 772)
                    player.setPosition(player.getPosition().x - x, player.getPosition().y);
                player.move(x,0);
            }

            if(Keyboard::isKeyPressed(Keyboard::A))
            {
                if (player.getPosition().x - player.getGlobalBounds().width/2 <= 28)
                    player.setPosition(player.getPosition().x + x, player.getPosition().y);
                player.move(-x,0);

            }

            if(Keyboard::isKeyPressed(Keyboard::W))
            {
                if (player.getPosition().y - player.getGlobalBounds().height/2 <= 20)
                    player.setPosition(player.getPosition().x, player.getPosition().y + y);
                player.move(0,-y);

            }

            if(Keyboard::isKeyPressed(Keyboard::S))
            {
                if (player.getPosition().y + player.getGlobalBounds().height/2 >= 580)
                    player.setPosition(player.getPosition().x, player.getPosition().y - y);
                player.move(0,y);

            }


            if(Keyboard::isKeyPressed(Keyboard::Space) && bombi > 0)
            {
                if(counter%10==0)
                {
                    bombi--;
                    bomb.pop_back();
                    badboi.clear();
                }
            }


            if(Mouse::isButtonPressed(Mouse::Left))
            {
                if(counter%15==0)
                {
                    bullet.push_back(RectangleShape(Vector2f(5,10)));
                    bullet.back().setPosition(player.getPosition().x,player.getPosition().y);
                    bullet.back().setOrigin(2.5,5);
                    bullet.back().setRotation(player.getRotation());
                    bangle.push_back(float(atan2(Mouse::getPosition(window).y - player.getPosition().y, Mouse::getPosition(window).x - player.getPosition().x)));


                }


            }
            counter++;


            window.clear(); //clears the screen
            window.draw(background);

            for(int i=0; i < walls.size(); i++)
            {
                window.draw(walls[i]);
            }

            for(int i=0; i < bomb.size(); i++)
            {
                window.draw(bomb[i]);
            }

            mdx=Mouse::getPosition(window).x - player.getPosition().x;
            mdy=Mouse::getPosition(window).y - player.getPosition().y;
            angle=(-atan2(-mdx, -mdy)) * 180 / 3.14;
            player.setRotation(angle);

            delta = clo.restart().asSeconds() * 60;

            window.draw(player);
            for(int i=0; i<bullet.size(); i++)
            {

                bullet[i].move(10*cos(bangle[i]),10*sin(bangle[i]));

                for(int i2=0; i2<badboi.size(); i2++)
                {

                    if(bullet[i].getGlobalBounds().intersects(badboi[i2].getGlobalBounds()))
                    {
                        badboi.erase(badboi.begin()+i2);
                    }
                }
                window.draw(bullet[i]);
            }


            for(int i=0; i<badboi.size(); i++)
            {

                if (player.getGlobalBounds().intersects(badboi[i].getGlobalBounds()))
                {
                    //die=true;
                }

                xdis = player.getPosition().x - badboi[i].getPosition().x;
                ydis = player.getPosition().y - badboi[i].getPosition().y;
                /*eangle=(atan2((player.getPosition().y - badboi[i].getPosition().y), (player.getPosition().x - badboi[i].getPosition().x))) * 180 / 3.14;
                if (xdis < 0)
                    badboi[i].move(1.5*cos(eangle), 1.5*sin(eangle));
                if (xdis >= 0)
                    badboi[i].move(1.5*cos(eangle+180), 1.5*sin(eangle+180));

                    */
                    if(xdis > 0)

                if(counter%5==0)
                {
                    badboi[i].setTextureRect(IntRect(xt, yt, 128, 128));
                    xt+=128;
                    if(xt == 1024)
                    {
                        xt=0;
                        yt+=128;
                        if(yt == 1024)
                        {
                            yt=0;
                            xt=0;
                        }

                    }
                }
                window.draw(badboi[i]);
            }
        }
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop


    return 0;

}

