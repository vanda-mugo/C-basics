#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string. a character array
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);       // Copy assignment overloading the assignment operator to work on the class objects in this case which are user defined 
    //in this case we are overloading the equal or the assignment operator and Mystring in this case is the right object and rhs is the object we are assigning 
    
    void display() const;

    int get_length() const;                                       // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_


 
        
