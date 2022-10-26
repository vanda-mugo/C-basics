// Section 9
// Switch with enumeration

#include <iostream>

using namespace std;

int main() {
    // here an enumeration type called direction is declared whose constants are left, right, up and down
    //note by when creating an enumeration you are creating a new type in this case the new type is direction 
    //henceforth with the new type you can create variables to match this new type
    enum Direction {
        left, right, up, down
    };
    
    Direction heading {left};// this here is a variable of the new type which in this case is Direction 
    //note by in this case heading is of type Direction and its initialised to the constants in this case left which is one of the constants of the declared type 
    // enumerations are integral types
    
    switch (heading) {
        case left:
            cout << "Going left" << endl;
            break;
        case right:
            cout << "Going right" << endl; // I used going left in the video by mistake
            break;
        default:
            cout << "OK" << endl;
    }
    
    cout <<  endl;
    return 0;
}

