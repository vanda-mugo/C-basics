#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

#include "SavingAccount.hpp"
#include "FixedAccount.hpp"
#include "CheckingAccount.hpp"
#include "Account.hpp"
#include "AccountManager.hpp"
#include "AccountCreatorManager.hpp"


void loadAccountsFromFile(const std::string pathToFile)
{
    
    std::cout<<"\n \nReading File"<<std::endl;
    std::string fileline ;
    std::string accountType;
    // reading data 
    std::ifstream accountInStream{pathToFile};
    
    while(std::getline(accountInStream , fileline))
    {              
        std::cout<<"Loading the above line : "<<fileline<<std::endl;
        std::stringstream ss(fileline);
        std::string typeName;
        ss>>typeName;
        std::string accountName;
        ss>>accountName;
        std::cout<<accountName<<std::endl;
        int age;
        ss>>age;
        std::cout<<age<<std::endl;
        int balance;
        ss>>balance;
        std::cout<<balance<<std::endl;
        //Account *account  = AccountManager::instance().create(typeName  , fileline);
        //account->printDetails();
        //delete account;
        
    }
            

            
}
    

int main()
{
    AccountCreatorManager::instance().registerAccountType<Account>("Account");// note by that with this AccountManager::instance() creates an object by singleton of type AccountManager. the registerAccountType<Account>("Account") just adds this type of Account into the Map 
    AccountCreatorManager::instance().registerAccountType<FixedAccount>("FixedAccount"); 
    AccountCreatorManager::instance().registerAccountType<CheckingAccount>("CheckingAccount"); 
    AccountCreatorManager::instance().registerAccountType<SavingAccount>("SavingAccount"); 
    
    auto& accountManager = AccountManager::instance();

    auto account1= std::make_unique<Account>("Allan" , 600, 30);
    auto account2= std::make_unique<FixedAccount>("Elsie" , 12370, 30,96000);
    auto account3= std::make_unique<CheckingAccount>("kayman" , 42370, 24, 26000);
    auto account4= std::make_unique<SavingAccount>("john" , 123700, 27, 76000);
    
    account2->setMinFixedBalance(80000);
    account3->setMinCheckingBalance(7000);
    account4->setMinSavingBalance(9000);
   
   accountManager.addAccount(std::move(account1));
   accountManager.addAccount(std::move(account2));
   accountManager.addAccount(std::move(account3));
   accountManager.addAccount(std::move(account4));
   
   std::string filename =  "C:\\Users\\25479\\Documents\\doc3.txt";
   std::ofstream os{filename };
   
   accountManager.saveAccounts(os);
   accountManager.saveAccounts(std::cout);
   os.close();
   
   std::ifstream is{filename};
   accountManager.loadAccounts(is);
   std::cout<<"*******************"<<std::endl;
   accountManager.saveAccounts(std::cout);
   
   
std::cout<<"Debug"<<std::endl;
}
