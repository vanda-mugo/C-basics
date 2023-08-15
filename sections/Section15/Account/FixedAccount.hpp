#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Account.hpp"

class FixedAccount : public Account{
    using Account::Account;// uses constructor in the Account class 
private:
    int m_interestAnnualTarget{0};
    double m_fixedInterestRate{0.15};
    int m_minimumFixedBalance{100000};
    double m_interest;
public:
    std::string getClassName() override;
    void save( std::ostream &accountStream) override;//this is a void return save function that expects a reference to an object  of type 
    void load(std::istream &accountStream ) override;
    void balanceAmount();
    void withdraw(int amount);
    void printDetails(std::ostream &os) const override;
    int target();
    void setTarget(double target);
    void setMinFixedBalance( int fixedBalance);
    int getMinFixedBalance() const ;
    // overloaded constructor example that delegates to the base class constructor 
    FixedAccount( std::string nameVal, int intVal , int ageVal, int target);
    ~FixedAccount();
};
