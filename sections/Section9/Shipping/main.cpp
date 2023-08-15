// Section 9
// Shipping

/* 
    Shipping cost calculator
    
    Ask the user for package dimension in inches
    length, width, height - these should be integers
    
    All dimension must be 10 inches or less or we cannot ship it
    
    Base cost $2.50
    If package volume is greater than 100 cubic inches there is a 10% surcharge
    If package volume is greater than 500 cubic inches there is a 25% surcharge

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int length{}, width{}, height{}; //introduced length, width and height and initialised them all to 0
    double base_cost{2.50};
    
    const int tier1_threshold {100};    // volume
    const int tier2_threshold{500};    // volume
    
    int max_dimension_length  {10};  // inches
    
    double tier1_surcharge {0.10};  // 10% extra
    double tier2_surcharge {0.25};  // 25% extra
    
    // All dimension must be 10 inches or less
    
    int package_volume{};
    
    cout << "Welcome to the package cost calculator" << endl;
    cout << "Enter length, width, and height of the package separated by spaces : ";
    cin >> length >> width >> height;
    // if statement that uses an or to check if the package fits the required dimensions 
    if (length > max_dimension_length || width > max_dimension_length || height > max_dimension_length) {
        cout << "Sorry, package rejected - dimension exceeded" << endl;
    } 
    else {
        double package_cost {}; // an introduced variable 
        package_volume= length * width * height;
        package_cost = base_cost;  // assigned to be equal to the base_cost
        
        if (package_volume > tier2_threshold) {
            package_cost += package_cost * tier2_surcharge; // note by the lhs += lhs* value = lhs = lhs + (lhs*value)
            // we check for the tier_2 first because it may be both greater than tier_1 and tier_2 at the same time so if wrongly evaluated the person may 
            // end up paying more surcharge than should 
            cout << " adding tier 2 surcharge" << endl;
            // package will only be greater than tier_1 if deemed less than tier_2 which has a higher value 
            // therefore this will only evaluate to the else if the if initially was not true
            //note by all this are in the else block of the initial if
        }
        else if ( package_volume > tier1_threshold) {
            package_cost += package_cost * tier1_surcharge;
            cout << " adding tier 1surcharge" << endl;
        }
        
        cout << fixed << setprecision(2); // prints dollars nicely. sets to precision of two decimal places 
        cout << "The volume of your package is: " << package_volume << endl;
        cout << "Your package will cost $" << package_cost << " to ship " << endl;
        
    }
    cout << endl;
    return 0;
}

