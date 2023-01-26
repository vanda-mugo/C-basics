// Section 15
// Constructors and Destructors
#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base() : value{0} { cout << "Base no-args constructor" << endl; }
   Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
    using Base::Base;// this allows inheriting of non special constructors from the base class 
    // think of a special constructor as a default or copy constructor such 
    // this will take care of initialising the base part but not the derived part
private:  
    int doubled_value;
public:
    Derived() : doubled_value {0} { cout << "Derived no-args constructor " << endl; } 
    Derived(int x) : doubled_value {x*2}  { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; } 
};

int main() {
//   Base b;
//    Base b{100};
   Derived d;
 //Derived d {1000};
    
    return 0;
}

//when you have the no args constructor in the derived class commented out what happens is that since derived class is derived from the base class 
// the base part of the derived class instance will be initialised and this would cause the default no args constructor in the base class to be called 
//since the derived class no args constructor was commented out what occurs is that the attribute from the base class that was to be initialised with this is not called and 
// henceforth in this case this the private attribute doubled value would not be initialised 
//