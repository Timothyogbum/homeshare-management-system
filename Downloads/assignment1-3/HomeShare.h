#ifndef HOMESHARE_H
#define HOMESHARE_H

#include <string>
#include "Rental.h"
#include "defs.h"

class HomeShare {
    private:
        // The Collection of all properties [cite: 212]
        Rental rentals[MAX_ARRAY]; 
        int num_rentals; // Tracks how many rentals are in the array [cite: 213]

    public:
        HomeShare(); // Default constructor [cite: 214]

        // Management functions [cite: 218-228]
        void addRental(int id, cat::Category cat, std::string desc, int maxP, double price);
        void removeRental(int rental_id);
        void addReservation(int rentalId, std::string name, int num, Date& in, Date& out);
        void removeReservation(int rentalId, std::string name, Date& checkin);

        // Specialized reporting [cite: 230-234]
        void printRentals();
        void printReservations(int rentalId);
        void printReservations(Date& date);
        void printRentalsByCategory(cat::Category category);
};

#endif