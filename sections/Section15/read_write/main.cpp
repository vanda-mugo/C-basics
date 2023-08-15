// C++ program to demonstrate read/write of class
// objects in C++.
#include <iostream>
#include <fstream>// file stream which is a sequence of characters moving from the disk to c++ program or from c++ to disk
// moving from program file in the disk is outputting abbreviated as ofstream 
// input filestream is abbreviated by the ifstream 
using namespace std;

// Class to define the properties
class Contestant {
public:
	// Instance variables
	string Name;
	int Age, Ratings;

	// Function declaration of input() to input into file
	int input();

	// Function declaration of output_highest_rated() to
	// extract info from file Data Base
	int output_highest_rated();
};

// Function definition of input() to input info
// implementation of the input function 
int Contestant::input()
/*
 * note that before a stream can be opened, a stream object has to be created . opening a stream means establishing a channel between the c++ program and a file in disk.
 * this is accomplished through which a sequence of characters will to the file or through which a sequence of characters will leave the file and come to the program . or throght which characters move to and fro
 * void open("path/to/and/the/file", ios_base::in);   // this here is the open() member function that  returns a void and is used with the object of fstream that was created (object of stream)
 * 
 * statement used to open the file would in this case be 
 * strm.open("./myfile", ios_base::in);
 * since the open method returns a void we use the following member function 
 * 
 * bool is_open() const;
 * 
 * to use if as 
 * if(strm.is_open(){
 * cout<<"open successfull" endl;
 * }
 * else{
 * cout<<"opening failed "<<endl;
 * return 1;
 * }
 * 
 * to open a file for writing 
 * 
 * strm.open("path/to/and/the/file", ios_base::out);
 * 
 * ios_base::in means to open for reading 
 * ios_base::out means to open for writing 
 * 
 * to open a file for both reading and writing use the following
 * strm.open("path/to/and/the/file", ios_base::in | ios_base::out);
 * 
 * Closing a stream means closing the channel through which data can be sent to and fro between the program and the file. No more datum can be sent in either direction using that channel.
 Closing the stream is not closing the stream object. The same stream can still be used to open a new channel, which should be closed after use in transmission of data.
 Make it a habit of closing any file stream, after it has been opened. When a stream is closed, any data in memory that was supposed to have been in the file is sent to the file before actually closing. 
  * The member function prototype to close fstream is:
  * 
  * void close();
  * 
 */
 
{
	// Object to write in file
	ofstream file_obj;

	// Opening file in append mode
	file_obj.open("Input.txt", ios::app);

	// Object of class contestant to input data in file
	Contestant obj;

	// Feeding appropriate data in variables
	string str = "Michael";
	int age = 18, ratings = 2500;

	// Assigning data into object
	obj.Name = str;
	obj.Age = age;
	obj.Ratings = ratings;

	// Writing the object's data in file
	file_obj.write((char*)&obj, sizeof(obj));

	// Feeding appropriate data in variables
	str = "Terry";
	age = 21;
	ratings = 3200;

	// Assigning data into object
	obj.Name = str;
	obj.Age = age;
	obj.Ratings = ratings;

	// Writing the object's data in file
	file_obj.write((char*)&obj, sizeof(obj));
	
	//close the file
	//It's always a good practice to close the file after opening them
	file_obj.close();

	return 0;
}

// Function definition of output_highest_rated() to
// extract info from file Data Base
int Contestant::output_highest_rated()
{
	// Object to read from file
	ifstream file_obj;

	// Opening file in input mode
	file_obj.open("Input.txt", ios::in);

	// Object of class contestant to input data in file
	Contestant obj;

	// Reading from file into object "obj"
	file_obj.read((char*)&obj, sizeof(obj));

	// max to store maximum ratings
	int max = 0;

	// Highest_rated stores the name of highest rated contestant
	string Highest_rated;

	// Checking till we have the feed
	while (!file_obj.eof()) {
		// Assigning max ratings
		if (obj.Ratings > max) {
			max = obj.Ratings;
			Highest_rated = obj.Name;
		}

		// Checking further
		file_obj.read((char*)&obj, sizeof(obj));
	}
	
	// close the file.
	//It's always a good practice to close the file after opening them
	file_obj.close();

	// Output is the highest rated contestant
	cout << Highest_rated;
	return 0;
}

// Driver code
int main()
{
	// Creating object of the class
	Contestant object;

	// Inputting the data
	object.input();

	// Extracting the max rated contestant
	object.output_highest_rated();

	return 0;
}
