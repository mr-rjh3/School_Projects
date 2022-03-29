#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    string fn;
    string ln;
    int pay;
    int hrs;
    int gross;
    char deduction;
    int net;
    char yn = 'n';


    cout<<"This program will produce a pay slip."<<endl;
    Sleep(2000);
    cout<<"But first you must provide the following information."<<endl;
    Sleep(2000);

    while(yn == 'n'){
            cout<<"Now, what is your last name?"<<endl;
            cin>>ln;
            cout<<"Okay, now what is your first name."<<endl;
            cin>>fn;
            cout<<"So your name is "
            <<fn
            <<" "
            <<ln
            <<"."
            <<" y/n"
            <<endl;
            cin>>yn;
    }

    cout<<"Okay, now that I've got your name i'll need your hourly rate of pay."<<endl;
    Sleep(2000);
    yn='n';

    while(yn=='n'){
        cout<<"Please input your hourly rate now."<<endl;
        cin>>pay;
        cout<<"so your hourly rate is "
        <<pay
        <<". y/n."
        <<endl;
        cin>>yn;
    }
    yn='n';
    cout<<"Great! Next on the list is the amount of hours you worked that week."<<endl;
    Sleep(2000);

    while(yn=='n'){
        cout<<"Please enter the amount of hours you worked that week now."<<endl;
        cin>>hrs;
        cout<<"so you worked "
        <<hrs
        <<"hours that week?"<<endl;
        cin>>yn;
    }

    cout<<"Now you must indicate which tax group you are apart of."<<endl;
    Sleep(2000);
    cout<<"A.	No tax deductions"<<endl;
    Sleep(2000);
    cout<<"B.	Tax is 10% of gross pay"<<endl;
    Sleep(2000);
    cout<<"C.	Tax is 20% of gross pay"<<endl;
    Sleep(2000);
    cout<<"D.	Tax is 29% of gross pay"<<endl;
    Sleep(2000);
    cout<<"E.	Tax is 35% of gross pay"<<endl;
    Sleep(2000);

    yn='n';
    while(yn=='n'){
        cout<<"please enter the the category you belong in, A, B, C, D, or E."<<endl;
        cin>>deduction;
        cout<<"You entered"
        <<deduction
        <<". Is that correct? y/n"<<endl;
        cin>>yn;
    }

    cout<<"One last question. \nDo you want to have $20 duducted from your weekly pay and contributed to the united way?"<<endl;
    cin>>yn;

    Sleep(2000);

    cout<<"Great! I will now compute your pay slip just hold on a moment."<<endl;
    Sleep(1000);
    cout<<"."<<endl;
    Sleep(1000);
    cout<<"."<<endl;
    Sleep(1000);
    cout<<"."<<endl;
    Sleep(1000);

    cout<<"okay i'm done! Here you go!"<<endl;

    cout<<ln
    <<", "
    <<fn
    <<"\n"
    <<pay*hrs
    <<"Gross Pay"<<endl;
    if (duduction=='a'){
        cout<<"0% Tax duduction"<<endl;
    }
    else if (duduction=='b'){
        cout<<"10% Tax duduction"<<endl;
    }
    else if (duduction=='c'){
        cout<<"20% Tax duduction"<<endl;
    }
    else if (duduction=='d'){
        cout<<"29% Tax duduction"<<endl;
    }
    else if (duduction=='e'){
        cout<<"35% Tax duduction"<<endl;
    }
    cout<<"Therefore your net pay is"












    return 0;
}
