finalProgram : Flight.o Reservation.o ReservationSystem.o main.o
        g++ Flight.o Reservation.o ReservationSystem.o main.o -o finalProgram

Flight.o : Flight.cpp
        g++ -c -std=gnu++11 Flight.cpp

Reservation.o : Reservation.cpp
        g++ -c Reservation.cpp

ReservationSystem.o : ReservationSystem.cpp
        g++ -c -std=gnu++11 ReservationSystem.cpp

main.o : main.cpp
        g++ -c main.cpp