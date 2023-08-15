#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Account.hpp"

class CheckingAccount : public Account
 {
    using Account::Account;
private:
    int m_checkingTarget{0}; // this is to just show that at some point the constructor of the checking class would be called 
    int m_minCheckingbalance {1000};
public:
    std::string getClassName() override;
    void save( std::ostream &accountStream) override ;//this is a void return save function that expects a reference to an object  of type 
    void load(std::istream &accountStream ) override;
    void balanceAmount();
    void withdraw(int amount);
    void printDetails(std::ostream &os) const override;
    int target();
    void setTarget(double target);
    void setMinCheckingBalance( int checkingBalance);
    int getMinCheckingBalance() const;
    CheckingAccount( std::string nameVal, int intVal , int ageVal, int target);
    ~CheckingAccount();
};