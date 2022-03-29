#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    /*Question 1
    int n;
    string str;
    cout<<"Enter a word:"<<endl;
    cin>>str;
    cout<<endl;
    for(n=str.length();n>0;n--){
        cout<<str<<endl;
    }
    */

    /*Question 2

    char abc;

    for(abc=97;abc<=122;abc++){
       cout<<abc<<" ";
    }
    */

    /*Question 3

    int pop=331000;
    float growth=1.031;
    int year=2013;
    float total;

    for(int i=0;i<=17;year++,i++){
        total=pop*pow(growth,i);
        cout<<"Population in Kitchener at "<<year<<": "<<total<<endl;
    }

    */

    /*Question 4
    string str;
    string str2;

    cin>>str;
    cin>>str2;

    cout<<str;

    for(int i = str.length()+str2.length();i<30;i++){
        cout<<".";
    }

    cout<<str2;
    */

    /*Question 5
    string str;
    string i1;
    string i2;
    string i3;
    int n;
    int n1;
    int n2;
    int n3;

    for(int i=100;i<1000;i++){
        str=to_string(i);
        i1=str[0];
        i2=str[1];
        i3=str[2];
        n1=stoi(i1);
        n2=stoi(i2);
        n3=stoi(i3);
        n=pow(n1,3)+pow(n2,3)+pow(n3,3);
        if(i==n){
            cout<<n<<endl;
        }
    }
    */

    /*Question 6
    float n;
    float n2;
    int percent;
    float i1;
    string an;
    for(float i=1,i1=365,percent=10,n=1;percent<=100;i++,i1--){
        n*=i1/365;
        n2=(1-n)*100;
        if(percent==80){
            an="an";
        }
        else{
            an="a";
        }
        if(n2>=percent){

            cout<<"There is about "
            <<an
            <<" "
            <<percent
            <<"% "
            <<"chance that 2 people will have the same birthday\nwhen there is "
            <<i
            <<" people in a room\n"
            <<endl;
            percent+=10;
        }
    }
    */

    return 0;
}
