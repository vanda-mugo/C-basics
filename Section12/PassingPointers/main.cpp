// Section 12
// Passing Pointers 1
#include <iostream>

using namespace std;

// the function above called double data expects a pointer as its parameter aegument
// its a void function henceforth does not have any return type
// due to the dereferencing what happens is that the value pointed to by the pointer is the one that is multiplied by 2
// by dereferencing you access the value that such a pointer points to 
void double_data(int *int_ptr) {
   *int_ptr *= 2;	
}

int main() {
    int value {10};
    int *int_ptr {nullptr};// initialised a pointer in this case "int_ptr set to value of null or 0
    
    cout << "Value: " << value << endl;// will output value of the int variable 
    double_data(&value);// calling the function that expects a pointer as its argument , realise that the 
    // argument passed in the function is actually the address for the value in memory which in this case is like a pointer 
    cout << "Value: " << value << endl;// 20

    cout << "-----------------------------" << endl;
    int_ptr = &value;// now we assign the pointer to be equal to the address of the value variable 
    double_data(int_ptr);// call the function 
    cout << "Value: " << value << endl;// 40

    cout  << endl;
    return 0;
}