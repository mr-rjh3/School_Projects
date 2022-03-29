#include <iostream>

using namespace std;

int main()
{
    int h;
    int z;
    int dt;
    int depart;
    int arrt;
    int arrive;
    float recover;

    cout << "This program will calculate how much rest is needed in days to recover from \njetlag." << endl;

    cout<<"Enter the amount of hours traveled here."<<endl;
    cin>>h;

    cout<<"Enter how many time zones you crossed to travel to your destination."<<endl;
    cin>>z;

    cout<<"Enter the departure time. Please use a twenty-four hour clock."<<endl;
    cin>>dt;

    while (dt>24){
      if (dt>24)
        cout<<"There aren't that many hours in the day. Please try again."<<endl;
        cin>>dt;
    }

    if (dt>=8 && dt<12){
        depart = 0;
    }
    else if (dt>=12 && dt<18){
        depart = 1;
    }
    else if (dt>=18 && dt<22){
        depart = 3;
    }
    else if (dt>=22 && dt==8){
        depart = 4;
    }
    else if (dt>=1){
        depart = 5;
    }

    cout<<"Enter the arrival time. Please use a twenty-four hour clock."<<endl;
    cin>>arrt;

    while (arrt>24){
      if (arrt>24)
        cout<<"There aren't that many hours in the day. Please try again."<<endl;
        cin>>arrt;
    }

    if (arrt>=8 && arrt<12){
        arrive = 4;
    }
    else if (arrt>=12 && arrt<18){
        arrive = 2;
    }
    else if (arrt>=18 && arrt<22){
        arrive = 0;
    }
    else if (arrt>=22 && arrt==8){
        arrive = 1;
    }
    else if (arrt>=1){
        arrive = 3;
    }

    recover = (h/2+(z-3)+depart+arrive)/10;

    cout<<"The amount of days needed to recover from the jetlag is: "
    <<recover
    <<" days"
    <<endl;


    return 0;
}
