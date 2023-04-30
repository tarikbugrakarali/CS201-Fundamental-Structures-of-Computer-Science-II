#ifndef FLIGHT_H
#define FLIGHT_H

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/


class Flight
{
    public:


        Flight(int flightNumber, int rowNumber, int colNumber);
        Flight();
        int emptySeats();
        int totalSeats();
        void displaySeat(bool seatCond);
        void info();
        void setFlight(const int flightNo, const int rowNo, const int seatNo);
        void setFlightNo(int update);
        void setRowNo(int update);
        void setColNo(int update);
        int getFlightNo();
        int getRowNo();
        int getColNo();
        int getReservedSeat();
        void setReservedSeat(int k);


    private:
        int flightNo;
        int rowNo;
        int colNo;
        int reservedSeat;
};

#endif
