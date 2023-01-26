#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout<<"copy assignment"<<std::endl;
    if(this == &rhs)// comparing to check if we are self copying . that is if the pointer or address this is the same as the &rhs address then dereferenced this is returned 
        return *this;
        
        //deallocate space storage for this-> str since we are overwriting it  
        delete [] this->str; // note  by that objects of this class have the pointer variable str which is of type char. this is or can be thought of well as array since the first element of an array is the mem
        // location of the first element 
        // the value of an array name is the address of the first element in the array 
        str = new char[std::strlen(rhs.str) +1];//  in this case here the str since it was deallocated in the previous line, the str value is changed to hold a dynamic memory location 
        // whose content is of type character + the null ending in c style strings 
        //note  by now that in this line the value of str is changed to hold the the address of a dynamic memory array of type character 
        // therefore the content of the str value is a memory location rather not the content represented by this string character 
        std::strcpy(this ->str , rhs.str);// here we have also used member of the pointer operator which dereferences this and applies the str dot object 
        // in this line the content value of the rhs.str  which is the string is copied to the str memory address where there is a character array in the heap that can accomodate the value and lenght 
        // of the string being passed on to it 
        //very important to note that the rhs in the copy assignment operator is an L value and therefore the rhs.str refers to the str pointer for the object passed as teh rhs
        return *this;// dereferenced right hand variable in this case str
        
}
        

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }




