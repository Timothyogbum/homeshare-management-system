#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include "Reservation.h"
#include "Category.h"
#include "defs.h"

class Rental {
    private:
        int rental_id;
        cat::Category category;
        std::string description;
        int maxPeople;
        double price_per_day;
        Reservation reservations[MAX_ARRAY];
        int num_reservations;

    public:
        Rental(); 
        Rental(int id, cat::Category cat, std::string desc, int maxP, double price);
        
        bool addReservation(std::string name, int num, Date& in, Date& out);
        void removeReservation(std::string name, Date& checkin);
        void print();
        void printReservations();
        void printReservation(Date& date);
        
        // Prototypes only - bodies moved to Rental.cc
        int getId();
        cat::Category getCategory();
};
#endif