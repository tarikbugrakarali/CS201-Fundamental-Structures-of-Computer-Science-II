#include "ReservationSystem.h"
#include "Flight.h"
#include "Reservation.h"
#include <iostream>
#include <string>

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/
using namespace std;

ReservationSystem::ReservationSystem()
{
    reservedFlightsNumbers = NULL;
    reservedFlights = 0;
    totalReservs = 0;
}

void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo)
{
    if(reservedFlightsNumbers == NULL)
    {
        reservedFlightsNumbers = new Flight[1];
        reservedFlightsNumbers[reservedFlights].setFlightNo(flightNo);
        reservedFlightsNumbers[reservedFlights].setRowNo(rowNo);
        reservedFlightsNumbers[reservedFlights].setColNo(seatNo);

          cout << "Flight " << flightNo << " has been added" << endl;

          reservedFlights++;
    }

    else
    {
        int counter = 0;

        for(int i = 0 ; i < reservedFlights ; i++)
        {
            if(reservedFlightsNumbers[i].getFlightNo() == flightNo)
            {
                counter++;
            }
        }

        if(counter == 0)
        {
            Flight* newFlights = reservedFlightsNumbers;
            reservedFlightsNumbers = new Flight[reservedFlights + 1];

            for(int i = 0 ; i < reservedFlights ; i++)
            {
                reservedFlightsNumbers[i] = newFlights[i];
            }
           reservedFlightsNumbers[reservedFlights].setFlightNo(flightNo);
           reservedFlightsNumbers[reservedFlights].setRowNo(rowNo);
           reservedFlightsNumbers[reservedFlights].setColNo(seatNo);

            cout << "Flight " << flightNo << " has been added" << endl;

            reservedFlights++;

            delete[] newFlights;
        }

        else
        {
            cout << "Flight " << flightNo << " already exists" << endl;
        }
    }
}

void ReservationSystem::cancelFlight( const int flightNo)
{
    int cond = 0;

    for(int i = 0 ; i < reservedFlights ; i++)
    {
        if(reservedFlightsNumbers[i].getFlightNo() == flightNo)
        {
            Flight* newFlights = reservedFlightsNumbers;
            reservedFlightsNumbers = new Flight[reservedFlights - 1];

            for(int j = 0 ; j < i ; j++)
            {
                reservedFlightsNumbers[j] = newFlights[j];
            }

            for(int j = i + 1 ; j < reservedFlights ; j++)
            {
                reservedFlightsNumbers[(j - 1)] = newFlights[j];
            }

            R.deleteAllReservations(flightNo);
            cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;

            cond ++;
            delete[] newFlights;
            reservedFlights--;
            break;
        }
    }

    if(cond == 0)
    {
         cout << "Flight " << flightNo << " does not exist." << endl;
    }
}
void ReservationSystem :: updateEmptySeat(Flight x)
{

}

void ReservationSystem::showAllFlights()
{
    if(reservedFlights  == 0)
    {
            cout << "No flights exist." << endl;
    }
    else
    {
        cout <<  "Flights currently operated: " << endl;

        for(int i = 0 ; i < reservedFlights ; i++)
        {
                updateEmptySeat(reservedFlightsNumbers[i]);
                reservedFlightsNumbers[i].info();
        }
    }
}


void ReservationSystem::cancelReservation(int resCode)
{
    R.deleteReservDisplay(resCode);
}


void ReservationSystem::showFlight( const int flightNo)
{
        int counter = 0;

        for(int i = 0 ; i < reservedFlights ; i++)
        {
            if(reservedFlightsNumbers[i].getFlightNo() == flightNo)
            {
                reservedFlightsNumbers[i].info();
                showDetailedInformation(flightNo);
                counter++;
                break;
            }
        }

        if(counter == 0)
        {
            cout << "Flight " << flightNo << " does not exist." << endl;
        }
}


void ReservationSystem::showDetailedInformation(int flightNo)
{
    if(reservedFlights != 0)
    {
        for(int i = 0 ; i < reservedFlights ; i++)
        {
            if( reservedFlightsNumbers[i].getFlightNo() == flightNo )
            {
                for(int j = 0 ; j < reservedFlightsNumbers[i].getColNo() + 1 ; j++)
                {
                    if( j == 0 )
                    {
                            cout << "   ";
                    }
                    else
                    {
                        cout << intToLetter(j) << "  " ;
                    }
                }
                cout << endl;

                for(int k = 0 ; k < reservedFlightsNumbers[i].getRowNo() ; k++)
                {
                   cout <<  k + 1 << "  " ;


                        for(int z = 0 ; z < reservedFlightsNumbers[i].getColNo() ; z++)
                        {

                            reservedFlightsNumbers[i].displaySeat(R.hasReserved(flightNo, k + 1, z + 1));
                        }
                        cout << endl;
                }
            }
        }
    }
}

char ReservationSystem::intToLetter( int n )
{
    if (n > 0 && n < 27 )
   {
           return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
   }
    return '-';
}


int ReservationSystem::makeReservation (const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol)
{
    return R.reserv(flightNo, numPassengers, seatRow, seatCol);
}

void ReservationSystem::showReservation(const int resCode)
{
    R.showReserv(resCode);
}


