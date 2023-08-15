#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Account.hpp"

class SavingAccount : public Account
 {
using Account::Account;
//this class shall explicitly inherit the constructors in the Account class 
private:
    int m_savingsAnnualTarget{0};
public:
    int m_minSavingBalance = 7000;
    
    std::string getClassName() override;
     void save( std::ostream &accountStream) override;//this is a void return save function that expects a reference to an object  of type 
    void load(std::istream &accountStream ) override;
    void balanceAmount();
    void withdraw(int amount);
    void printDetails(std::ostream &os) const override;
    int target();
    void setTarget(double target);
    void setMinSavingBalance( int savingBalance);
    int getMinSavingBalance() const;
    
    
    SavingAccount( std::string nameVal, int intVal , int ageVal, int target);
    ~SavingAccount();
    
};