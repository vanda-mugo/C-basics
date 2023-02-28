#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Account
{
    
private:
    std::string m_name;
    int m_balance;
    int m_age;
    
public :
//    friend class AccountManager;
        
    virtual std::string getClassName();    
    virtual void save( std::ostream &accountStream);//this is a void return save function that expects a reference to an object  of type 
    virtual void load(std::istream &accountStream ) ;
    int getAge() const;
    void setAge( int age);
    int getBalance() const;
    void setBalance( int balance );
    const std::string& getName() const;  
    void setName( const std::string& name); 
    virtual void balanceAmount();
    virtual void withdraw(int amount);
    virtual void printDetails(std::ostream &os)const;
    virtual int target();
    virtual void setTarget(double target);

    
    Account();    
    Account( std::string nameVal, int intVal , int ageVal);
    virtual ~Account();

};

//operator overloading for the operator<<
std::ostream &operator<<(std::ostream &os , const Account &account);


