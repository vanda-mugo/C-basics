#include <iostream>
using namespace std;

int main()
{
    
    
    // what are variables 
    int num1;
    int num2, num4, num5;
    double num3;

    cout<<"enter an integer :";
    cin>>num1;
    cout<<"youve entered :"<<num1<<endl;
    
    
    cout<<"enter first integer :" ;
    cin>>num2;
    cout<<"Enter the second integer :";
    cin>>num3;
    cout<<"Youve entered"<<num2<<"and"<<num3<<endl;
    
    //chaining inputs
    cin>>num4>>num5;
    cout<<"youve entered :"<<num4<<num5<<endl;
    return 0;
}