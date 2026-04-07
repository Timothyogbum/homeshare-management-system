#include "HomeShare.h"
#include <iostream>

using namespace std;

HomeShare::HomeShare() : num_rentals(0) {}

void HomeShare::addRental(int id, cat::Category cat, string desc, int maxP, double price) {
    // Ensure rental IDs are unique before adding
    for (int i = 0; i < num_rentals; ++i) {
        if (rentals[i].getId() == id) return; 
    }
    if (num_rentals < MAX_ARRAY) {
        rentals[num_rentals++] = Rental(id, cat, desc, maxP, price);
    }
}

void HomeShare::removeRental(int id) {
    for (int i = 0; i < num_rentals; ++i) {
        if (rentals[i].getId() == id) {
            // Shift remaining rentals forward to fill the gap
            for (int j = i; j < num_rentals - 1; ++j) rentals[j] = rentals[j+1];
            num_rentals--;
            return;
        }
    }
}

void HomeShare::addReservation(int rId, string n, int num, Date& in, Date& out) {
    for (int i = 0; i < num_rentals; ++i) {
        // Find the specific rental by ID and delegate
        if (rentals[i].getId() == rId) {
            rentals[i].addReservation(n, num, in, out);
            return;
        }
    }
}

void HomeShare::removeReservation(int rId, string n, Date& in) {
    for (int i = 0; i < num_rentals; ++i) {
        if (rentals[i].getId() == rId) {
            rentals[i].removeReservation(n, in);
            return;
        }
    }
}

void HomeShare::printRentals() {
    for (int i = 0; i < num_rentals; ++i) rentals[i].print();
}

void HomeShare::printReservations(int rId) {
    for (int i = 0; i < num_rentals; ++i) {
        if (rentals[i].getId() == rId) rentals[i].printReservations();
    }
}

void HomeShare::printReservations(Date& date) {
    // Print reservations from ALL rentals that cover this date
    for (int i = 0; i < num_rentals; ++i) rentals[i].printReservation(date);
}

void HomeShare::printRentalsByCategory(cat::Category cat) {
    for (int i = 0; i < num_rentals; ++i) {
        if (rentals[i].getCategory() == cat) rentals[i].print();
    }
}