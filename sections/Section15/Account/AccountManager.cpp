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
#include <algorithm>
#include <cstdio>

#include "Account.hpp"
#include "AccountCreatorManager.hpp"
#include "AccountManager.hpp"


void AccountManager::addAccount(std::unique_ptr<Account> &&accountPtr )// force the pointer to be moved using the R reference
{
    m_accounts.push_back(std::move(accountPtr));
}

void AccountManager::removeAccount(Account* accountPtr)
{
    auto accountIterator = m_accounts.begin();
    for( ; accountIterator != m_accounts.end() ; ++accountIterator)
    {
        if(accountPtr == accountIterator->get())
        {
            break;
        }
    }
    
    if(m_accounts.end() !=accountIterator)
    {
        m_accounts.erase(accountIterator);
    }
    
//        std::remove(m_accounts.begin() , m_accounts.end() , accountPtr);// this function moves the specific item to the end of the vector 
//        m_accounts.pop_back();// removes last element from the vector 
}

void AccountManager::saveAccounts(std::ostream &os) const
{
    //std::vector<std::unique_ptr>::const_iterator  accountIterator;
    //for(const auto &item : m_accounts)
    for(auto accountIterator = m_accounts.begin() ; accountIterator != m_accounts.end() ; ++accountIterator)// dont increase itrerator when used in an argument //divide(++a , ++a);  such is the case
    {
        if( *accountIterator != nullptr)
        {
            (*accountIterator)->save(os); 
        }
        else
        {
            throw std::runtime_error("The account pointer is null ");
        }
            
            
    }
}

void AccountManager::loadAccounts(std::istream &is)
{
    m_accounts.clear();
    std::string fileLine;
    while(std::getline(is , fileLine))
    {
        std::string className ;
        std::stringstream ss{fileLine};
        //std::cout<<fileLine<<std::endl;
        ss>>className;
        std::unique_ptr<Account> accountObj=AccountCreatorManager::instance().createAccount(className);
        //std::cout<<className<<std::endl;
        
        ss.seekg(std::ios_base::beg);
        accountObj->load(ss);
        m_accounts.push_back(std::move(accountObj));
        
    }
    
    
}

AccountManager& AccountManager::instance()
{
    //returns a static member of the account manager instance having the constructors as private 
    static AccountManager accountManager;
    return accountManager;
}
    


//create specific accounts using account manager and check whether type is as expected 
// think of how to dynamicly create types when reading from the account manager 
// method to save and to load to use this create account method for account manager
// make account manager to something that can store account 
//store the accounts run time saving and storing  
//separate container

//a function to add and to remove account 


// create AccountCreatorManager class that is singleton for the sole purpose to create account, method to register this and to create 
//  remove creation from Account Manager 

//task 24 feb 2023

// add remaining fields . have the methods for set and get for the fixed, checking and saving  account 
//moving cmake
//create the visual studio solution using cmake 