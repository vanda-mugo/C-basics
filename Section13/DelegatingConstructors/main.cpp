// Section 13
// Delegating Constructors
 #include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
// Overloaded Constructors
// this are like cnstructor prototypes 
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

// the no args constructor is delegating to the three args constructor, its important to know that the body of the three args constructor will
// run before the body of the one arg constructor runs 
Player::Player() 
    : Player {"None",0,0} {
        cout << "No-args constructor" << endl;
}

Player::Player(std::string name_val) 
   : Player {name_val,0, 0}  {
           cout << "One-arg constructor" << endl;
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
            cout << "Three-args constructor" << endl;
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}

/*
 * (output)
 * Three-args constructor
 * No-args constructor
 * Three-args constructor
 * One-arg constructor 
 * Three-args constructor
*/

// from the output above its clear that the body of the 3 args constructor runs before the body of the constructor that is delegating to the three args constructor