#include <iostream>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;

int main()
{
    //Question 1

//*
    float a;
    float b;
    float c;

    cout << "Enter A, B, C values of a quadratic equation to get the roots."<<endl;
    Sleep(1000);

    cout << "Enter A variable now."<< endl;
    cin >> a;
    cout << "Enter B variable now."<< endl;
    cin >> b;
    cout << "Enter C variable now."<< endl;
    cin >> c;

    cout<<"The variables you put in were A="<< a <<" B=" << b <<" C="<< c<<"."<<endl;

    cout<<"The roots of this equation are"<<endl;

    float root1 = (-b+sqrt(pow(b,2)-4*a*c))/2*a;
    float root2 = (-b-sqrt(pow(b,2)-4*a*c))/2*a;


    cout<< root1<< " and " << root2<<endl;
//*/

    //Question 2

//*
    float a2;
    float b2;
    float c2;

    cout << "To find the area of the triangle enter the sides 'a', 'b', and 'c'."<< endl;
    cout << "Enter A variable now."<< endl;
    cin >> a2;
    cout << "Enter B variable now."<< endl;
    cin >> b2;
    cout << "Enter C variable now."<< endl;
    cin >> c2;

    cout<<"The variables you put in were A="<< a2 <<" B=" << b2 <<" C="<< c2 <<"."<<endl;

    float s = (a2+b2+c2)/2;
    float area = sqrt(s*(s-a2)*(s-b2)*(s-c2));

    cout<<"The area of this triangle is\n" << area <<endl;
//*/

    //Question 3

//*
    char lc;

    cout<<"Input a lowercase letter and I will output that letter in uppercase!"<<endl;
    cin>>lc;

    cout<<"you entered "<<lc<<endl;
    int uc= ((int)lc)-32;
    cout <<"here is the uppercase version: "<< (char)uc <<endl;

//*/

    //Question 4

//*
    int dollar;
    int quart;
    int dime;
    int nick;
    int cent;
    int change;

    string plurd;
    string plurq;
    string plurdime;
    string plurn;
    string plurc;

    cout<<"This program will tell you how many\nDollars, quarters, dimes, and nickels you should get\nafter telling it how much change is owed back."<<endl;
    Sleep(2000);
    cout<<"Enter change due back in cents now please."<<endl;
    cin>>change;

    dollar = change/100;
    change = change % 100;
    quart = change/25;
    change = change % 25;
    dime = change/10;
    change = change % 10;
    nick = change/5;
    change = change % 5;
    cent = change;

    if (dollar>1){
        plurd= "dollars";
   } else if (dollar=1){
        plurd= "dollar";}

    if (quart>1) {
        plurq= "Quarters";
    }else if (quart=1) {
        plurq= "Quarter";}

    if (dime>1){
        plurdime= "Dimes";
    }else if (dime=1){
        plurdime= "Dime";}

    if (nick>1){
        plurn= "Nickles";
   } else if (nick=1) {
        plurn= "Nickel";}

    if (cent>1){
        plurc= "Cents";
   } else if (cent=1) {
        plurc= "Cent";}


    cout<<"Your change is:"<<endl;
    cout<<dollar<< " "<<plurd<<endl;
    cout<<quart<<" "<<plurq<<endl;
    cout<<dime<<" "<<plurdime<<endl;
    cout<<nick<<" "<<plurn<<endl;
    cout<<cent<<" "<<plurc<<endl;

//*/

    return 0;
}
