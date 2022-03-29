#include <iostream>
#include <string>

using namespace std;

int minn(int x[10]){
int mn;

    for(int i=0; i<10; i++){
        if(mn>x[i]) mn=x[i];
    }

    return mn;
}


int maxx(int x[10]){
int mx=0;

    for(int i=0; i<10; i++){
        if(mx<x[i]) mx=x[i];
    }

    return mx;
}


int main(){

    string name[6];
    int x[10];
    //string name[6] = {"James","John","Carol","Ben","Donald","Ann"};


    for(int i=0;i<10;i++){
        cin>>x[i];
    }

    cout<<endl<<minn(x)<<endl<<maxx(x)<<endl;




    for(int i=0;i<6;i++){
        cin>>name[i];
        if(name[i][0]=='P' || name[i][0]=='p'){
            cout<<"That name starts with p"<<endl;
        }
    }



    return 0;
}


