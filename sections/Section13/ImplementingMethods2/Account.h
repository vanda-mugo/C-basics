// note by declaration of the class occurs in this header file
// note by that this header file is the one that is included in the main.cpp file 
// the header file may have method prototypes for methods that are declared in the Account.cpp file which in this case will have the implementation of the same

#ifndef _ACCOUNT_H_ // preprocessor directive that checks if the _ACCOUNT_H_ has already been declared, if already defined moves to endif
#define _ACCOUNT_H_ // if  not defined this defines it and declares the class 

#include <string>

class Account {
private:
    // attributes
    std::string name;
    double balance;
    
public:
    // methods
    // declared inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }
    
    // methods will be declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();
    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _ACCOUNT_H_
