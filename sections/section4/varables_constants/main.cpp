#include <iostream>
using namespace std;
// this is a global variable
// if a variable name is referenced within a function this variable is searched initially within this function before 
// searching for this variable in the global namespace 
int agemate {18};


int main() {
    
     // in todays course we investigate what variables are 
    // a variable is an abstraction for memory location 
    //variables have type that is their category ( integer, real numbers, stringm 
    // variables also have values associated with this  
    
    // example
    // you have to declare a variable before being used in c++
    // syntax for variable declaration
    
    //variable type variable name ;
    //be consistent with the naming convention used 
    // never use variables before initialzizing them 
    // simple program that calculates the are of a rectangle
    
    int length = 0 , width = 0, area = 0;
    cout<<"Please insert the value of length : ";
    cin>>length;
    cout<<"Please insert the value of width :";
    cin>>width;
    area =length * width;
    cout<<" the area of the rectangle is "<<area<<endl;
    
    
    // its good practice to declare a variable closest to where this variable is used 

    //exercise 
    double hourly_wage {23.50};
    int age;
    string name;
    cout<<"Please enter your name and age :";
    cin>>name>>age;
    cout<<name<<" "<<age<<" "<<hourly_wage<<endl;
    
    std::cout << "My template " << std::endl;
    
    
    //global variables are decalred outside the function
    //local variables are declared inside a function that is local to that function 
    return 0;
}