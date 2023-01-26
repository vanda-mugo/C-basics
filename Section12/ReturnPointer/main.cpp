// Section 12
// Return Pointer
#include <iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0) {
   int *new_storage {nullptr};// initialisation of the pointer to be equaivalent to null so points no where in the memory 
   new_storage = new int[size];   // dynamic allocation of memory on the heap that is meant for in this case a array of int 
   for (size_t i{0}; i < size; ++i)
      *(new_storage + i) = init_value;// in this case you are doing pointer arithmetics where if you add 1 to a pointer what you are doing is adding the size of the 
        // size of the variable that the pointer points to the location/ address in memory that the pointer points to 
        // the pointer therefore will be added such that it will reference the next available element in the array 
        // note by in the range based for loop
   return new_storage;
}

// in this example the function expects a constant pointer argument that points to a constant value that cannot be changed , the pointer points to a constant 
// value in memory of whose value cannot be changed 
void display(const int *const array, size_t size) {
    for (size_t i{0}; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    int *my_array {nullptr};
    size_t size;// unsigned integer variable that contains garbage data 
    int init_value {};// init value initialised to 0
    
    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;
    
    my_array = create_array(size, init_value);
    cout << "\n--------------------------------------" << endl;

    display(my_array, size);
    delete [] my_array;
    return 0;
}