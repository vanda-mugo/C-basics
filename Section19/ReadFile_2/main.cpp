// Section 19
// Read File 2
// Continuous read of 3 data items in a loop
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    
    in_file.open("../test2.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    // this while loop allows the reading of line 
    
    while(!in_file.eof())  // while not end of file. eof() will be true when the end of file is reached // 
    {
        in_file>>line;//num>>total;
        std::cout<<std::setw(10)<<std::left<<line ; // remember that this actually has effect only on line, the manip operators only have effect on line 
//                    <<std::setw(10)<<num
//                    <<std::setw(10)<<total
//                    <<std::endl;
    }
    std::cout<<"\n";
    in_file.close();
    
    
    
    in_file.open("../test.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    while (in_file >> line >> num >> total) {// if anything fails it wont run, whenever you are able to read the unformatted lines in the file 
        
        std::cout << std::setw(10) << std::left << line 
                       << std::setw(10) << num 
                       << std::setw(10)  << total
                       << std::endl;
    }
    // either of the two while loops is correct
    in_file.close();
    return 0;
}

