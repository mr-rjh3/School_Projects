#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> names;
    vector<float> nums={1, 0.5, 0.25, 0.125};

    names.push_back("Bingo");
    names.push_back("Donny");
    names.push_back("Thunder");
    names.pop_back();

    cout<<names.size();

    return 0;
}
