#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>

using namespace std;
using namespace sf; //for graphics



//A function that limits value to the range minn..maxx
float clamp(float value,float minn, float maxx){
    if (value < minn) return minn;
    else if (value > maxx) return maxx;
    else return value;
}

//A Boolean function that takes in a Rectangle and a Circle and returns true if they are intersecting and false if not.
//The circles origin must be set to its center and the rectangles origin must be set to its top left corner

bool checkCollision (RectangleShape &R1,  CircleShape &C1) {

        // Find the closest point to the circle within the rectangle
        float closestX = clamp(C1.getPosition().x, R1.getPosition().x,R1.getPosition().x+R1.getSize().x );
        float closestY = clamp(C1.getPosition().y, R1.getPosition().y,R1.getPosition().y+R1.getSize().y );

        // Calculate the distance between the circle's center and this closest point
        float distanceX = C1.getPosition().x - closestX;
        float distanceY = C1.getPosition().y - closestY;

        // If the distance is less than the circle's radius, an intersection occurs
        float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
        if (distanceSquared < C1.getRadius()*C1.getRadius() ){
            return true;
        }
        else return false;
}



int main()
{
    //Text and Font
    Text txt;
    Text txt2;
    Text winner;
    Font fnt;
    fnt.loadFromFile("American Captain.ttf");
    int s1=0,s2=0;
    string score1 = "0";
    string score2 = "0";

    txt.setFont(fnt);
    txt.setCharacterSize(60);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold);
    txt.setPosition(350,0);

    txt2.setFont(fnt);
    txt2.setCharacterSize(60);
    txt2.setFillColor(Color::White);
    txt2.setStyle(Text::Bold);
    txt2.setPosition(420,0);

    winner.setFont(fnt);
    winner.setString(" ");
    winner.setCharacterSize(60);
    winner.setFillColor(Color::White);
    winner.setStyle(Text::Bold);

    //CircleShape, RectangleShape, and Textures
    int counter=0, x=0;
    int Bx=0, By=0, Bs=15, Ps=15, winpoint=5;
    CircleShape balls;
    balls.setRadius(20.0);
    balls.setOrigin(20,20);
    Texture ballt;
    ballt.loadFromFile("ball.png");
    balls.setTexture(&ballt);
    balls.setPosition(55,300);

    RectangleShape center(Vector2f(5,600));
    center.setPosition(395,0);

    RectangleShape paddle1(Vector2f(15,80));
    paddle1.setPosition(20,300);
    paddle1.setOrigin(7.5, 40);

    RectangleShape paddle2(Vector2f(15,80));
    paddle2.setPosition(780,300);
    paddle2.setOrigin(7.5, 40);

    //RenderWindow and Framerate
    RenderWindow window(VideoMode(800,600),"Riley's Pong Game");
    window.setFramerateLimit(60);


    ///Main game loop | Start

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //Ball Animation
        if(counter%2==0){
        balls.setTextureRect(IntRect(x, 0, 64, 64));
        x+=64;
    }
        if (x>=764){
              x=0;
            }
        counter++;

        //Ball Bounce
        if(balls.getPosition().y+20>=600){
            By=-Bs;
        }
        else if(balls.getPosition().y-20<=0){
            By=Bs;
        }

        //Ball Reset and Points
        else if(balls.getPosition().x>=800){
            s1++;
            score1=to_string(s1);
            Bx=0;
            By=0;
            balls.setPosition(55,300);
            paddle1.setPosition(20,300);
            paddle2.setPosition(780,300);
        }
        else if(balls.getPosition().x<=0){
            s2++;
            score2=to_string(s2);
            Bx=0;
            By=0;
            balls.setPosition(745,300);
            paddle1.setPosition(20,300);
            paddle2.setPosition(780,300);
        }

        //Move ball after point
        if(s1<winpoint && s2<winpoint){
            if (Bx==0 && By==0 && balls.getPosition().x==55){
                if(Keyboard::isKeyPressed(Keyboard::W)| Keyboard::isKeyPressed(Keyboard::S)){
                    Bx=Bs;
                    By=Bs;
                }
            }
            if (Bx==0 && By==0 && balls.getPosition().x==745){
                if(Keyboard::isKeyPressed(Keyboard::Up)| Keyboard::isKeyPressed(Keyboard::Down)){
                    Bx=-Bs;
                    By=-Bs;
                }
            }
        }

        //Paddle Bounce / Collision
        if (checkCollision(paddle1, balls)==true){
                Bx=Bs;
        }
        if (checkCollision(paddle2, balls)==true){
                Bx=-Bs;
        }

        //Paddle Movement
        if(s1<winpoint && s2<winpoint){
            if(paddle1.getPosition().y-40>=0){
                if (Keyboard::isKeyPressed(Keyboard::W)){
                    paddle1.move(0, -Ps);
                }
            }
            if(paddle1.getPosition().y+40<=600){
                if (Keyboard::isKeyPressed(Keyboard::S)){
                    paddle1.move(0, Ps);
                }
            }
            if(paddle2.getPosition().y-40>=0){
                if (Keyboard::isKeyPressed(Keyboard::Up)){
                    paddle2.move(0, -Ps);
                }
            }
            if(paddle2.getPosition().y+40<=600){
                if (Keyboard::isKeyPressed(Keyboard::Down)){
                    paddle2.move(0, Ps);
                }
            }
        }

        //Create Winner String
        if(s1>=winpoint && s2<winpoint){
            winner.setPosition(4,0);
            winner.setString("Winner");

        }
        if(s2>=winpoint && s1<winpoint){
            winner.setPosition(640,0);
            winner.setString("Winner");
        }

        //Drawing to Window
        txt.setString(score1);
        txt2.setString(score2);
        window.clear();
        window.draw(txt);
        window.draw(txt2);
        window.draw(winner);
        window.draw(center);
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(balls);
        window.display();

        //Ball Movement
        balls.move(Bx,By);

    }   ///Main game loop | End

    return 0;
}
