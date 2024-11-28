#include "Date.h"

using namespace std;

// Helper functions
bool Date::isLeapYear(int y) const {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
	static const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m == 2 && isLeapYear(y))
		return 29;
	return daysPerMonth[m - 1];
}

// Constructors
Date::Date() : day(1), month(1), year(1930) {}

Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

// Setter 
void Date::setDate(int m, int d, int y) {
	if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) {
		throw invalid_argument("Invalid date!");
	}
	month = m;
	day = d;
	year = y;
}

// Output functions
void Date::printNumeric() const {
	cout << month << "/" << day << "/" << year << endl;
}
void Date::printLong() const {
	static const string months[] = { "", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };

	cout << months[month] << " " << day << ", " << year << endl;
}
void Date::printEuropean() const {
	static const string months[] = { "", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };

	cout << day << " " << months[month] << " " << year << endl;
}

// Operator Overloads
Date& Date::operator++() {
	if (day < daysInMonth(month, year)) {
		day++;  // Increment the day if it's not the last day of the month
	}
	else {
		day = 1;
		if (month < 12) {
			month++;  // Move to the next month
		}
		else {
			month = 1;
			year++;  // Move to the next year
		}
	}
	return *this;  // Return the modified object by reference
}

Date Date::operator++(int) {
	Date temp = *this;  // Make a copy of the current date
	++(*this);  // Call the pre-increment to modify the current object
	return temp;  // Return the copy, which is the original state of the object
}

Date& Date::operator--() {
	if (day > 1) {
		day--;  // Decrement the day if it's not the first day of the month
	}
	else {
		if (month > 1) {
			month--;  // Move to the previous month
			day = daysInMonth(month, year);  // Set the day to the last day of the previous month
		}
		else {
			month = 12;
			year--;  // Move to the previous year
			day = 31;  // December has 31 days
		}
	}
	return *this;  // Return the modified object by reference
}

Date Date::operator--(int) {
	Date temp = *this;  // Make a copy of the current date
	--(*this);  // Call the pre-decrement to modify the current object
	return temp;  // Return the copy, which is the original state of the object
}

int Date::operator-(const Date& other) const {
	int days = 0;
	Date temp = *this;

	while (temp.year > other.year || (temp.year == other.year && (temp.month > other.month || (temp.month == other.month && temp.day > other.day)))) {
		--temp;
		days++;
	}

	while (temp.year < other.year || (temp.year == other.year && (temp.month < other.month || (temp.month == other.month && temp.day < other.day)))) {
		++temp;
		days--;
	}

	return days;
}

ostream& operator<<(ostream& ostrm, const Date& date) {
	static const string months[] = { "" ,"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
	ostrm << months[date.month] << " " << date.day << ", " << date.year;
	return ostrm;
}

istream& operator>>(istream& istrm, Date& date) {
	int m, d, y;
	char sep1, sep2;
	istrm >> m >> sep1 >> d >> sep2 >> y;

	if (sep1 != '/' || sep2 != '/' || m < 1 || m > 12 || d < 1 || d > date.daysInMonth(m, y)) {
		istrm.setstate(ios::failbit);
		throw invalid_argument("Invalid date format");
	}

	date.setDate(m, d, y);
	return istrm;
}
