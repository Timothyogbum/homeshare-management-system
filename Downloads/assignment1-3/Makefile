OBJ = main.o Date.o Reservation.o Rental.o HomeShare.o Category.o Tester.o

a1: $(OBJ)
	g++ -o a1 $(OBJ)

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h Date.h
	g++ -c Reservation.cc

Rental.o: Rental.cc Rental.h Reservation.h Category.h defs.h
	g++ -c Rental.cc

HomeShare.o: HomeShare.cc HomeShare.h Rental.h
	g++ -c HomeShare.cc

Category.o: Category.cc Category.h
	g++ -c Category.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

main.o: main.cc HomeShare.h Rental.h Date.h Tester.h
	g++ -c main.cc

clean:
	rm -f a1 *.o