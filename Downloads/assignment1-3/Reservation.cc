#include "Reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation(string n, int num, Date& in, Date& out) {
    name = n; 
    num_people = (num < 1) ? 1 : num; 
    check_in = in; 
    check_out = out; 
}

Reservation::Reservation() : name("Guest"), num_people(1) {} 

string Reservation::getName() { 
    return name; 
}

Date& Reservation::getCheckIn() { 
    return check_in; 
}

Date& Reservation::getCheckOut() { 
    return check_out; 
}

void Reservation::print() {
    cout << "Reservation for: " << name << " (" << num_people << " people)" << endl; 
    cout << "Check-in: "; check_in.print(); 
    cout << " | Check-out: "; check_out.print(); cout << endl; 
}