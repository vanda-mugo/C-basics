#include <iostream>
#include <cstring>      // for c-style string functions
#include <cctype>       // for character-based functions

using namespace std;    

int main()
{
    //note that this strings which are sequences of characters are implemented as arrays in the c type strings
    // when therefore declaring them we do so as arrays 
    char first_name[20];// declared the array called first_name  and in this case no initialisation was done for the same 
    // the rest of the string arrays have been initialised to 0
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};
    
    //cout << first_name;     // Will likely display garbage! this is because this is still very not initialised and therefore cannot predict what is stored in this part of memory

    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Please enter your last name: ";
    cin >> last_name;
    cout << "-------------------------------" << endl; 
    
    cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters" << endl;
    // note by that the string lenght function starts at index 1 and not 0
    cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters" << endl;

    strcpy(full_name, first_name);          // copy first_name to full_name
    strcat(full_name, " ");                       // concatenate full_name and a space , basically adds space to so far full name 
    strcat(full_name, last_name);           // concatenate last_name to full_name
    cout << "Your full name is " << full_name << endl;

    cout << "-------------------------------" << endl;
    cout << "Enter your full name: ";
    cin >> full_name;

    cout << "Your full name is " << full_name << endl;// this output will only be usually the first name since the compiler will stop 
    // when it comes across whitespace characters in the full name inserted 

    cout << "Enter your full name: ";
    cin.getline(full_name, 50); // basically this tels the compiler how many characters in the array can be assigned full name hencforth in the case of white space 
    // in case of white space the full name will still be evaluated fully even with the whitespace so long as it is below 50 characters 
    // the getline() function is a function that extracts the characters from the input stream and appends it to the string object until the delimiting character is encountered 
    // note by the getline is important since any whitespace the c++ compiler assumes that any white space terminates the program when getting the input    
    
    // this could also stand in the case of the getline 
    string full_name_string;
    getline(cin, full_name_string);
    
    // we can also use the delimiter in this case 
    
    cin.getline(full_name, 50, '$');
    // in the case above the '$' is a delimiter , this basically tells the function to stop reading the input     
    
    cout << "Your full name is " << full_name << endl;

    cout << "-------------------------------" << endl;
    strcpy(temp, full_name);
    if(strcmp(temp, full_name) == 0)// basically if the two inputs that is the two character strings are the same then the return is 0
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;
        
    cout << "-------------------------------" << endl;
    
// for the for loop to follow above please note the use of size_t and also the string length which starts from 1, henceforth if 
// i is initialised to 0, this means that for i to be equal to the length of the string which starts at 0, i is terminated when its less that the length of the string by 1
    for(size_t i{ 0 }; i < strlen(full_name); ++i) {
        if(isalpha(full_name[i])) // isalpha checks whether the character is a letter, basically iterating through each character in the full name string to check if it fits to be a letter 
            full_name[i] = toupper(full_name[i]); // assigning the character at said index i to be equal to its uppercase value 
    }
    cout << "Your full name is " << full_name << endl;


    cout << "-------------------------------" << endl;
    if(strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;

    cout << "-------------------------------" << endl;
    cout << "Result of comparing " << temp << " and " <<  full_name <<  ": " << strcmp(temp, full_name) << endl;
    cout << "Result of comparing " << full_name << " and " <<  temp <<  ": " << strcmp(full_name, temp) << endl;

    cout  << endl;
    return 0;
}
