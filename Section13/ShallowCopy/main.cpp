// Section 13
// Copy Constructor - Shallow Copy
// Note: this program will crash
#include <iostream>

using namespace std;

class Shallow {
private:
    int *data; // note that this is a pointer for an integer object 
    
public:
    // the following are member class methods 
    
    // first method dereferences the pointer data and assigns the value d as the data the pointer is pointing to 
    void set_data_value(int d) { *data = d; }
    
    // this method returns the dereferenced pointer that is the data the pointer is actually pointing to 
    int get_data_value() { return *data; }
    // Constructor
    // only method prototypes of the above constructors have been made 
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

// basically this constructor has one argument integer that is d
// the constructor assigns the pointer a location in the heap to store the dynamic integer , therefore the pointer data points 
// points to an integer location in the heap
// the constructor also dereferences the pointer data and sets the value of the data that this pointer points to as d
Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}


// note that this copy constructor basically just copies the pointer in this case the pointer being data
// remember that a pointer is a variable whose value is a location in memory
// in this case data is a pointer, *data is the value that this pointer points to 
// therefore in the initialisation list as can be noted that the  data which in the initial constructor is a dynamic allocated memory for an integer is copied as the value of data
// from the source which in this case would be a member of the class , data is a pointer and that is the same thing that will be copied with this pointer rather than the value data points to
Shallow::Shallow(const Shallow &source) 
    : data(source.data) {
        cout << "Copy constructor  - shallow copy" << endl;
}


// destructor that is called when an object of the class is destroyed
Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

// note by that in this case s which is of type shallow is a pass by value and henceforth will  make a copy of whatever argument is passed in the function 
// argument has to be of type   Shallow
void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Shallow obj1 {100}; // initialised an object of class Shallow 
    display_shallow(obj1); // in this case a copy of the object obj1 is made 
    // notice that the copy is local to this function and therefore when the function ends the copy/object in this case is destroyed 
    // note by that the object in this case was a pointer since 100 is the value of the dereferenced pointer data that is stored dynamically on the heap
    // when this shallow copy is done and destroyed both the copy that was made and the obj1 were in the same memory location since the copy constructor only pointed to the same location 
    
    Shallow obj2 {obj1};
    obj2.set_data_value(1000);
    
    return 0;
}

