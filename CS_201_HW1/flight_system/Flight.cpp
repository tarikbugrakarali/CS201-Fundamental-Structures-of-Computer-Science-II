#include "Flight.h"
#include <iostream>

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

using namespace std;

Flight::Flight(int flightNumber, int rowNumber, int colNumber)
{
    flightNo = flightNumber;
    rowNo = rowNumber;
    colNo = colNumber;
    reservedSeat = 0;

}

Flight::Flight()
{
    flightNo = 0;
    rowNo = 0;
    colNo = 0;
    reservedSeat = 0;
}

int Flight::totalSeats()
{
    return rowNo * colNo;
}

int Flight::emptySeats()
{
    return ((rowNo * colNo) - reservedSeat);
}

void Flight :: info()
{
     cout << "Flight " << getFlightNo() << " ( " <<  totalSeats() - getReservedSeat() << " available seats.)" << endl;
}

void Flight:: setFlight(const int flightNo, const int rowNo, const int seatNo)
{
    setFlightNo(flightNo);
    setRowNo(rowNo);
    setColNo(seatNo);
}

void Flight :: displaySeat(bool seatCond)
{
    if(seatCond)
        cout <<" x";
    else
        cout <<" o";
}

void Flight::setFlightNo(int update)
{
    flightNo = update;
}

void Flight::setRowNo(int update)
{
    rowNo = update;
}

void Flight::setColNo(int update)
{
    colNo = update;
}

int Flight::getFlightNo()
{
    return flightNo;
}

int Flight::getRowNo()
{
    return this->rowNo;
}

int Flight::getColNo()
{
    return this->colNo;
}

int Flight::getReservedSeat()
{
    return reservedSeat;
}

void Flight :: setReservedSeat(int k)
{
    reservedSeat = k;
}

