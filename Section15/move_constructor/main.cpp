// C++ program without declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declaring the raw pointer as
	// the data member of the class
	int* data;

public:
	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
        // in the below line the value of data which is a pointer is assigned to a memory location on the heap 
        //then the dereferenced pointer in this case *data is assigned to be equal to the value of d 
        // note by a pointer is a variable whose value is an address in memory therefore data in this case the address will be the dynamic memory on the heap that is 
        // dynamic memory on the heap that is of type int 
        
		*data = d;

		cout << "Constructor is called for "
			<< d << endl;
	};

	// Copy Constructor to delegated
	// Copy constructor
	Move(const Move& source)
    // note by here const is for the source which in this case is an L value and shouldnt be changed 
    // in the constructor initialisation list what is happening is that the delegation of the move overloaded costructor is occuring and what this does is that 
    //the overloaded move constructor is called and the value for which is expected is placed as source which in this case is the l value being copied from 
		: Move{ *source.data }
	{

		// Copying constructor copying
		// the data by making deep copy
		cout << "Copy Constructor is called - "
			<< "Deep copy for "
			<< *source.data
			<< endl;
	}

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If the pointer is not
			// pointing to nullptr
			cout << "Destructor is called for "
				<< *data << endl;
		else

			// If the pointer is
			// pointing to nullptr
			cout << "Destructor is called"
				<< " for nullptr"
				<< endl;

		// Free the memory assigned to
		// data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Create vector of Move Class
	vector<Move> vec;

	// Inserting object of Move class
	vec.push_back(Move{ 10 });
	vec.push_back(Move{ 20 });
	return 0;
}




//        
//        std::string x[10];
//        int i = 0;
//        std::string fileLine;
//        while(!accountStream.eof())
//        {
//            std::getline(accountStream, fileLine);
//            x[i++] = fileLine;
//        }
//        
//        className = x[1];
//        accountName = x[2];
//        std::stringstream(x[3]) >>age;
//        std::stringstream(x[4]) >>balance;
//        
//        Account accountObj{accountName , balance, age};
//        accountObj.printDetails();
        
//        if(!accountStream)
//        {
//            std::cerr<<"cannot open the indicated file  "<<std::endl;
//            exit(-1);
//        }
//        
//        else
//        {
//            //file stream to read
//            Account accountObj;
//            while( std::getline(accountStream , fileLine))
//            {
//                std::cout<<fileLine<<std::endl;
//                
//            }
//        }



        //accountStream.close();
        //        if(accountStream.is_open() )
        //        {
        //            std::cout<<"stream could not close "<<std::endl;
        //            // this stream could be called in the destructor 
        //        }
                //std::ofstream 
        //explanation of the above 
        // note that in this case the the & fileName which is a reference to a constant variable of type std::string. note by that in this case filename is an alias of whatever
        // l value variable that will be passed in this function 
        //file stream for write 
        // an ofstream object to write to class 
        //accountStream.write((char*)this , sizeof(this));
        
                
        
        



