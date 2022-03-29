#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int v;
    int t;

    cout<<"Input the wind speed in miles per hour."<<endl;
    cin>>v;
    cout<<"Input the temperature in Fahrenheit."<<endl;
    cin>>t;

    if (v>=0 and v<=4) {
        cout<< "the temperature is: "
        << t
        <<" Degrees Fahrenheit"
        <<endl;
    }
    else if (v >=45){
        cout<<"The temperature is: "
        <<1.6*t-55
        <<" Degrees Fahrenheit"
        <<endl;
    }
    else {
        cout<<"The temperature is: "
        <<91.4+(91.4-t)*(0.0203*v-0.304*sqrt(v)-0.474)
        <<" Degrees Fahrenheit"
        <<endl;
    }


    return 0;
}
