#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Account.hpp"

class SavingAccount : public Account {
     using Account::Account;
    //this class shall explicitly inherit the constructors in the Account class 
private:
    int m_savingsAnnualTarget{0};
public:
    int m_minSavingBalance = 7000;

    std::string getClassName() override
    {
        static const std::string className = "SavingAccount";
        return className;
    }
    
     void save( std::ostream &accountStream) override//this is a void return save function that expects a reference to an object  of type 
    {

        accountStream<<this->getClassName() <<" "<<this->getName()<<" " << this->getAge() <<" "<<this->getBalance()<<" "<<this->m_savingsAnnualTarget<<" "<<m_minSavingBalance<<"\n";
    }
    
    void load(std::istream &accountStream ) override
    {
        std::string className ;
        std::string accountName;
        int age;
        int balance;  
        double savingTarget;
        int minSavingBalance;
        
        accountStream>>className ; 
        if(className != this->getClassName())
        {
            std::cerr<<" Account::load  invalid class name  "<<className <<" . Expected value of className "<<this->getClassName() <<std::endl;
            return;
        }
        accountStream>>accountName ;
        accountStream>>age;
        accountStream>>balance;
        accountStream>>savingTarget;
        accountStream>>minSavingBalance;
        
        setName(accountName) ;
        setAge(age) ;
        setBalance(balance) ;
        setTarget(savingTarget);
        setMinSavingBalance(minSavingBalance);
        
    }
    
    void balanceAmount()
    {
         if(getBalance() > m_minSavingBalance)
        {
            Account::balanceAmount();
            std::cout<<"Savings account minimum saving balance is exceeded by  :"<< getBalance() - m_minSavingBalance<<std::endl;
        }
        else
        {
            std::cout<<"Kindly update your savings account with the following amount  :"<<m_minSavingBalance - getBalance() <<std::endl;
        }       
    }
    
    void withdraw(int amount)
    {
        if((getBalance() - amount) < m_minSavingBalance){
                std::cout<< "A minimum of 7000 is required to maintain this account try a lower withdraw amount" << std::endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }
    
    void printDetails(std::ostream &os) const override
    {
        Account::printDetails(os);
        os<<"SavingAccount::printDetails" << std::endl;
        os<<"The annual saving target is  "<<m_savingsAnnualTarget<<" and the minimum saving balance is  "<<m_minSavingBalance<<std::endl;
    }
    
    int target()
    {
        if( getBalance() > m_savingsAnnualTarget)
            {
            std::cout<<"Youre Saving Annual is above target by  :"<< getBalance() - m_savingsAnnualTarget<< "\n";
            return getBalance() - m_savingsAnnualTarget;
        }
        else
            {
            std::cout<<"Youre Saving Annual is below target by  :"<< getBalance() -m_savingsAnnualTarget<< "\n";
            return m_savingsAnnualTarget - getBalance();
        }
    }
    
    void setTarget(double target)
    {
        m_savingsAnnualTarget= target;
    }
    
    void setMinSavingBalance( int savingBalance)
    {
        m_minSavingBalance = savingBalance;
    }
    
    int getMinSavingBalance() const
    {
        return m_minSavingBalance;
    }
    
    
    
    SavingAccount( std::string nameVal, int intVal , int ageVal, int target)
    :Account(nameVal, intVal, ageVal), m_savingsAnnualTarget{target}
    {
        //std::cout<<"Overloaded constructor of the Saving Account class"<< std::endl;
    }
    
    ~SavingAccount(){
        //std::cout<<"Destructor for the Saving Account class"<<std::endl;
    }
    
};