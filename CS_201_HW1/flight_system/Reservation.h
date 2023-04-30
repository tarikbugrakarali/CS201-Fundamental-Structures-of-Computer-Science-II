#ifndef RESERVATION_H
#define RESERVATION_H
#include "Flight.h"

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

class Reservation
{
    public:

        Reservation();
        int reserv(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol);
        void deleteAllReservations(const int flightNo);
        void deleteReservation(int resCode);
        void deleteReservDisplay(int resCode);
        void showReserv(const int resCode);
        bool hasReserved(const int flightNo, const int rowInput, const int colInput);
        char intToLetter(const int x);
        int getRowArr(int i,int j);
        int getColArr(int i, int j);
        int letterToInt(const char x);


    private:

        int numberOfReservs;
        int* passangers;
        int* flights;
        int** rowNoArr;
        int** colNoArr;
};

#endif
