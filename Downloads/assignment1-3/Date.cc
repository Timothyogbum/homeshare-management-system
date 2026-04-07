#include "Date.h"
#include <iostream>

using namespace std;

// Added constructor to match your header
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::equals(Date& d){
    return(day == d.day && month == d.month && year == d.year);
}

bool Date::lessThan(Date& d){
    if (year < d.year) return true;
    if (year > d.year) return false;

    if (month < d.month) return true;
    if (month > d.month) return false;

    return (day < d.day);
}

void Date::print(){
    // Use the format required by the printReservation tests
    cout << day << "-" << month << "-" << year;
}