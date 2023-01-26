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
// the string through constructor initialisation was made in such a way as to point no where since its nullptr
// within the constructor body what happens is that the value of the str which is a pointer of character type is assigned to str dynamically 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];// note by that str is a pointer to the character objecy in this case 
            std::strcpy(str, s);// what this does is copy the value of the s which is a constant character  pointer . note by that this is a pointer to a constant 
            // the content of s are copied to str in this case . 
            // this is the strcpy() function syntax
            //strcpy( char* dest, const char* src );
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
     : str{nullptr} {
        str = new char[std::strlen(source.str )+ 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
 const char *Mystring::get_str() const { return str; }




