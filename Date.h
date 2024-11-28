#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

class Date {
private:
	int day, month, year;
	bool isLeapYear(int y) const;
	int daysInMonth(int m, int y) const;

public:
	// Setters and Getters
	/**
	 * Sets the date.
	 * Precondition: m, d, y must form a valid date.
	 * Postcondition: Updates the date to the specified values if valid; throws an exception otherwise.
	 */
	void setDate(int m, int d, int y);
	/**
	* Gets the day of the date.
	* Precondition: None.
	* Postcondition: Returns the day component of the date.
	*/
	int getDay() const {
		return day;
	}
	/**
	 * Gets the month of the date.
	 * Precondition: None.
	 * Postcondition: Returns the month component of the date.
	 */
	int getMonth() const {
		return month;
	}
	/**
	 * Gets the year of the date.
	 * Precondition: None.
	 * Postcondition: Returns the year component of the date.
	 */
	int getYear() const {
		return year;
	}

	// Outpur functions

	/**
	 * Prints the date in numeric format (MM/DD/YYYY).
	 * Precondition: None.
	 * Postcondition: Outputs the date in numeric format to standard output.
	 */
	void printNumeric() const;
	/**
	 * Prints the date in long format (Month DD, YYYY).
	 * Precondition: None.
	 * Postcondition: Outputs the date in long format to standard output.
	 */
	void printLong() const;
	/**
	 * Prints the date in European format (DD Month YYYY).
	 * Precondition: None.
	 * Postcondition: Outputs the date in European format to standard output.
	 */
	void printEuropean() const;

	// Operators overloaded

	/**
	 * Pre-increment operator.
	 * Precondition: None.
	 * Postcondition: Advances the date by one day, adjusting month and year as needed.
	 */
	Date& operator++(); // Pre-increment
	/**
	 * Post-increment operator.
	 * Precondition: None.
	 * Postcondition: Advances the date by one day, adjusting month and year as needed. 
	 * Returns the original value before increment.
	 */
	Date operator++(int); // Post-increment
	/**
	 * Pre-decrement operator.
	 * Precondition: None.
	 * Postcondition: Moves the date back by one day, adjusting month and year as needed.
	 */
	Date& operator--(); // Pre-decrement
	/**
	 * Post-decrement operator.
	 * Precondition: None.
	 * Postcondition: Moves the date back by one day, adjusting month and year as needed. 
	 * Returns the original value before decrement.
	 */
	Date operator--(int); // Post-decrement
	/**
	 * Subtraction operator.
	 * Precondition: Both dates must be valid.
	 * Postcondition: Returns the number of days between the two dates. 
	 * The result is positive if the first date is after the second date, and negative otherwise.
	 */
	int operator-(const Date& other) const;

	/**
	 * Stream insertion operator.
	 * Precondition: None.
	 * Postcondition: Outputs the date in long format (Month DD, YYYY) to the specified stream.
	 */
	friend ostream& operator << (ostream& ostrm, const Date& date);
	/**
	 * Stream extraction operator.
	 * Precondition: Input format must be MM/DD/YYYY.
	 * Postcondition: Updates the date object with the input values if valid; 
	 * sets the failbit on the stream and throws an exception otherwise.
	 */
	friend istream& operator >> (istream& istrm, Date& date);

	// Default and Parameterized constructors
	/**
	* Default Constructor
	* Precondition: None.
	* Postcondition: Initializes the date to 1/1/1930.
	*/
	Date();
	/**
	* Parameterized Constructor
	* Precondition: m, d, y must form a valid date.
	* Postcondition: Initializes the date to the provided values if valid; throws an exception otherwise.
	*/
	Date(int m, int d, int y);

};

#endif // !DATE_H

