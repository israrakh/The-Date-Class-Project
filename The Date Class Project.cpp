// The Date Class Project.cpp

#include "Date.h"
#include <iostream>

using namespace std;


int main() {
    try {
        // Test 1: Default constructor
        Date date1;
        cout << "Test 1 - Default constructor (numeric format): ";
        date1.printNumeric();  // Expected output: 1/1/1930

        // Test 2: Parameterized constructor
        Date date2(12, 25, 2021);
        cout << "Test 2 - Parameterized constructor (long format): ";
        date2.printLong();  // Expected output: December 25, 2021

        // Test 3: setDate() function and print in European format
        date2.setDate(1, 31, 2020);
        cout << "Test 3 - setDate and print in European format: ";
        date2.printEuropean();  // Expected output: 31 January 2020

        // Test 4: Invalid date (13/45/2018)
        try {
            date2.setDate(13, 45, 2018);
        }
        catch (invalid_argument& e) {
            cout << "Test 4 - " << e.what() << endl;  // Expected output: Invalid date!
        }

        // Test 5: Invalid date (4/31/2000)
        try {
            date2.setDate(4, 31, 2000);
        }
        catch (invalid_argument& e) {
            cout << "Test 5 - " << e.what() << endl;  // Expected output: Invalid date!
        }

        // Test 6: Invalid date (2/29/2009)
        try {
            date2.setDate(2, 29, 2009);
        }
        catch (invalid_argument& e) {
            cout << "Test 6 - " << e.what() << endl;  // Expected output: Invalid date!
        }

        // Test 7: Date subtraction
        Date date3(4, 10, 2014);
        Date date4(4, 18, 2014);
        cout << "Test 7 - Difference between " << date4 << " and " << date3 << " is " << (date4 - date3) << " days." << endl;  // Expected output: 8 days

        // Test 8: Date subtraction
        Date date5(2, 2, 2006);
        Date date6(11, 10, 2003);
        cout << "Test 8 - Difference between " << date6 << " and " << date5 << " is " << (date5 - date6) << " days." << endl;  // Expected output: 815 days

        // Test 9: Pre-decrement
        Date date7(2, 29, 2008);
        --date7;
        cout << "Test 9 - Pre-decrement: ";
        date7.printNumeric();  // Expected output: 1/31/2008

        // Test 10: Pre-increment
        ++date7;
        cout << "Test 10 - Pre-increment: ";
        date7.printNumeric();  // Expected output: 2/29/2008

        // Test 11: Post-decrement and post-increment
        date7--;
        cout << "Test 11 - Post-decrement: ";
        date7.printNumeric();  // Expected output: 1/31/2008

        date7++;
        cout << "Test 12 - Post-increment: ";
        date7.printNumeric();  // Expected output: 2/29/2008

        // Test 12: Post-increment from 12/31/2024
        date7.setDate(12, 31, 2024);
        date7++;
        cout << "Test 13 - Post-increment: ";
        date7.printNumeric();  // Expected output: 1/1/2025

        // Test 13: Post-decrement from 1/1/2025
        date7--;
        cout << "Test 14 - Post-decrement: ";
        date7.printNumeric();  // Expected output: 12/31/2024

        // Test 14: Pre-increment and pre-decrement
        ++date7;
        cout << "Test 15 - Pre-increment: ";
        date7.printNumeric();  // Expected output: 1/1/2025

        --date7;
        cout << "Test 16 - Pre-decrement: ";
        date7.printNumeric();  // Expected output: 12/31/2024

        // Test 15: Read date
        Date date8;
        cout << "Test 17 - Enter a date (MM/DD/YYYY): ";
        cin >> date8;
        cout << "The date you entered is: " << date8 << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}