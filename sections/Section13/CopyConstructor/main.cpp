// Section 13
// Copy Constructor
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

    // the above are public member methods therefore can be accessed from outside the class 
    std::string get_name()
        {
            return name;
        }
    int get_health()    
        {
            return health;
        }
    int get_xp()
        {
            return xp;
        } 
        
    //  3 args constructor 
    Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    // note by this is a prototype for the copy constructor 
    Player(const Player &source);
    // Destructor
    //this will show us when the object is being deleted 
    ~Player() { cout << "Destructor called for: " << name << endl; }
};

// note by this is the player constructor 
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val}
 {
            cout << "Three-args constructor for " + name << endl;
}

// this is implementation of the player copy constructor
//note by that the main use of the copy constructor is that it creates new objects from existing objects 
// this example is an illustration of the copy constrcutor for the above class 


Player::Player(const Player &source)
    // we use const in this case to avoid  altering the actual source
    // there are two ways by which this can be done , one is specified just below
   // : name(source.name), health(source.health), xp{source.xp} {
      
    // this is delegating the construction to the 3 args constructor 
    //notice how a constructor is called in this case using the arguments you would want to include with the new constructor  
       : Player {source.name, source.health, source.xp}  
       {
            cout << "Copy constructor - made copy of: " << source.name << endl; 
        }

// this is a function that expects a player by value
// the value p implies pass by value since the player object that will be input into this will be a copy that is stored into the p variable that is local to the function 
void display_player(Player p) {
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;    
}

int main() {    
    Player empty {"XXXXXX", 100, 50};
    
    Player my_new_object {empty};
    
    // whenever this function is called the copy constructor is called 
    // therefore when this is called since a user defined copy constructor was implemented this will take precedence 
    // this is because p is local to the function display_player() and that enemy being a member of the class Player that has a user defined copy constructor 
    display_player(empty);
    
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
        
    return 0;
}