// Section 15
// Copy constructor and operator=
#include <iostream>

using namespace std;

class Base {
    // we are going to go throught this checking each of the classes and what is offered by them
private:
    int value;
public:
// the above is a no args constructor for the class that is Base 
   Base()
        : value {0}  { 
            cout << "Base no-args constructor" << endl; 
    }
    // overloaded base constructor 
    Base(int x) 
        : value {x} { 
            cout << "int Base constructor" << endl;
    }
    // copy constructor for the class that is Base 
    // note by that this expects reference for an object in this case other that is of type Base 
    Base(const Base &other) 
        : value {other.value} {
         cout << "Base copy constructor" << endl;     
    }
        
    // copy assignment overloaded constructor 
    Base &operator=(const Base &rhs)  {
    cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }
            
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
private:
    int doubled_value;
public:
// nb here we have the derived class no args constructor which invokes(calls) the Base constructor for no args
// note that this is the base constructor that will be called/ implied when an object of derived class is made that has no parameter arguments
    Derived() : 
        Base {}  {
            cout << "Derived no-args constructor " << endl; 
    }
    
    // overloaded derived constructor 
    Derived(int x) 
        : Base{x} , doubled_value {x * 2} { 
            cout << "int Derived constructor" << endl; 
    }
    // copy constructor for the derived class. lets go through what happens when this copy constructor is called 
    //nb it oinvokes the base with the member of the derived class as the argument 
    // since we are invoking base(other) we are calling the base class copy constructor 
    // note by that the other part which is an object of the type derived is sliced to reveal its base part 
    // this is done in the base copy constructor which in this case is the one that is called 
    //explanation note by that other in this case is what is being copied ( instance of the derived class that is being copied ) realize that its a constant 
    // now because of this being a constant we cannot change the object we are copying from and remember that copy consructors function with the l values that is they are 
    // addresable in memory
    // since a copy constructor creates a new object based on the l value object that happens to be passed onto it
    //when Base(other) is invoked what happens is that the copy constructor in this case is the one that is called in the base class
    // other in this case now will be the address of the object being copied and value which is a base class attribute is in this case initialised to the 
    //  : value {other.value}
    Derived(const Derived &other)
        : Base(other), doubled_value {other.doubled_value} {
         cout << "Derived copy constructor" << endl;     
    }
    
    Derived &operator=(const Derived &rhs) {
            cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);// whats happening here is that the base classes overloaded assignment operator and passing in the rhs
        doubled_value = rhs.doubled_value;
        return *this;
    }
   ~Derived(){ cout << "Derived destructor " << endl; } 
};


int main() {
//    Base b {100};   // Overloaded constructor
//    Base b1 {b};    // Copy constructor
//    b = b1;          //   Copy assignment

    Derived d {100};    // Overloaded constructor
    Derived d1 {d};     // Copy constructor
    d = d1;                // Copy assignment
    
    return 0;
}

