#include "Rental.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor for array initialization
Rental::Rental() {
    rental_id = 0;
    category = cat::misc;
    description = "";
    maxPeople = 0;
    price_per_day = 0.0;
    num_reservations = 0;
}

// Parameterized constructor
Rental::Rental(int id, cat::Category cat, string desc, int maxP, double price)
    : rental_id(id), category(cat), description(desc), maxPeople(maxP), price_per_day(price), num_reservations(0) {}

int Rental::getId() { 
    return rental_id; 
}

cat::Category Rental::getCategory() { 
    return category; 
}

bool Rental::addReservation(string name, int num, Date& in, Date& out) {
    // 1. Capacity and Occupancy Check
    if (num_reservations >= MAX_ARRAY || num > maxPeople) return false;
    
    // 2. Date Validity Check: out must be after in
    if (out.lessThan(in) || out.equals(in)) return false; 

    // 3. Find chronological insertion index
    int index = 0;
    while (index < num_reservations) {
        if (in.lessThan(reservations[index].getCheckIn())) {
            break; 
        }
        index++;
    }

    // 4. Strict Overlap check
    // Check previous reservation's end date
    if (index > 0 && in.lessThan(reservations[index-1].getCheckOut())) return false;
    // Check next reservation's start date
    if (index < num_reservations && reservations[index].getCheckIn().lessThan(out)) return false;

    // 5. Shift elements to the right to maintain order
    for (int i = num_reservations; i > index; --i) {
        reservations[i] = reservations[i-1];
    }

    // 6. Insert new reservation and update counter
    reservations[index] = Reservation(name, num, in, out);
    num_reservations++;
    return true;
}

void Rental::removeReservation(string name, Date& checkin) {
    for (int i = 0; i < num_reservations; ++i) {
        // Find matching reservation
        if (reservations[i].getName() == name && reservations[i].getCheckIn().equals(checkin)) {
            // Shift remaining reservations left to close the gap
            for (int j = i; j < num_reservations - 1; ++j) {
                reservations[j] = reservations[j+1];
            }
            num_reservations--;
            return;
        }
    }
}

void Rental::print() {
    // Matches the required output format for the Tester
    cout << "Rental ID:    " << rental_id << endl;
    cout << "Category:     " << cat::categoryToString(category) << endl; 
    cout << "Description:  " << description << endl;
    cout << "Max People:   " << maxPeople << endl;
    // Strict price formatting
    cout << "Price per Day: $" << fixed << setprecision(2) << price_per_day << endl;
}

void Rental::printReservations() {
    for (int i = 0; i < num_reservations; ++i) {
        reservations[i].print();
    }
}

void Rental::printReservation(Date& date) {
    for (int i = 0; i < num_reservations; ++i) {
        // Stay covers date if check_in <= date AND date < check_out
        if ((reservations[i].getCheckIn().lessThan(date) || reservations[i].getCheckIn().equals(date)) && 
             date.lessThan(reservations[i].getCheckOut())) {
            reservations[i].print();
        }
    }
}