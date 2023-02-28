#include <fstream>
#include <iostream>
using namespace std;

int main() {

    fstream strm;
    strm.open("C:\\Users\\25479\\Documents\\doc1.txt", ios_base::out);
    if (!strm.is_open()) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    char str[] = "A: This is the first line.\n"
                 "B: This is the second line.\n"
                 "C: This is the third line.\n";

    strm << str;// the name of the content to be input is identified by the str in this line . at the end of the program a string content would be inserted
    // into the stream 
    
    strm.close();
    if (strm.is_open()){
        cout << "Stream could not close!" << endl;
        return 1;
    }
    cout << "Success, check file" << endl;
    return 0;
}

/*
 * Instead of sending text to the file with the insertion operator, the write() member function can be used. The following code illustrates this:
 * 
 * basic_ostream<charT, traits>& write(const char_type* s, streamsize n)
 * 
 * The first argument of the write() function is the identifier of the character array. The second argument is the number of characters (without \0) in the array.
 * */

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main() {

    fstream strm;
    strm.open("doc2.txt", ios_base::out);
    if (!strm.is_open()) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    char str[] = "A: This is the first line.\n"
                 "B: This is the second line.\n"
                 "C: This is the third line.\n";

    strm.write(str, strlen(str));

    strm.close();
    if (strm.is_open()){
        cout << "Stream could not close!" << endl;
        return 1;
    }

    return 0;
}

/*
Appending Characters to a File

To append text to a file, use “ios_base::app” alone, instead of “ios_base::out” in the open() member function. Still, use the insertion operator, <<, as follows:
The output file should now have four lines.
*/

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main() {

    fstream strm;
    strm.open("doc2.txt", ios_base::app);
    if (!strm.is_open()) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    char str[] = "D: This is the fourth line.\n";

    strm << str;

    strm.close();
    if (strm.is_open()){
        cout << "Stream could not close!" << endl;
        return 1;
    }

    cout << "Success, check file" << endl;
    return 0;
}