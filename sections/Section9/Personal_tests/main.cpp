#include <iostream>
using namespace std;

int main() {
    char selection {};// this for one has to be outside the loop for the while loop beneth the loop to be able to actually have the variable in its namespace 
    
    
    
//    do{
//        cout << "enter a character for the loop to evaluate  " << std::endl;
//        cin>>selection;
//        
//        cout<<"This loop evaluates to true and the "<<selection<<" evaluates to true based on the expression"<<endl;
//        if (selection == 'Q')
//            cout<<"As can be observed even though 'Q' was selected, 'q' still hold the expression to be True henceforth the loop still evaluates "<<endl;
//        else if(selection=='q')
//            cout<<"As can be observed even though 'q' was selected, 'Q' still hold the expression to be True henceforth the loop still evaluates "<<endl;
//        else
//            cout<<"This is any other character that is not 'Q' or 'q' that still evaluates to true "<<endl;
//    }while (selection != 'q' || selection != 'Q');
    
    
    while (selection != 'q' || selection != 'Q'){
        cout << "enter a character for the loop to evaluate  " << std::endl;
        cin>>selection;
        
        cout<<"This loop evaluates to true and the "<<selection<<" evaluates to true based on the expression"<<endl;
        if (selection == 'Q')
            cout<<"As can be observed even though 'Q' was selected, 'q' still hold the expression to be True henceforth the loop still evaluates "<<endl;
        else if(selection=='q')
            cout<<"As can be observed even though 'q' was selected, 'Q' still hold the expression to be True henceforth the loop still evaluates "<<endl;
        else
            cout<<"This is any other character that is not 'Q' or 'q' that still evaluates to true "<<endl;
        
    }
    
    
    return 0;
}