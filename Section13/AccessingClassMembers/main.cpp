// Section 13
// Accessing Class Members
#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    // attributes
    string name;
    int health;
    int xp;
    
    // methods
    void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  }
    bool is_dead();
};

class Account {
public:// making this attributes Public 
    // attributes
    string name;
    double balance;
    
    // methods
    bool deposit(double bal) {balance += bal; cout << "In deposit" << endl; }
    bool withdraw(double bal) {balance -= bal; cout << "In withdraw" << endl;  }
    
};

int main() {
    Account frank_account;
    frank_account.name = "Frank's account";// this is actually assigning the value to the Account object Frank , the value in this case is for the attribute in this case name 
    frank_account.balance = 5000.0;
    
    frank_account.deposit(1000.0);
    frank_account.withdraw(500.0);
    
    
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");
    
    Player *enemy = new Player;// in this case this is a pointer to an object of class Player whose name is enemy. this pointer is dynamically  placed on the heap
    (*enemy).name = "Enemy";// you have to dereference and also use parenthesis since (.) has higher precedence than the (*)
    (*enemy).health = 100;
    enemy->xp = 15;// using the member of pointer operator, note that this is one only for pointer object 
    
    enemy->talk("I will destroy you!");
    


    return 0;
}

