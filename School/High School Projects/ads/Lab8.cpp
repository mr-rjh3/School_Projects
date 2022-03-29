#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    /*Question 1

    int grade;
    int grade2;
    int n;

        cout<<"Enter in your grades. You can stop by entering any negative number."<<endl;
        for(n=0,grade,grade2=0;grade>0;grade2+=grade,n++){
            cin>>grade;
        }
        cout<<"The average of all your grades is: "
        <<(grade2-grade)/(n-1)<<endl;

        */

    /*Question 2
    int n;
    float i, sum=0;

    cout<<"This program finds the sum of the series 1+1/2+1/3...1/n. Enter 'n'."<<endl;
    cin>>n;
       for(i=1;i<=n;i++){
            sum+=1/i;
            cout<<sum<<endl;
    }

    i=1;
    sum=0;
    cout<<"This program finds the sum of the series 1+1/2+1/3...1/n. Enter 'n'."<<endl;
    cin>>n;
    while(i<=n){
        sum+=1/i;
        cout<<sum<<endl;
        i++;
    }

*/

    int n;

    cin>>n;
    string s = to_string(n);
    cout<<s<<endl;



    return 0;
}
