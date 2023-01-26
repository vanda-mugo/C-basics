// Section 13
// Declare Classes and Objects
  #include <iostream>
#include <string>
#include <vector>

using namespace std;

// this is a class declared called player that has the instance attributes as shown 
class Player {
    // attributes, note by each instance of this player objects is going to have the above which is 
    // the name, health and the xp
    
    string name {"Player"};
    int health {100};
    int xp {3};
    
    // methods
    // note by this are function prototypes in this case 
    void talk(string);
    bool is_dead();
};

class Account {
    // attributes
    string name {"Account"};
    double balance {0.0};
    
    // methods
    bool deposit(double);
    bool withdraw(double);
    
};


int main() {
//    // objects of the class Account 
//    Account frank_account;
//    Account jim_account;
    
    
    //objects of the class Player 
    Player frank;
    Player hero;
    
    // declaring an array of type class that will have two objects of type class 
    Player players[] {frank, hero};
    
    vector<Player> player_vec {frank};
    player_vec.push_back(hero);
    
    // a pointer to the heap,
    Player *enemy {nullptr};
    enemy = new Player;
    
    delete enemy;

    return 0;
}