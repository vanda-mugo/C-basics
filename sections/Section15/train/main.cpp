#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

// Student class
class Student {
    
private:
    string id;
    string lname;
    string fname;
    int    age;
    int    phone;

public:
    void setId(string);
    void setLname(string);
    void setFname(string);
    void setAge(int age);
    void setPhone(int);
    
    string getId() const;
    string getLname() const;
    string getFname() const;
    int    getAge() const;
    int    getPhone() const;
    
    friend std::istream & operator >> (std::istream & is, Student & s);
    
};

// Student setter methods
void Student::setId(string student_id)    { id    = student_id;    }
void Student::setLname(string last_name)  { lname = last_name;     }
void Student::setFname(string first_name) { fname = first_name;    }
void Student::setAge(int student_age)     { age   = student_age;   }
void Student::setPhone(int student_phone) { phone = student_phone; }

// Student getter methods
string Student::getId()    const { return id;    }
string Student::getLname() const { return lname; }
string Student::getFname() const { return fname; }
int    Student::getAge()   const { return age;   }
int    Student::getPhone() const { return phone; }


std::ostream & operator << (std::ostream & os, const Student & s)
{
    os << s.getId()    << ' '
       << s.getLname() << ' '
       << s.getFname() << ' '
       << s.getAge()   << ' '
       << s.getPhone();   
    return os; 
}

std::istream & operator >> (std::istream & is, Student & s)
{
    is >> s.id >> s.lname >> s.fname >> s.age >> s.phone;
    return is;
}

int main ()
{
    Student student_array[MAX_SIZE];

    // populate student_array
    ifstream Studentfile("C:\\Users\\25479\\Documents\\doc3.txt");
    if (Studentfile.fail())
    {
        cout << "File was not found\n";
        system ("PAUSE");
        exit(1);
    }
        
    Studentfile.ignore(100,'\n');
    int index = 0;
    
    while ( index < MAX_SIZE && Studentfile >> student_array[index] )
    {
        index++;
    }
    
    Studentfile.close();
    
    for (int i=0; i<index; ++i)
    {
        cout << student_array[i] << '\n';
    }
    
    system("PAUSE");
    return 0;
}