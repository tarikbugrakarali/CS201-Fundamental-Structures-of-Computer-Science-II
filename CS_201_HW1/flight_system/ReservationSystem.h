#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
#include <iostream>

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

using namespace std;

class ReservationSystem
{
    public:

        ReservationSystem();
        void addFlight( const int flightNo, const int rowNo, const int seatNo );
        void cancelFlight( const int flightNo );
        void showAllFlights();
        void showFlight( const int flightNo );
        void cancelReservation( const int resCode );
        void showReservation( const int resCode );
        void updateEmptySeat(Flight x);
        int makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol );
        void showDetailedInformation(int flightNo);
        char intToLetter(int n);




    private:
        int reservedFlights;
        int totalReservs;
        Flight* reservedFlightsNumbers;
        Reservation R;


};
#endif

