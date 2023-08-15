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
#include <algorithm>
#include <cstdio>

#include "Account.hpp"
#include "AccountCreatorManager.hpp"

class AccountManager
{
private:
    AccountManager() = default ;// default no args constructor that is private therefore only accessible from within the class
    AccountManager(const  AccountManager &other) = delete;// basically deletes the instance of Account Manager as a result of copying , note that this is a copy constructor 
    AccountManager& operator=(const AccountManager &other) = delete; // operator= copy assignment overloading. note that copy assignment works with already created and initialised objects 
    std::vector <std::unique_ptr<Account>> m_accounts;  //  single responsibility clause for this class 
public:    
    void addAccount(std::unique_ptr<Account> &&accountPtr );// force the pointer to be moved using the R reference
    void removeAccount(Account* accountPtr);
    void saveAccounts(std::ostream &os) const;
    void loadAccounts(std::istream &is);
    static AccountManager& instance();
    
};
