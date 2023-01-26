 #include <iostream>
#include "Account.h"

// this is a no args constructor 
Account::Account()  
    :  balance{0.0}, name{"An Account"} {
}

// destructor for the class Account 
Account::~Account()
{
}

// method in the class Account called deposit 
void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount  << std::endl;
}

// Account class withdraw method 
void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}
