#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Date.h"

class Reservation {
    private:
        std::string name;
        int num_people;
        Date check_in;
        Date check_out;

    public:
        Reservation(std::string name, int num, Date& in, Date& out);
        Reservation();
        void print();
        
        // Prototypes only - bodies moved to Reservation.cc
        std::string getName();
        Date& getCheckIn();
        Date& getCheckOut();
};
#endif