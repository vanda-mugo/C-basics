#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Account.hpp"
#include "FixedAccount.hpp"

    std::string FixedAccount::getClassName() 
    {
        static const std::string className = "FixedAccount";
        return className;
    }
    
    void FixedAccount::save( std::ostream &accountStream) //this is a void return save function that expects a reference to an object  of type 
    {

        accountStream<<this->getClassName() <<" "<<this->getName()<<" " << this->getAge() <<" "<<this->getBalance() <<" "<<this->m_interestAnnualTarget<<" "<<m_minimumFixedBalance<<"\n";
    }
    
    void FixedAccount::load(std::istream &accountStream ) 
    {
        std::string className ;
        std::string accountName;
        int age;
        int balance;   
        double fixedTarget;
        int minFixedBalance;
        
        accountStream>>className ; 
        if(className != this->getClassName())
        {
            std::cerr<<" Account::load  invalid class name  "<<className <<" . Expected value of className "<<this->getClassName() <<std::endl;
            return;
        }
        accountStream>>accountName ;
        accountStream>>age;
        accountStream>>balance;
        accountStream>>fixedTarget;
        accountStream>>minFixedBalance;
        
        setName(accountName) ;
        setAge(age) ;
        setBalance(balance) ;
        setTarget(fixedTarget);
        setMinFixedBalance(minFixedBalance);
        
    }
    
    void FixedAccount::balanceAmount()
    {
         if(getBalance() > m_minimumFixedBalance)
        {
             m_interest = m_fixedInterestRate * getBalance();
            setBalance( m_interest + getBalance() );
            Account::balanceAmount();
            std::cout<< "The Fixed account  minimum fixed balance of   "<<m_minimumFixedBalance<< " is exceeded by  "<< getBalance() - m_minimumFixedBalance<<std::endl;
        }
        else
        {
            std::cout<<"Kindly update your fixed account with the following amount to accrue interest :"<<m_minimumFixedBalance - getBalance() <<std::endl;
        }       
    }  
    
    void FixedAccount::withdraw(int amount)
    {
        if((getBalance() - amount) < m_minimumFixedBalance)
        {
                std::cout<< "A minimum of  "<<m_minimumFixedBalance << " is required to maintain this account try a lower withdraw amount" << std::endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }
    
    void FixedAccount::printDetails(std::ostream &os) const 
    {
        Account::printDetails(os);// without the argument we have a stack overflow cause of calling that is recursive
        os<<"FixedAccount::printDetails" <<std::endl;
        os<<" your annual interest target is  "<<m_interestAnnualTarget<<" fixed interest rate  "<<m_fixedInterestRate <<"m,inimum fixed balance  " << m_minimumFixedBalance <<std::endl;
    }

    int FixedAccount::target()
    {
        if( getBalance() > m_interestAnnualTarget)
        {
            std::cout<<"youre interest Annual Target is above target by  :"<< getBalance() - m_interestAnnualTarget<< "\n";
            return getBalance() - m_interestAnnualTarget;
        }
        else
        {
            std::cout<<"youre interest Annual Target is below target by  :"<< getBalance() - m_interestAnnualTarget<< "\n";
            return m_interestAnnualTarget - getBalance();
        }
    }
    
    void FixedAccount::setTarget(double target)
    {
        m_interestAnnualTarget= target;
    }
    
    void FixedAccount::setMinFixedBalance( int fixedBalance)
    {
        m_minimumFixedBalance = fixedBalance;
    }
    
    int FixedAccount::getMinFixedBalance() const 
    {
        return m_minimumFixedBalance;
    }
    
    
    // overloaded constructor example that delegates to the base class constructor 
    FixedAccount::FixedAccount( std::string nameVal, int intVal , int ageVal, int target)
    :Account(nameVal, intVal, ageVal), m_interestAnnualTarget{target}
    {
        //std::cout<<"Overloaded constructor of the Fixed Account class"<< std::endl;
    }
    
    FixedAccount::~FixedAccount()
    {
        //std::cout<<"Destructor for the Fixed Account class"<<std::endl;
    }
