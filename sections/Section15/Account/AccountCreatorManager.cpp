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
#include "AccountCreatorManager.hpp"

    
std::unique_ptr<Account> AccountCreatorManager::createAccount(const std::string &typeName ) const
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

AccountCreatorManager& AccountCreatorManager::instance()
{
    //returns a static member of the account manager instance having the constructors as private 
    static AccountCreatorManager accountManager;
    return accountManager;
}

