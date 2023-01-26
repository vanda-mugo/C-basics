// Section 12
// Passing Pointers 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// note by the function display expects a constant pointer that points to a constant vector , a constant vector of strings 
// v is the name of the constant pointer that points to the constant vector 
void display( const vector<string> *const  v) {
//(*v).at(0) = "Funny";
    for (auto str: *v)// passing the dereference pointer for sequence vector into the for range based loop. in this case just passing in the vector 
        cout << str << endl;
    cout << endl;
  
 //   v = nullptr;  // should not be possible
}

// the second display function expects a pointer and anoter int variable sentinel as the arguments passed to the void function 
void display(int *array, int sentinel) {
    while (*array != sentinel)// since array is a pointer in this case the array is being dereferenced in which arrau poingts to the first element in the array
        cout << *array++ << " "; // post fix where the array pointer is added to in this case added to after being used in the iteration that was taking place in the loop 
        // kindly note that when you add 1 to an array that essentially means adding the size of variable to the address already represnted by the pointer ,in this case size of int 
    cout << endl;
}

int main() {

    
// this is for the vector 
//    cout << "-----------------------------" << endl;
//    vector<string> stooges {"Larry", "Moe", "Curly"};
//    display(&stooges);
    // remember function overloading which is the case here with the display function 
   
    cout << "\n-----------------------------" << endl;
    int scores[] {100,98,97,79,85,-1};
    display(scores, -1);
    
    cout  << endl;
    return 0;
}

