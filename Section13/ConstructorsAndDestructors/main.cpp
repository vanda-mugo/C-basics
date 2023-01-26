// Section 13
// Constructors and Destructors

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
    void set_name(std::string name_val) { 
        name = name_val; 
    }
    // Overloaded Constructors
    Player() { 
        cout << "No args constructor called"<< endl;
    }
    Player(std::string name) { 
        cout << "String arg constructor called"<< endl;
    }
    Player(std::string name, int health, int xp) {
        cout << "Three args constructor called"<< endl; 
    }
    
    // this is a destructor that is called when the object is destroyed
    ~Player() { 
        cout << "Destructor called for " << name << endl; 
    }
};

int main() {

    
    // in this main when creating this class objects you realise that the constructor responsible for the specified object is the one that is called 
    // notice that this objects are local to the blocks they are created in, in this case when the block ends the destriuctor is called for the said objects 
    // the destructor is same for all the members of the class
    // the order for destruction of the objects when they come out of scope is that the last to be declared is the first to be destroyed when the objects go out of scope
    {
        Player slayer;
        slayer.set_name("Slayer");
    }
    
    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");
    }
    
    Player *enemy = new Player;
    enemy->set_name("Enemy");
    
    Player *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");
    
    // explicit deletion of the objects being created 
    delete enemy;
    delete level_boss;
    
    return 0;
}

