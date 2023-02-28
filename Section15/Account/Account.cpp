#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Account.hpp"


    std::string Account::getClassName()
    {
        static const std::string className = "Account";
        return className;
        //virtual
    }
    
    void Account::save( std::ostream &accountStream)//this is a void return save function that expects a reference to an object  of type 
    {
        accountStream<<this->getClassName() <<" "<<this->getName()<<" " << this->getAge() <<" "<<this->m_balance <<"\n";
    }
    
    void Account::load(std::istream &accountStream ) 
    {
        std::string className ;
        std::string accountName;
        int age;
        int balance;     
        
        accountStream>>className ; 
        if(className != this->getClassName())
        {
            std::cerr<<" Account::load  invalid class name  "<<className <<" . Expected value of className "<<this->getClassName() <<std::endl;
            return;
        }
        accountStream>>accountName ;
        accountStream>>age;
        accountStream>>balance;
        
        m_name = accountName;
        m_age = age;
        m_balance = balance;
        
        
    }
    
    int Account::getAge() const
    {
//       std::cout<<"Account::getAge"<< m_age << std::endl;
        return m_age;
    }
    
    void Account::setAge( int age)
    {
        m_age = age;
    }
    
    int Account::getBalance() const
    {
        return m_balance;
    }
    
    void Account::setBalance( int balance )
    {
        m_balance = balance;
    }
    
    const std::string& Account::getName() const
    {
        return m_name;
    }
    
    void Account::setName( const std::string& name)
    {
        m_name = name;
    }
    
    void Account::balanceAmount()
    {
        std::cout<<"The balance in the account is  :" <<m_balance<< std::endl;
        
    }
    void Account::withdraw(int amount)
    {
        m_balance-=amount;
        std::cout<< "The amount withdrawn is equal to  : "<<amount<< "and balance remaining is  :"<< m_balance<<std::endl;
        
    }
    
//    virtual void printDetails()const
//    {
//        printDetails(std::cout );
//        std::cout<<"Account::printDetails"<<"\n";
//        std::cout<<"Name registered under the Account is  :" << this->m_name <<"   age  :" << m_age<< "   balance :" << m_balance <<std::endl;
//    }

    void Account::printDetails(std::ostream &os)const
    {
        os<<"Account::printDetails"<<"\n";
        os<<"Name registered under the Account is  :" << m_name <<"   age  :" << m_age<< "   balance :" << m_balance <<std::endl;
    }
    
    int Account::target()
    {
        std::cout<<"Method will be implemented in the derived classes"<<std::endl;
         return 0;
    }
    
    void Account::setTarget(double target)
    {
        std::cout<<"method implemented in derived classes "<<std::endl;
    }
    
    Account::Account()
    : m_name{"Generic Account"}, m_balance{0} , m_age{0} 
    {
        //std::cout<<"Such an account is only for experimental purposes for base Account class  " << std::endl;
    } 
    
    Account::Account( std::string nameVal, int intVal , int ageVal)
    :m_name{nameVal}, m_balance{intVal} , m_age{ageVal} 
    {
        //std::cout<<"Overloaded constructor of the base Account class"<< std::endl;
    }
    
    Account::~Account()
    {
        //std::cout<<"Destructor for the Account class"<<std::endl;
    }
    


//operator overloading for the operator<<
std::ostream &operator<<(std::ostream &os , const Account &account)
{
    account.printDetails(os) ;
    return os;
}

