#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string.note by that this are the attributes associated with members of the class
    
public:
    Mystring();                                            // No-args contstructor definition alone 
    Mystring(const char *s);                         // Overloaded contstructor   1 arg constructor  . the type in this case is a pointer and the type stored is a character. character pointer       
    Mystring(const Mystring &source);        // Copy constructor this are the prototypes for the said constructors 
    ~Mystring();                                          // Destructor
    void display() const;
    int get_length() const;                           // getters
    const char *get_str() const;
  
};

#endif // _MYSTRING_H_
