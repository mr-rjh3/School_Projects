#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
/*
    vector <int> v;
    for(int i=0;i<4;i++) {
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            v.push_back(5);
            v.push_back(6);
            v.push_back(7);
            v.push_back(8);
            v.push_back(9);
            v.push_back(10);
            v.push_back(10);
            v.push_back(10);
            v.push_back(10);
    }

    random_shuffle(v.begin(), v.end());

    for(int i=0;i<v.size();i++) {
            cout<<v[i]<<endl;
    }
    */


    /*
    vector <int> v;
    int n;
    for(int i=0;i<5;i++){
    cin>>n;
    v.push_back(n);
    }


    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++) {
            cout<<v[i]<<endl;
    }
    */


    /*
    vector <int> v;
    int n;

    for(int i=0;i<=10000;i++){
        v.push_back(rand());
    }

    cout<<*max_element(v.begin() , v.end())<<endl;

    n=count(v.begin(),v.end(),*max_element(v.begin() , v.end()));
    cout<<n<<endl;
    */


    vector <int> v;
    for(int i=1;i<=10;i++){
        v.push_back(i);
    }

    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<endl;
    }
    //Will be 1,2,3,4,5,6,7,8,9,10

    reverse(v.begin(),v.end());
    //Reverses the order


    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<endl;
    }
    //Becomes 10,9,8,7,6,5,4,3,2,1








    return 0;
}
