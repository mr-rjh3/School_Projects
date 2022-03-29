#include <iostream>
#include <math.h>

using namespace std;

void countdown() {
    for (int i = 10; i >= 1; i--) {
cout<<i<<endl;
    }
}


float maximum(float n1,float n2,float n3){
    float n;

    if (n1>=n2 && n1>=n3){
        n=n1;
    }
    else if (n2>=n1 && n2>=n3){
        n=n2;
    }
    else if (n3>=n2 && n3>=n1){
        n=n3;
    }

    return n;
}

int GCF(int n1, int n2){

int n;
bool remainder, remainder2;

    if (n1>=n2){
        n=n1;
    }
    else if (n2>=n1){
        n=n2;
    }

for(int i=n; i>=0; i--){
    remainder = n1%i;
    remainder2 = n2%i;
    if(remainder==0&&remainder2==0){
        return i;
    }
}

return 0;
}
/*void euler(int &n1) {

    float n2 = pow(2.718281828,n1);
    cout<<n1<<endl;

}
*/
void swapper(int n1,int n2) {
    int n3=n1;
    n1=n2;
    n2=n3;
    cout<<"n1 is now equal to n2."
    <<endl
    <<"n1:"
    <<n1
    <<endl
    <<"n2:"
    <<n2
    <<endl;
}

void func(int &x)
{
   x = 4;
}

void callfunc()
{
    int x = 7;
    func(x);

}





void euler(float n) {

    n=10;
    float n2 = pow(2.718281828, n);
    cout<< n2 <<endl;

}

int main()
{
    float n;
    cin>>n;
    euler(n);
    return 0;
}

/*int main()
{
    int n1;
    cin>>n1;
    euler(n1);
    cout<<n1;


    return 0;
}
*/
