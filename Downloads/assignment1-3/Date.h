#ifndef Date_H
#define Date_H

class Date{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int d = 1, int m = 1, int y = 2026);
        bool equals(Date& d);
        bool lessThan(Date& d);
        void print();
};
#endif