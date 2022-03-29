#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf; //for graphics

///Changes Image used for textures
Texture bob(Time t, String str0, String str1)
{
    Texture texture;
    if(t.asMilliseconds()>=0 && t.asMilliseconds()<300)
        texture.loadFromFile(str0);
    else if (t.asMilliseconds()>=300 && t.asMilliseconds()<600)
        texture.loadFromFile(str1);
    else
        texture.loadFromFile(str0);
    return texture;
}

///The same as above but quiker for enemy when they are about to move
Texture attack(Time t, String str0, String str1)
{
    Texture texture;
    if(t.asMilliseconds()>=0 && t.asMilliseconds()<50)
        texture.loadFromFile(str0);
    else if (t.asMilliseconds()>=50 && t.asMilliseconds()<100)
        texture.loadFromFile(str1);
    else
        texture.loadFromFile(str0);
    return texture;
}

int main()
{

    int h = 0;
    int health = 36;
    int hdamage = 3;
    int edamage = 3;
    int x = 0;
    int h2 = 2;

    Texture wallt;
    wallt.loadFromFile("wall.png");
    Texture floort;
    floort.loadFromFile("floor.png");
    vector<vector<int> > grid(100, vector<int>(100));
    vector<vector<RectangleShape> > flr(100, vector<RectangleShape>(100));
    ifstream infile;
    infile.open("Dungeon_full.txt");
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            infile>>grid[i][j];
            ///Brick Floor
            if(grid[i][j] == 149)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(16, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick Left
            else if(grid[i][j] == 148)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(0, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick top left
            else if(grid[i][j] == 127)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(0, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///brick top
            else if(grid[i][j] == 128)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(16, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///brick top right
            else if(grid[i][j] == 129)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(32, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///brick right
            else if(grid[i][j] == 150)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(32, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick bottom right
            else if(grid[i][j] == 171)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(32, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///brick bottom
            else if(grid[i][j] == 170)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(16, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///brick bottom left
            else if(grid[i][j] == 169)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(0, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick all sides
            else if(grid[i][j] == 132)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(80, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick bot/top
            else if(grid[i][j] == 153)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(80, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick Left bot/top
            else if(grid[i][j] == 152)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(64, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Brick right bot/top
            else if(grid[i][j] == 154)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(96, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///Grass patch
            else if(grid[i][j] == 139)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(192, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///full grass
            else if(grid[i][j] == 156)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(128, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt left
            else if(grid[i][j] == 155)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(112, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt top left
            else if(grid[i][j] == 134)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(112, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt top
            else if(grid[i][j] == 135)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(128, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt top right
            else if(grid[i][j] == 136)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(144, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt right
            else if(grid[i][j] == 157)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(144, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt bottom right
            else if(grid[i][j] == 178)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(144, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt bottom
            else if(grid[i][j] == 177)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(128, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt bottom left
            else if(grid[i][j] == 176)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(112, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt top left and right
            else if(grid[i][j] == 137)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(160, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt bot right left
            else if(grid[i][j] == 179)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(160, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///grass dirt right top bot
            else if(grid[i][j] == 161)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(208, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }

            ///black brick
            else if(grid[i][j] == 275)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(16, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick left
            else if(grid[i][j] == 274)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(0, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick right
            else if(grid[i][j] == 276)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(32, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick top
            else if(grid[i][j] == 254)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(16, 192, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick bot
            else if(grid[i][j] == 296)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(16, 224, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick left top
            else if(grid[i][j] == 253)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(0, 192, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick left bot
            else if(grid[i][j] == 295)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(0, 224, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick right top
            else if(grid[i][j] == 255)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(32, 192, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick right bot
            else if(grid[i][j] == 297)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(32, 224, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick top bot
            else if(grid[i][j] == 279)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(80, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick all sides
            else if(grid[i][j] == 258)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(80, 192, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick left right
            else if(grid[i][j] == 277)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(48, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick bot top right
            else if(grid[i][j] == 280)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(96, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///black brick bot top left
            else if(grid[i][j] == 278)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&floort);
                flr[i][j].setTextureRect(IntRect(64, 208, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }



            ///Left down up wall
            else if(grid[i][j] == 965)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(80, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///right down up wall
            else if(grid[i][j] == 963)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(48, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }

            ///dirty wall
            else if(grid[i][j] == 1200)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(0, 256, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }

            ///top right cracked wall
            else if(grid[i][j] == 1189)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(144, 240, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///bot left cracked wall
            else if(grid[i][j] == 1227)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(112, 272, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }

            ///top left cracked wall
            else if(grid[i][j] == 1187)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(112, 240, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///top/bot cracked wall
            else if(grid[i][j] == 1188)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(128, 240, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///bot right cracked wall
            else if(grid[i][j] == 1229)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(144, 272, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///side cracked wall
            else if(grid[i][j] == 1207)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(112, 256, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }

            ///Side wall
            else if(grid[i][j] == 960)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(0, 112, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///top/bottom wall
            else if(grid[i][j] == 941)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(16, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///top left wall
            else if(grid[i][j] == 940)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(0, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///top right wall
            else if(grid[i][j] == 942)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(32, 96, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///bottom right wall
            else if(grid[i][j] == 982)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(32, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
            ///bottom left wall
            else if(grid[i][j] == 980)
            {
                flr[i][j].setSize(Vector2f(16,16));
                flr[i][j].setTexture(&wallt);
                flr[i][j].setTextureRect(IntRect(0, 128, 16, 16));
                flr[i][j].setScale(2, 2);
                flr[i][j].setPosition(j*32, i*32);
            }
        }
    }

    View view1;
    int zoomx = 800, zoomy = 608;
    view1.setSize(zoomx, zoomy);
    view1.setCenter(1584, 2895);
    RectangleShape viewer;
    RectangleShape secret;
    secret.setSize(Vector2f(320, 352));
    secret.setPosition(320, 1376);

    SoundBuffer damagebuff;
    damagebuff.loadFromFile("damage1.wav");
    Sound damage;
    damage.setBuffer(damagebuff);

    SoundBuffer swordbuff;
    swordbuff.loadFromFile("sword3.wav");
    Sound sword;
    sword.setBuffer(swordbuff);

    SoundBuffer errorbuff;
    errorbuff.loadFromFile("error3.wav");
    Sound error;
    error.setBuffer(errorbuff);

    SoundBuffer keybuff;
    keybuff.loadFromFile("button4.wav");
    Sound key;
    key.setBuffer(keybuff);

    SoundBuffer doorbuff;
    doorbuff.loadFromFile("neutral1.wav");
    Sound door;
    door.setBuffer(doorbuff);

    Font fnt;
    fnt.loadFromFile("pixeled.ttf");
    Text times;
    Text keynum;
    times.setFont(fnt);
    times.setString("x");
    times.setCharacterSize(8);
    times.setPosition(view1.getCenter().x - 328, view1.getCenter().y - 296);
    int keyn = 0;
    keynum.setFont(fnt);
    keynum.setCharacterSize(8);
    keynum.setPosition(view1.getCenter().x - 315, view1.getCenter().y - 295);
    RectangleShape tbar;
    tbar.setSize(Vector2f(97, 16));
    tbar.setFillColor(Color::Black);
    tbar.setPosition(view1.getCenter().x - 400, view1.getCenter().y - 300);
    Texture t1;
    Texture t2;
    Texture doorclose;
    Texture dooropen;
    Texture Dungeont;
    Texture keyt;
    Texture Slasht;
    Texture healtht;
    doorclose.loadFromFile("door0.png");
    dooropen.loadFromFile("door1.png");
    Dungeont.loadFromFile("dungeon full.png");
    Slasht.loadFromFile("slash.png");
    keyt.loadFromFile("key.png");
    Sprite keyi;
    vector<Sprite> doors;
    vector <Sprite> keys;
    keyi.setTexture(keyt);
    keyi.setTextureRect(IntRect(0, 0, 16, 16));
    keyi.setPosition(view1.getCenter().x - 345, view1.getCenter().y - 300);
    Sprite hero;
    RectangleShape waller;
    Sprite Slash;
    Sprite dungeon;
    dungeon.setTexture(Dungeont);
    dungeon.setScale(2, 2);
    Slash.setTexture(Slasht);
    Slash.setTextureRect(IntRect(1152, 0, 192, 192));
    Slash.setScale(.3,.3);
    vector <Sprite> enemy;
    vector <int> ehealth;
    vector <RectangleShape> ewaller;
    vector <Sprite> healths;
    hero.setScale(2,2);
    hero.setPosition(1568, 2848);
    Clock clo1;
    Clock clo2;
    Clock clo3;
    Clock clo4;
    Clock clo5;
    Clock clo6;
    Clock clo7;
    Clock clo8;
    Time t;
    bool pos1, pos2, pos3, pos4, mov, mov2, mov3, mov4;
    bool slashb;
    bool death;
    bool key_have;
    vector <bool> door_open;

    ///Hearts
    healths.push_back(Sprite(healtht, IntRect(0, 16, 16, 16)));
    healths.back().setPosition(view1.getCenter().x - 400, view1.getCenter().y - 300);
    healths.push_back(Sprite(healtht, IntRect(0, 16, 16, 16)));
    healths.back().setPosition(view1.getCenter().x - 384, view1.getCenter().y - 300);
    healths.push_back(Sprite(healtht, IntRect(0, 16, 16, 16)));
    healths.back().setPosition(view1.getCenter().x - 368, view1.getCenter().y - 300);

    ///Doors
    doors.push_back(Sprite(doorclose, IntRect(16, 16, 16, 16)));
    doors.back().setScale(2, 2);
    doors.back().setPosition(65*32, 72*32);
    door_open.push_back(false);

    ///Enemy Spawns
    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(112, 0, 16, 16));
    enemy.back().setPosition(928, 1632);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(704, 1696);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(960, 1792);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(112, 0, 16, 16));
    enemy.back().setPosition(704, 1888);


    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(2336, 2240);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(2432, 2240);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(112, 0, 16, 16));
    enemy.back().setPosition(2336, 2112);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(2432, 2112);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(2336, 1984);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(112, 0, 16, 16));
    enemy.back().setPosition(2432, 1984);


    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(2272, 1152);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(2272, 1024);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(2496, 1024);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(2496, 1152);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(2336, 1088);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(2368, 1056);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(96, 16, 16, 16));
    enemy.back().setPosition(2400, 1056);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(2432, 1088);


    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(192, 992);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(288, 992);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(416, 992);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(512, 992);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(192, 1088);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(256, 1088);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(256, 1056);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(256, 1120);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(448, 1088);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(448, 1056);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(448, 1120);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(544, 1088);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(192, 1184);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(288, 1184);

    enemy.push_back(Sprite(t2));
    ehealth.push_back(9);
    ewaller.push_back(RectangleShape());
    enemy.back().setScale(2,2);
    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
    enemy.back().setPosition(416, 1184);

//    enemy.push_back(Sprite(t2));
//    ehealth.push_back(9);
//    ewaller.push_back(RectangleShape());
//    enemy.back().setScale(2,2);
//    enemy.back().setTextureRect(IntRect(32, 64, 16, 16));
//    enemy.back().setPosition(512, 1184);

    ///Keys
    keys.push_back(Sprite(keyt));
    keys.back().setScale(2,2);
    keys.back().setTextureRect(IntRect(0, 0, 16, 16));
    keys.back().setPosition(42*32, 49*32);

    keys.push_back(Sprite(keyt));
    keys.back().setScale(2,2);
    keys.back().setTextureRect(IntRect(0, 0, 16, 16));
    keys.back().setPosition(1632, 2880);

    keys.push_back(Sprite(keyt));
    keys.back().setScale(2,2);
    keys.back().setTextureRect(IntRect(0, 0, 16, 16));
    keys.back().setPosition(1600, 2880);




    RenderWindow window(VideoMode(800,608),"SFML Works");  //creates a window on the screen that is 800 by 600
    //window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape) && death != true)     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        t=clo8.getElapsedTime();
        if(Keyboard::isKeyPressed(Keyboard::Z) && t.asMilliseconds()>=200)
        {
            zoomx+=32;
            zoomy+=32;
            clo8.restart();
        }
        t=clo7.getElapsedTime();
        if(Keyboard::isKeyPressed(Keyboard::X) && t.asMilliseconds()>=200)
        {
            zoomx-=32;
            zoomy-=32;
            clo7.restart();
        }
        view1.setSize(zoomx, zoomy);
        ///Bob for Player
        t=clo1.getElapsedTime();
        t1=bob(t, "player0.png", "player1.png");
        if(t.asMilliseconds()>=600)
            clo1.restart();
        hero.setTexture(t1);
        hero.setTextureRect(IntRect(16, 176, 16, 16));

        ///Hero Movement
        t=clo2.getElapsedTime();
        if(Keyboard::isKeyPressed(Keyboard::Up) && t.asMilliseconds()>=200 && pos1 == false)
        {
            view1.move(0, -32);
            times.move(0, -32);
            tbar.move(0, -32);
            keyi.move(0, -32);
            keynum.move(0, -32);
            for(int i = 0; i < healths.size(); i++)
                healths[i].move(0, -32);
            hero.move(0, -32);
            for(int i = 0; i < enemy.size(); i++)
            {
                ///Hero Damages Enemy
                if(enemy[i].getPosition() == hero.getPosition())
                {
                    ehealth[i] -= hdamage;
                    slashb = true;
                    sword.play();
                    Slash.setPosition(enemy[i].getPosition().x - 15, enemy[i].getPosition().y - 15);
                    view1.move(0, 32);
                    times.move(0, 32);
                    tbar.move(0, 32);
                    keyi.move(0, 32);
                    keynum.move(0, 32);
                    for(int i = 0; i < healths.size(); i++)
                        healths[i].move(0, 32);
                    hero.move(0, 32);
                }
            }
            clo2.restart();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left) && t.asMilliseconds()>=200 && pos2 == false)
        {
            view1.move(-32, 0);
            times.move(-32, 0);
            tbar.move(-32, 0);
            keyi.move(-32, 0);
            keynum.move(-32, 0);
            for(int i = 0; i < healths.size(); i++)
                healths[i].move(-32, 0);
            hero.move(-32, 0);
            for(int i = 0; i < enemy.size(); i++)
            {
                ///Hero Damages Enemy
                if(enemy[i].getPosition() == hero.getPosition())
                {
                    ehealth[i] -= hdamage;
                    slashb = true;
                    sword.play();
                    Slash.setPosition(enemy[i].getPosition().x - 15, enemy[i].getPosition().y - 15);
                    view1.move(32, 0);
                    times.move(32, 0);
                    tbar.move(32, 0);
                    keyi.move(32, 0);
                    keynum.move(32, 0);
                    for(int i = 0; i < healths.size(); i++)
                        healths[i].move(32, 0);
                    hero.move(32, 0);
                }
            }
            clo2.restart();
        }
        if(Keyboard::isKeyPressed(Keyboard::Down) && t.asMilliseconds()>=200 && pos3 == false)
        {
            view1.move(0, 32);
            times.move(0, 32);
            tbar.move(0, 32);
            keyi.move(0, 32);
            keynum.move(0, 32);
            for(int i = 0; i < healths.size(); i++)
                healths[i].move(0, 32);
            hero.move(0, 32);
            for(int i = 0; i < enemy.size(); i++)
            {
                ///Hero Damages Enemy
                if(enemy[i].getPosition() == hero.getPosition())
                {
                    ehealth[i] -= hdamage;
                    slashb = true;
                    sword.play();
                    Slash.setPosition(enemy[i].getPosition().x - 15, enemy[i].getPosition().y - 15);
                    view1.move(0, -32);
                    times.move(0, -32);
                    tbar.move(0, -32);
                    keyi.move(0, -32);
                    keynum.move(0, -32);
                    for(int i = 0; i < healths.size(); i++)
                        healths[i].move(0, -32);
                    hero.move(0, -32);
                }
            }
            clo2.restart();
        }
        if(Keyboard::isKeyPressed(Keyboard::Right) && t.asMilliseconds()>=200 && pos4 == false)
        {
            view1.move(32, 0);
            times.move(32, 0);
            tbar.move(32, 0);
            keyi.move(32, 0);
            keynum.move(32, 0);
            for(int i = 0; i < healths.size(); i++)
                healths[i].move(32, 0);
            hero.move(32, 0);
            for(int i = 0; i < enemy.size(); i++)
            {
                ///Hero Damages Enemy
                if(enemy[i].getPosition() == hero.getPosition())
                {
                    ehealth[i] -= hdamage;
                    slashb = true;
                    sword.play();
                    Slash.setPosition(enemy[i].getPosition().x - 15, enemy[i].getPosition().y - 15);
                    view1.move(-32, 0);
                    times.move(-32, 0);
                    tbar.move(-32, 0);
                    keyi.move(-32, 0);
                    keynum.move(-32, 0);
                    for(int i = 0; i < healths.size(); i++)
                        healths[i].move(-32, 0);
                    hero.move(-32, 0);
                }
            }
            clo2.restart();
        }
        if(slashb)
        {
            t=clo6.getElapsedTime();
            if(t.asMilliseconds() >= 70)
            {
                Slash.setTextureRect(IntRect(x, 0, 192, 192));
                x += 192;
                clo6.restart();
            }
            if(x >= 1152)
            {
                x = 0;
                slashb = false;
            }
        }
        window.clear(); //clears the screen

        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                infile>>grid[i][j];

                if(flr[i][j].getPosition().x - hero.getPosition().x < 432 && flr[i][j].getPosition().x - hero.getPosition().x  > -432 && flr[i][j].getPosition().y - hero.getPosition().y  < 368 && flr[i][j].getPosition().y - hero.getPosition().y  > -368)
                {
                    if(!flr[i][j].getGlobalBounds().intersects(secret.getGlobalBounds()) || hero.getGlobalBounds().intersects(secret.getGlobalBounds()))
                        window.draw(flr[i][j]);
                }
                for(int i = 0; i < enemy.size(); i++)
                {
                    if(enemy[i].getPosition().x - hero.getPosition().x < 432 && enemy[i].getPosition().x - hero.getPosition().x  > -432 && enemy[i].getPosition().y - hero.getPosition().y  < 368 && enemy[i].getPosition().y - hero.getPosition().y  > -368)
                        window.draw(enemy[i]);
                        ewaller[i].setPosition(enemy[i].setPosition());
                }
                for(int i = 0; i < keys.size(); i++)
                {
                    if(!keys[i].getGlobalBounds().intersects(secret.getGlobalBounds()))
                        window.draw(keys[i]);
                }

                if(grid[i][j] == 941 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 960 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 940 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 942 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 982 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 980 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 965 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 963 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1227 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1189 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1229 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1229 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1188 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1187 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
                else if(grid[i][j] == 1207 && flr[i][j].getGlobalBounds().intersects(hero.getGlobalBounds()))
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }

                for(int i = 0; i < enemy.size(); i++)
                {
                if(grid[i][j] == 941 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 960 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 940 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 942 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                   enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 982 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 980 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 965 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 963 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1227 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1189 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1229 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()));
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1229 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1188 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1187 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                   enemy[i].setPosition(ewaller[i].getPosition());

                else if(grid[i][j] == 1207 && flr[i][j].getGlobalBounds().intersects(enemy[i].getGlobalBounds()))
                    enemy[i].setPosition(ewaller[i].getPosition());
                }

            }
        }
        for(int i = 0; i < doors.size(); i++)
        {
            window.draw(doors[i]);
            if(!door_open[i] && !key_have)
            {
                if(doors[i].getPosition() == hero.getPosition())
                {
                    error.play();
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                }
            }
            if(doors[i].getPosition() == hero.getPosition() && key_have)
            {
                if(!door_open[i])
                {
                    hero.setPosition(waller.getPosition());
                    view1.setCenter(viewer.getPosition());
                    doors[i].setTexture(dooropen);
                    door.play();
                    keyn--;
                }
                door_open[i] = true;
            }
        }
        keyi.setPosition(view1.getCenter().x - 345, view1.getCenter().y - 300);
        keynum.setPosition(view1.getCenter().x - 315, view1.getCenter().y - 295);
        tbar.setPosition(view1.getCenter().x - 400, view1.getCenter().y - 300);
        times.setPosition(view1.getCenter().x - 328, view1.getCenter().y - 296);
        window.setView(view1);
        window.draw(hero);
        for(int i = 0; i < enemy.size(); i++)
        {
            if(enemy[i].getPosition().x - hero.getPosition().x < 640 && enemy[i].getPosition().x - hero.getPosition().x  > -640 && enemy[i].getPosition().y - hero.getPosition().y  < 640 && enemy[i].getPosition().y - hero.getPosition().y  > -640)
            {
                ///Bob for enemy
                t=clo3.getElapsedTime();
                t2=bob(t, "demon0.png", "demon1.png");
                if(t.asMilliseconds()>=600)
                    clo3.restart();
            }
            if(enemy[i].getPosition().x - hero.getPosition().x < 320 && enemy[i].getPosition().x - hero.getPosition().x  > -320 && enemy[i].getPosition().y - hero.getPosition().y  < 320 && enemy[i].getPosition().y - hero.getPosition().y  > -320)
            {
                ///Enemy Telegraphing
                t=clo4.getElapsedTime();
                if(hero.getPosition().y > enemy[i].getPosition().y && t.asMilliseconds()>=1000)
                {
                    t=clo6.getElapsedTime();
                    t2=attack(t, "demon0.png", "demon1.png");
                    if(t.asMilliseconds()>=100)
                        clo6.restart();
                    t=clo4.getElapsedTime();
                }
                if(hero.getPosition().y < enemy[i].getPosition().y && t.asMilliseconds()>=1000)
                {
                    t=clo6.getElapsedTime();
                    t2=attack(t, "demon0.png", "demon1.png");
                    if(t.asMilliseconds()>=100)
                        clo6.restart();
                    t=clo4.getElapsedTime();
                }
                if(hero.getPosition().x > enemy[i].getPosition().x && t.asMilliseconds()>=1000)
                {
                    t=clo6.getElapsedTime();
                    t2=attack(t, "demon0.png", "demon1.png");
                    if(t.asMilliseconds()>=100)
                        clo6.restart();
                    t=clo4.getElapsedTime();
                }
                if(hero.getPosition().x < enemy[i].getPosition().x && t.asMilliseconds()>=1000)
                {
                    t=clo6.getElapsedTime();
                    t2=attack(t, "demon0.png", "demon1.png");
                    if(t.asMilliseconds()>=100)
                        clo6.restart();
                    t=clo4.getElapsedTime();
                }
                ///Enemy Movement
                if(hero.getPosition().y > enemy[i].getPosition().y && t.asMilliseconds()>=1500)
                {
                    enemy[i].move(0, 32);
                    mov = true;
                    mov2 = false;
                    mov3 = false;
                    mov4 = false;
                    clo4.restart();
                }
                if(hero.getPosition().y < enemy[i].getPosition().y && t.asMilliseconds()>=1500)
                {
                    enemy[i].move(0, -32);
                    mov = false;
                    mov2 = true;
                    mov3 = false;
                    mov4 = false;
                    clo4.restart();
                }
                if(hero.getPosition().x > enemy[i].getPosition().x && t.asMilliseconds()>=1500)
                {
                    enemy[i].move(32, 0);
                    mov = false;
                    mov2 = false;
                    mov3 = true;
                    mov4 = false;
                    clo4.restart();
                }
                if(hero.getPosition().x < enemy[i].getPosition().x && t.asMilliseconds()>=1500)
                {
                    enemy[i].move(-32, 0);
                    mov = false;
                    mov2 = false;
                    mov3 = false;
                    mov4 = true;
                    clo4.restart();
                }
            }
            ///Enemy damages Hero
            if(enemy[i].getPosition() == hero.getPosition() && mov)
            {
                enemy[i].move(0, -32);
                health -= edamage;
                slashb = true;
                damage.play();
                Slash.setPosition(hero.getPosition().x - 15, hero.getPosition().y - 15);
                h += 16;
                if(h >=80)
                {
                    h2--;
                    h = 16;
                }
                mov = false;
            }
            if(enemy[i].getPosition() == hero.getPosition() && mov2)
            {
                enemy[i].move(0, 32);
                health -= edamage;
                slashb = true;
                damage.play();
                Slash.setPosition(hero.getPosition().x - 15, hero.getPosition().y - 15);
                h += 16;
                if(h >=80)
                {
                    h2--;
                    h = 16;
                }
                mov2 = false;
            }
            if(enemy[i].getPosition() == hero.getPosition() && mov3)
            {
                enemy[i].move(-32, 0);
                health -= edamage;
                slashb = true;
                damage.play();
                Slash.setPosition(hero.getPosition().x - 15, hero.getPosition().y - 15);
                h += 16;
                if(h >=80)
                {
                    h2--;
                    h = 16;
                }
                mov3 = false;
            }
            if(enemy[i].getPosition() == hero.getPosition() && mov4)
            {
                enemy[i].move(32, 0);
                health -= edamage;
                slashb = true;
                damage.play();
                Slash.setPosition(hero.getPosition().x - 15, hero.getPosition().y - 15);
                h += 16;
                if(h >=80)
                {
                    h2--;
                    h = 16;
                }
                mov4 = false;
            }
            ///Enemy Death
            if(ehealth[i] <= 0)
            {
                enemy.erase(enemy.begin() + i);
                ehealth.erase(ehealth.begin() + i);
                ewaller.erase(ewaller.begin() + i);
            }
        }
        if(keyn >= 1)
            key_have=true;
        else
            key_have=false;
        keynum.setString(to_string(keyn));
        window.draw(tbar);
        window.draw(keyi);
        window.draw(times);
        window.draw(keynum);

        for(int i = 0; i < keys.size(); i++)
        {
            if(keys[i].getGlobalBounds().intersects(hero.getGlobalBounds()))
            {
                keys.erase(keys.begin()+i);
                key.play();
                keyn++;
            }
        }
        for(int i = 0; i < healths.size(); i++)
        {
            t=clo5.getElapsedTime();
            healtht=bob(t, "GUI0.png", "GUI1.png");
            if(t.asMilliseconds()>=600)
                clo5.restart();
            healths[i].setTexture(healtht);
            healths[h2].setTextureRect(IntRect(h, 16, 16, 16));
            healths[0].setPosition(view1.getCenter().x - 400, view1.getCenter().y - 300);
            healths[1].setPosition(view1.getCenter().x - 384, view1.getCenter().y - 300);
            healths[2].setPosition(view1.getCenter().x - 368, view1.getCenter().y - 300);
            window.draw(healths[i]);
        }
        ///GAMEOVER
        if(health <= 0)
        {
            //death = true;
        }
        window.draw(Slash);
        waller.setPosition(hero.getPosition());
        viewer.setPosition(view1.getCenter());
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop
    return 0;
}

