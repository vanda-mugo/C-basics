// Section 13
// Implementing member methods 1 
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    // attributes
    // the above are private attributes not to be accessed out side a class
    string name;
    double balance;
    
public:
    // methods
    // declared inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }
    
    // methods will be declared outside the class declaration
    // this are basically method prototypes , they will be defined outside the class 
    void set_name(string n);
    string get_name();
    
    bool deposit(double amount);
    bool withdraw(double amount);
};

// for methods declared outside the class the method name has to be prefixed with the class that they are related to plus the scope resolution operator 
// in this case this is Account::
//note by that in this case name was one of the attributes of the class and even though private the public methods from within the class can access this variable  
// this is because the set_name is a member method 
void Account::set_name(string n) {
    name = n;
}

// method declared outside the class it is attached to
// since method is a member method what happens is that it will have access to private attrbutes in this case it will have access to name 
string Account::get_name() {
    return name;
}

// method declared outside the class 
// has access to the private variable in this case balance
bool Account::deposit(double amount) {
    // if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance-amount >= 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}


int main() {
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);
    
    if (frank_account.deposit(200.0))
        cout << "Deposit OK" << endl;
    else 
        cout << "Deposit Not allowed" << endl;
        
    if (frank_account.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
        
    if (frank_account.withdraw(1500.0))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
    
    return 0;
}

