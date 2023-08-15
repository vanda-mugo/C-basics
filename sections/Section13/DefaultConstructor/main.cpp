// Section 13
// Default Constructors
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
    std::string get_name() {
        return name;
    }
    // in this case the user must explicitly define the default constructor cause another constructor was initialiased , in the case such as above 
    // inorder to create class objects with no parameters a default constructor must be explicitly defined for the said class 
    // otherwise if another constructor is declared that needs parameters c++ no longer automatically provides a default constructor 
    // this here is a user defined default/ no args constructor 
    Player() {
        name = "None";
        health = 100;
        xp = 3;
    }
    // this is a constructor that requires arguments when creating said objects in this case 
    Player(std::string name_val, int health_val, int xp_val) {
        name = name_val;
        health = health_val;
        xp = xp_val;
    }
    
};

int main() {
    Player hero;
    Player frank {"Frank", 100, 13};
    frank.set_name("Frank");
    cout << frank.get_name() << endl;
    return 0;
}

