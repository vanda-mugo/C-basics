// Section 13
// Constructor Initialization Lists
#include <iostream>
#include <string>

using namespace std;

class Player
{
private: 

    // in the case of the string being initialised above, notice that the name variable which is a string is being initialised to "XXXXXXX"
    // therefore when an object of the class is created before the constructor is accessed this value is already initialised to the member attribute of the said object 
    // using the initial constructors in this case is henceforth inefficient since you are just assigning values to already initialised class memeber attributes for said object
    // using constructor list aids this as it initialises member attributes before even the constructor starts execution
   std::string name {"XXXXXXX"};
   int health;
   int xp;
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};


// this constructors show the use of constructor lists , they are not initialised to any other value but the values initialised in the constructor lists
Player::Player() 
    : name{"None"}, health{0}, xp{0} {
        // the constructor bodies can be empty since in this case the member attributes have already been initialised
}

Player::Player(std::string name_val) 
   : name{name_val}, health{0}, xp{0} {
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
    
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}

