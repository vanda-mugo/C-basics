#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>// it keeps the map for key and variable 
#include <memory>
#include <stdexcept>

#include "Account.hpp"


class AccountCreatorBase 
{
public:
    virtual std::unique_ptr<Account> create() const = 0;
    virtual ~AccountCreatorBase() = default ;
};


//TAccount is the type to be used in this case 
//note by that this is a template class that will public inherit from the AccountCreatorBase
template<class TAccount>
class AccountCreator : public AccountCreatorBase 
{
public:
    std::unique_ptr<Account> create() const override   // create function that returns a std::unique_ptr<Account>  . the pointer returned is of type Account 
    {
        std::unique_ptr<Account> ptr = std::make_unique<TAccount>(); // creates a std::unique_ptr of type Account that will use dynamic polymorphism to return a unique_ptr of type TAccount
        return ptr;
    }
};


class AccountCreatorManager
{
private:
    AccountCreatorManager() = default ;
    AccountCreatorManager(const  AccountCreatorManager &other) = delete;// basically deletes the instance of Account Manager as a result of copying , note that this is a copy constructor 
    AccountCreatorManager& operator=(const AccountCreatorManager &other) = delete; // operator= copy assignment overloading. note that copy assignment works with already created and initialised objects 
    std::map<std::string, std::unique_ptr<AccountCreatorBase>> m_accountCreators ; // map object whose key and value are std::string and value is std::unique_ptr<AccountCreatorBase> of name m_accountCreator
    
public:    
    // note that this is a template method in the AccountManager class returns a void 
    template<class TAccount>
    void registerAccountType(const std::string &typeName )// used only for register
    {
        // creates m_accountCreators[typeName] (Key ): value being std::make_unique<AccountCreator<TAccount>>()
        //note that the registerAccountType basically created an entry into the map which is a private attribute of class AccountManager whose value is an object of type AccountCreator
        m_accountCreators[typeName] = std::make_unique<AccountCreator<TAccount>>();
    }
    
    std::unique_ptr<Account> createAccount(const std::string &typeName ) const
    {
        //find method because the 
        std::map<std::string, std::unique_ptr<AccountCreatorBase>>::const_iterator accountIterator  = m_accountCreators.find(typeName);// using the map to find the type of account . note that this type of account has already been registered by its addition to the map
        // the find method returns an iterator
        // notice the use auto
        //auto accountIterator 
        if(accountIterator != m_accountCreators.end())
        {
            //const std::unique_ptr<AccountCreatorBase>  &ptr =accountIterator->second;// you can 
            const AccountCreatorBase* ptr = accountIterator->second.get();// first is key then second is value 
            if(ptr == nullptr)
            {
                std::stringstream ss;
                ss<<" The key :  "<< typeName <<"was found but the value is Null .";
                throw std::runtime_error(ss.str());
            }
            std::unique_ptr<Account> accountPtr = ptr->create();
            return accountPtr;// an Account 
        }
        else
        {
            std::cerr<<"invalid name :" << typeName<<std::endl;
            std::stringstream ss;
            ss<<"Invalid TypeName : "<<typeName ;
            throw  std::runtime_error(ss.str());
        }
        
    }

    static AccountCreatorManager& instance()
    {
        //returns a static member of the account manager instance having the constructors as private 
        static AccountCreatorManager accountManager;
        return accountManager;
    }
    
};