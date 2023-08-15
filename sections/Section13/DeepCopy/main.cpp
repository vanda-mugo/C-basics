// Section 13
// Copy Constructor - Deep Copy
#include <iostream>

using namespace std;

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};

//one arg constructor for the class that is Deep 
// notice that data which is the value of a pointer which is a variable that stored a memory location in this case has been assigned 
// has been assigned the value of new int which is dynamic memory on the heap for type int variable 
Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// in deep copying as can be noted with the copy constructor delegation happens and the value passed as int d in this case is the dereferenced value of 
// data which is *source.data 
Deep::Deep(const Deep &source)
// another way this can be achived is by use of  the above within the constructor body
    : Deep {*source.data}// in this case what happens is that in the delegated constructor variable int d which is an l value 
    // is the one that is assigned the value *source.data which is the dereferenced value of the pointer data
    

 {
        /*
         data = new int;  // basically this will allocate new storage on the heap for type int variable 
        *data = *source.data;

this or the delegation that happened in the constructor initialisation list can be an approch for deep copying        
         */
    cout << "Copy constructor  - deep copy" << endl;
}

Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Deep s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Deep obj1 {100};
    display_deep(obj1);
    
    Deep obj2 {obj1};
    
    obj2.set_data_value(1000);
  
    return 0;
}

