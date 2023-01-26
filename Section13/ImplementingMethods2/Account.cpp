// the include in " " is for header files that are local to project 
#include "Account.h"clTabCtrl

// declaring the methods outside of the class in this case
// must have class name plus scope resolution operator
void Account::set_name(std::string n) {
    name = n;
}

std::string Account::get_name() {
    return name;
}

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
