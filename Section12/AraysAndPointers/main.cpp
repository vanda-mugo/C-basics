#include <iostream>

using namespace std;

int main() {
    
    int scores[] {100, 95, 89};// this basically is scores array that is at a certain location in memory. 
    // remember that they are contiguos since it an array that is all elements of the array are of teh same type
    // also remember that the value of an array name in this case the value of scores is an address in memory
    // also remember that the pointer value is usually also an address in memory
    cout << "Value of scores: " << scores << endl;     // this should be an address in memory
    //output   :  0x6707fff85c
    
    int *score_ptr {scores};// this is an initialised pointer whose value is that of scores
    // remember that we dont use the (&) in this case because the & infront a variable is used to reference the address in memory, 
    //however in this case scores is already an address in memory. realise that this is the address of the first array element in the memory
    cout << "Value of score_ptr: " << score_ptr << endl;// the value of a pointer is an address in memory. in this case this is the address of the first element of the array
    // output : 0x6707fff85c
    cout << "\nArray subscript notation -------------------------" << endl;// using array subscript notation
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;
    
    cout << "\nPointer subscript notation -------------------------" << endl;// since array name values and poiter name values are the same then this is using the 
    // subscript notation with the pointer 
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;
    
    cout << "\nPointer offset notation-------------------------" << endl;// using pointer dereferencing 
    // note by since the pointer declared was a pointer of integers when you add 1 per say what happens is that the size of an int variable is added onto the address stored by the pointer
    cout << *score_ptr << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr +2) << endl;
    
    cout << "\nArray offset notation-------------------------" << endl;// can also apply to the array name since its an address in memory
    cout << *scores << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores +2) << endl;
    
    cout << endl;
    return 0;
}

