// Section 9
// Do-while
// Simple Menu Example
#include <iostream>


using namespace std;

int main() {
    
    char selection {};
    do {
        cout << "\n---------------------" << endl;
        cout << "1. Do this" << endl;
        cout << "2. Do that" << endl;
        cout << "3. Do something else" << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;
        //you can use a switch case statement in this to define the logic of what happens 
        
//        if (selection == '1')
//            cout << "You chose 1 - doing this" << endl;
//        else if (selection == '2') 
//             cout << "You chose 2 - doing that" << endl;
//        else if (selection == '3')
//            cout << "You chose 3 - doing something else" << endl;   
//        else if (selection == 'Q' || selection == 'q')
//            cout << "Goodbye..." << endl;
//        else 
//            cout << "Unknown option -- try again..." << endl;

//         lets try and use the switch case logic
            switch (selection){
                case '1' : cout<<"You chose 1 - doing this"<<endl; break;
                case '2':cout<<"You chose 2 - doing that"<<endl; break;
                case '3':cout<<"You chose 3 - doing something else"<<endl; break;
                case 'Q':
                case 'q':cout<<"Goodbye..."<<endl; break;
                default:cout<<"Unknown option -- try again..." << endl;
            }
    
    } while ( selection != 'q' && selection != 'Q');
    // basically what the while does is that it checks for the input by user and compares them to set expression
    // that is if the value entered by user in this case is not "Q" or "q" then this loop will continue to iterate
    // when the user inputs either the Q or q then the while(selection != 'q' && selection !='Q'); is false
    // recall that for the and && both statements have to be true for the expression to evaluate a bool of true
    // otherwise with the and if either one of the above evaluates to false then the whole selection evaluates to a false 
    // when the while loop evaluates to a false then then the do while loop stops loopuing 
    // in case you thought of thr logic of while(selection != 'q'  || selection != 'Q'); this logic would fail cause of the reason above 
    // in that in the case that the user entered lower 'q' this means that in the expression the while loop evaluates to true either if or if one of the value evaluates to true
    // ?? what does this mean you ask when a lower 'q' is selected the statement still evaluates to true since one of the conditions in this case selection != 'Q' will still be true
    // so for the while logic to work its imperative to understand that whatever selection was chosen has not to be 'q' or 'Q' AND IF THE SELECTION IS EITHER OF THE ABOVE
    // THE AND IN THE WHILE LOOP EXPRESSION FAILS AND RESULTS IN A FALSE     
    
    cout  << endl;
    return 0;
}

