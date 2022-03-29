#include <iostream>
#include <string>

using namespace std;

/*Question 11
string backwards(string input) {

    string str;

    int i = input.length();
    while(i>=0){
        str+=input[i];
        i--;
    }
    return str;
}



int main()
{

    cout<<backwards("Hello World")<<endl;


    return 0;
}
*/

///*Question 12
bool palindrome(string input){
    string backwards;
    bool tf;
    int i = input.length()-1;
    while(i>=0){
        backwards+=input[i];
        i--;
    }
     if(input==backwards){
        tf = true;
    }
    else{
        tf = false;
    }
    return tf;
}


int main(){


    cout<<palindrome("racecar")<<endl;



    return 0;
}
//*/
