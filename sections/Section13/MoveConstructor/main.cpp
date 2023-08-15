// Section 13
// Move Constructor 
#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    Move(Move &&source) noexcept;
    // Destructor
    ~Move();
};

 Move::Move(int d)  {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy ctor
Move::Move(const Move &source)
    : Move {*source.data} {
        cout << "Copy constructor  - deep copy for: " << *data << endl;
}

//Move ctor
Move::Move(Move &&source) noexcept 
// note by the move object which is what is expected within this move constructor has a data variable whose value is an address , a pointer variable to be precise 
// what happens is that when you pushback temp objects in the vector a copy of them has to be made which is the copy that is passed and copied into our vector 
// notice since each temporaty variable has a data variable in some location in memory , by doing deep copy each time it consumes alot of time since new memory is created with each pushback
// the move constructor in the other hand will move the pointer of the variable/object to be copied in the vector to point at the temporary location before the temporary pointer in this case is nulled out leaving the new object 
// pointing to this location

    : data {source.data} {
        source.data = nullptr;
        cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;

    vec.push_back(Move{10});
    
    Move moveObj1{30};
    vec.push_back(moveObj1);
    moveObj1.~Move();
//    vec.push_back(Move{20});
//    vec.push_back(Move{30});
//    vec.push_back(Move{40});
//     vec.push_back(Move{50});
//    vec.push_back(Move{60});
//    vec.push_back(Move{70});
//    vec.push_back(Move{80});

//note by that the move{10}, etc in the vec.push_back() is a temporary object since its not addressable and after 
//the vector has been pushed back this will be deleted unlike the moveObj1 which is a move object but in this case not
// a temporary object since its addressable and the only thing that happens is that the vector makes a copy of this object within itself

//note that the move constructor expects a temporary object so when you pushback temporary objects the move constructor gets to be called 


    return 0;
}

