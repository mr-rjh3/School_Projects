#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int myrand(int mn, int mx){
    int mnn=mx-mn;
    srand(time(0));
    int rannd=rand()%mnn + mn;

return rannd;
}


int main()
{
    int mx=0;
    int rannd;
    srand(time(0));
    int x,y;
    cout<<time(0)<<endl;
    cin>>x>>y;
    cout<<myrand(x,y)<<endl;

    for(int i=1000000; i>=0; i--){
        rannd=rand();
        if(mx>rannd) mx=rannd;
    }
    cout<<mx<<endl;

    return 0;
}
