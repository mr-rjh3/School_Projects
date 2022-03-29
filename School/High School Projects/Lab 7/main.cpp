#include <iostream>

using namespace std;

int main()
{

    /*
    float total;
    float grade;
    int n;
    for (total,n=1 ; n != 6 ; total += grade, n++) {

	cout<<"Enter grade "
	<< n
	<<endl;

	cin>>grade;
	while(grade>100){
        cout<<"You can't have a grade over 100%. Try again."<<endl;
        cin>>grade;
	}
}

    float average = total/5;

    cout<<"Your average is: "
    <<average
    <<"."
    <<endl;
    */

    int n;
    int n2;
    bool remainder;

    cin>>n;
        for(n2=2;n2!=n;n2++){
            remainder= n%n2;
                if(remainder==0){
                    cout<<"The number is not prime."<<endl;
                    return 0;
                }
            }
    cout<<"The number is prime"<<endl;

    return 0;
}
