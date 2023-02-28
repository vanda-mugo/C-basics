#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Account.hpp"

class CheckingAccount : public Account {
    using Account::Account;
private:
    int m_checkingTarget{0}; // this is to just show that at some point the constructor of the checking class would be called 
    int m_minCheckingbalance {1000};
public:
    std::string getClassName() override
    {
        static const std::string className = "CheckingAccount";
        return className;
    }
    
    void save( std::ostream &accountStream) override//this is a void return save function that expects a reference to an object  of type 
    {

        accountStream<<this->getClassName() <<" "<<this->getName()<<" " << this->getAge() <<" "<<this->getBalance() <<" "<<this->m_checkingTarget<<" "<<m_minCheckingbalance<<"\n";
    }
    
     void load(std::istream &accountStream ) override
    {
        std::string className ;
        std::string accountName;
        int age;
        int balance;    
        double checkingTarget;
        int minCheckingBalance;
        
        accountStream>>className ; 
        if(className != this->getClassName())
        {
            std::cerr<<" Account::load  invalid class name  "<<className <<" . Expected value of className "<<this->getClassName() <<std::endl;
            return;
        }
        accountStream>>accountName ;
        accountStream>>age;
        accountStream>>balance;
        accountStream>>checkingTarget;
        accountStream>>minCheckingBalance;
        
        setName(accountName) ;
        setAge(age) ;
        setBalance(balance) ;
        setTarget(checkingTarget);
        setMinCheckingBalance(minCheckingBalance);
        
        
    }
    
    void balanceAmount(){
        if(getBalance() <m_minCheckingbalance){
            std::cout<< "The remaining balance for the checking account should not go below 1000 and currently is"<< getBalance()<<"\n";
            std::cout<<"Kindly update your account with the above amount "<<m_minCheckingbalance -getBalance()  <<std::endl;
        }
        else{
            std::cout<< "Your checking account has a balance of the above "<<std::endl;
            Account::balanceAmount();
        }
    }
    
    void withdraw(int amount){
        if((getBalance() - amount) < m_minCheckingbalance){
                std::cout<< "A minimum of 1000 is required to maintain this account try a lower withdraw amount" << std::endl;
        }
        else{
            Account::withdraw(amount);
        }
    }

    void printDetails(std::ostream &os) const override
    {
        // to override the function 
        Account::printDetails(os);
        os<<"CheckingAccount::printDetails"<<std::endl;
        os<< "Checking account target " << m_checkingTarget <<" and minimum checking balance is " << m_minCheckingbalance <<std::endl;
    }
    
    int target(){
        if( getBalance() > m_checkingTarget){
            std::cout<<"Youre checking is above target by  :"<< getBalance() - m_checkingTarget<< "\n";
            return getBalance() - m_checkingTarget;
        }
        else{
            std::cout<<"Youre checking is below target by  :"<< getBalance() - m_checkingTarget<< "\n";
            return m_checkingTarget - getBalance();
        }
    }
    
    void setTarget(double target)
    {
        m_checkingTarget= target;
    }
    
    void setMinCheckingBalance( int checkingBalance)
    {
        m_minCheckingbalance = checkingBalance;
    }
    
    int getMinCheckingBalance() const
    {
        return m_minCheckingbalance;
    }
    CheckingAccount( std::string nameVal, int intVal , int ageVal, int target)
    : Account(nameVal, intVal , ageVal) ,m_checkingTarget{target}{
        //std::cout<<"Overloaded checking account class constructor "<< std::endl;
    }
    
    ~CheckingAccount(){
        //std::cout<<"Destructor for the Checking Account class"<<std::endl;
    }

};