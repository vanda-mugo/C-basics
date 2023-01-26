#include <iostream>
#include <string>
#include <vector>

class Account
{
public :
    std::string name;
    int balance;
    int age;
    
    virtual void balanceAmount(){
        std::cout<<"The balance in the account is  :" << std::endl;
        
    }
    virtual void withdraw(int amount)
    {
        balance-=amount;
        std::cout<< "The amount withdrawn is equal to  : "<<amount<< "and balance remaining is  :"<< balance<<std::endl;
        
    }

    virtual void printDetails()
    {
        std::cout<<"Name registered under the checking account is  :" << name <<"   age  :" << age<< "   balance :" << balance <<std::endl;
        std::cout<< "Method called from Acoount Class"<< std::endl;
        
    }
    
    virtual int target(){
        std::cout<<"Method will be implemented in the derived classes"<<std::endl;
         return 0;
    }
    
    Account()
    : name{"Generic Account"}, balance{0} , age{0} 
    {
        std::cout<<"Such an account is only for experimental purposes for base Account class  " << std::endl;
    } 
    
    Account( std::string nameVal, int intVal , int ageVal)
    :name{nameVal}, balance{intVal} , age{ageVal} 
    {
        std::cout<<"Overloaded constructor of the base Account class"<< std::endl;
    }
    
    ~Account(){
        std::cout<<"Destructor for the Account class"<<std::endl;
    }
    
};

class CheckingAccount : public Account {
    using Account::Account;
private:
    int checkingTarget{0}; // this is to just show that at some point the constructor of the checking class would be called 
public:
   int minCheckingBalance {1000}; 
    
    void balanceAmount(){
        if(balance <minCheckingBalance){
            std::cout<< "The remaining balance for the checking account should not go below 1000 and currently is"<< balance<<"\n";
            std::cout<<"Kindly update your account with the above amount "<<minCheckingBalance - balance<<std::endl;
        }
        else{
            std::cout<< "Your checking account has a balance of the above "<< balance<<std::endl;
        }
    }
    
    void withdraw(int amount){
        if((balance - amount) < minCheckingBalance){
                std::cout<< "A minimum of 1000 is required to maintain this account try a lower withdraw amount" << std::endl;
        }
        else{
            balance -=amount;
            std::cout<<"The remaining balace in the account is  :" << balance<<std::endl;
        }
    }

    void printDetails(){
        // to override the function 
        std::cout<<"Name registered under the checking account is  :" << name <<"   age  :" << age<< "   balance  :" << balance <<std::endl;
        std::cout<< "Method called from Checking Acoount Class"<< std::endl;
    }
    
    int target(){
        if( balance > checkingTarget){
            std::cout<<"Youre checking is above target by  :"<< balance -checkingTarget<< "\n";
            return balance -checkingTarget;
        }
        else{
            std::cout<<"Youre checking is below target by  :"<< balance -checkingTarget<< "\n";
            return checkingTarget- balance;
        }
    }
    
    CheckingAccount( std::string nameVal, int intVal , int ageVal, int target)
    : Account(nameVal, intVal , ageVal) ,checkingTarget{target}{
        std::cout<<"Overloaded checking account class constructor "<< std::endl;
    }
    
    ~CheckingAccount(){
        std::cout<<"Destructor for the Checking Account class"<<std::endl;
    }

};

class SavingAccount : public Account {
    //this class shall explicitly inherit the constructors in the Account class 
private:
    int savingsAnnualTarget{0};
public:
    int minSavingBalance = 7000;
    
    void balanceAmount(){
         if(balance > minSavingBalance){
            std::cout<<"Saving account balance is  :" << balance <<" and minimum saving balance is exceeded by  :"<< balance-minSavingBalance<<std::endl;
        }
        else{
            std::cout<<"Kindly update your savings account with the following amount  :"<<minSavingBalance - balance <<std::endl;
        }       
    }
    
    void withdraw(int amount){
        if((balance - amount) < minSavingBalance){
                std::cout<< "A minimum of 7000 is required to maintain this account try a lower withdraw amount" << std::endl;
        }
        else{
            balance -=amount;
            std::cout<<" The remaining balace in the account is  :" << balance<<std::endl;
        }
    }
    
    void printDetails(){
        std::cout<<"Name registered under the checking account is  :" << name <<"   age  :" << age<< "   balance :" << balance <<std::endl;
        std::cout<< "Method called from SavingAccount Class"<< std::endl;
    }
    
    int target(){
        if( balance > savingsAnnualTarget){
            std::cout<<"Youre Saving Annual is above target by  :"<< balance -savingsAnnualTarget<< "\n";
            return balance -savingsAnnualTarget;
        }
        else{
            std::cout<<"Youre Saving Annual is below target by  :"<< balance -savingsAnnualTarget<< "\n";
            return savingsAnnualTarget- balance;
        }
    }
    
    SavingAccount()
    : Account() 
    {
        std::cout<<"No args constructor for the saving account " << std::endl;
    } 
    
    SavingAccount( std::string nameVal, int intVal , int ageVal)
    :Account(nameVal, intVal, ageVal)
    {
        std::cout<<"Overloaded constructor of the Saving Account class"<< std::endl;
    }
    
    SavingAccount( std::string nameVal, int intVal , int ageVal, int target)
    :Account(nameVal, intVal, ageVal), savingsAnnualTarget{target}
    {
        std::cout<<"Overloaded constructor of the Saving Account class"<< std::endl;
    }
    
    ~SavingAccount(){
        std::cout<<"Destructor for the Saving Account class"<<std::endl;
    }
    
};

class FixedAccount : public Account{
    using Account::Account;// uses constructor in the Account class 
private:
    int interestAnnualTarget{0};
public:
    double fixedInterestRate{0.15};
    int minimumFixedBalance{100000};
    double interest;
  
    void balanceAmount(){
         if(balance > minimumFixedBalance){
             interest = fixedInterestRate * balance;
            balance += interest;
            std::cout<<"Fixed account balance is  :" << balance <<" and minimum fixed balance is exceeded by  :"<< balance-minimumFixedBalance<<std::endl;
        }
        else{
            std::cout<<"Kindly update your fixed account with the following amount to accrue interest :"<<minimumFixedBalance - balance <<std::endl;
        }       
    }  
    
    void withdraw(int amount){
        if((balance - amount) < minimumFixedBalance){
                std::cout<< "A minimum of 100000 is required to maintain this account try a lower withdraw amount" << std::endl;
        }
        else{
            balance -=amount;
            std::cout<<"The remaining balace in the account is  :" << balance<<std::endl;
        }
    }
    
    void printDetails(){
        std::cout<<"Name registered under the checking account is  :" << name <<"   age  :" << age<< "   balance :" << balance <<std::endl;
        std::cout<< "Method called from FixedAccount Class"<< std::endl;
    }

        int target(){
        if( balance > interestAnnualTarget){
            std::cout<<"youre interest Annual Target is above target by  :"<< balance -interestAnnualTarget<< "\n";
            return balance -interestAnnualTarget;
        }
        else{
            std::cout<<"youre interest Annual Target is below target by  :"<< balance -interestAnnualTarget<< "\n";
            return interestAnnualTarget- balance;
        }
    }

    // overloaded constructor example that delegates to the base class constructor 
    FixedAccount( std::string nameVal, int intVal , int ageVal, int target)
    :Account(nameVal, intVal, ageVal), interestAnnualTarget{target}
    {
        std::cout<<"Overloaded constructor of the Fixed Account class"<< std::endl;
    }
    
    ~FixedAccount(){
        std::cout<<"Destructor for the Fixed Account class"<<std::endl;
    }
    
};


int main() {
    std::vector <Account*> classVec;
    // member of checking class
    classVec.push_back(new  CheckingAccount("Allan" , 600, 30, 500));
    // member of class saving account 
    classVec.push_back(new  SavingAccount("Boris" , 13700, 20, 70000));
    // member of fixed amount 
    classVec.push_back(new  FixedAccount("gunther" , 122300, 19, 300022));
    
    for (auto val : classVec){
        val->balanceAmount();
        val->withdraw(30000);
        val->printDetails();
        val->target();
    }
    
    for(auto val : classVec){
        delete val;
    }
    return 0;
}