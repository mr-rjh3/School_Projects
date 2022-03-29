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
    Font fnt;
    fnt.loadFromFile("American Captain.ttf");
    txt.setFont(fnt);
    txt.setString("Hello world");
    txt.setCharacterSize(60);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold);

    //CircleShape and textures

    int counter=0, counter2=0, x=0;
    CircleShape balls;  //create a circle object
    balls.setRadius(32.0);
    Texture ballt, paddlet, paddlet2;

    if (!ballt.loadFromFile("ball.png")){
        cout<<"ERROR"<<endl;
    }

    balls.setTexture(&ballt);
    //balls.setTextureRect(IntRect(0,0,64,64));






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
            balls.setTextureRect(IntRect(x, 0, 64, 64));
            x+=64;
        }


        window.clear(); //clears the screen
        window.draw(txt);
        window.draw(balls); //draws the circle to the video card
        window.display();   //displays everything on the video card to the monitor

            if (x>=764){
              x=0;
            }

        counter++;

    }   //ends the game loop

    return 0;
}
