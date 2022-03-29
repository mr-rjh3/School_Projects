#include <iostream>

using namespace std;


int factorial(int n){
    if(n>0) return n* factorial(n-1);
    else return 1;
}



int choose(int n,int r){

    int i=factorial(n)/(factorial(r)*factorial(n-r));
    return i;

}



int main()
{

    return 0;
}
