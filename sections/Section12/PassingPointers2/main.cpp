// Section 12
// Passing Pointers 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// swaps two integer variables 
// note that this function expects two pointers as the arguments passed 
void swap(int *a, int *b) {
    int temp = *a;// dereference the pointer so that the value of the type it points to is the value for temp
    *a = *b;
    *b = temp;
}


int main() {
    int x {100}, y {200};// initialised variables x and y
    cout << "\nx: " << x <<  endl;// 100
    cout << "y: " << y <<  endl;//200
    
    swap(&x, &y);// note by in this passing the addtress of this variables as the argument to this function
    
    
    cout << "\nx: " << x <<  endl; 
    cout << "y: " << y <<  endl;
    
    cout  << endl;
    return 0;
}

