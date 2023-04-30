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

Reservation::Reservation()
{
    numberOfReservs = 0;
    flights = NULL;
    rowNoArr = NULL;
    colNoArr = NULL;
    passangers = NULL;
}

void Reservation::deleteAllReservations(const int flightNo)
{
    if(numberOfReservs > 0)
    {
        for (int i  = 0 ; i < numberOfReservs ; i++)
        {
            if(flights[i] == flightNo)
            {
                deleteReservation(i  + 1);
            }
        }
    }

    else
    {
        cout << "There is no Flight" << endl;
    }
}

void Reservation::deleteReservation(int resCode)
{
    if(resCode > 0 && resCode < numberOfReservs + 1)
    {
        flights[resCode - 1] = 0;
        passangers[resCode - 1] = 0;

        if(rowNoArr[resCode - 1] != NULL )
        {
            delete[] rowNoArr[resCode - 1];
            rowNoArr[resCode - 1] = NULL;
        }

        if(colNoArr[resCode - 1] != NULL)
        {
            delete[] colNoArr[resCode - 1];
            colNoArr[resCode - 1]  = NULL;
        }
    }
}

void Reservation::deleteReservDisplay(int resCode)
{
    resCode = resCode - 1;

    if(resCode > -1 && resCode < numberOfReservs + 1)
    {
        cout << "Reservation for the seats ";

        for(int i = 0 ; i < passangers[resCode] ; i++)
        {
            cout  << rowNoArr[resCode][i] << intToLetter(colNoArr[resCode][i]) << " ";
        }

        cout << "is canceled in flight " << flights[resCode] << endl;

        flights[resCode] = 0;
        passangers[resCode] = 0;

        if(rowNoArr[resCode] != NULL )
        {
            delete[] rowNoArr[resCode];
        }

        if(colNoArr[resCode] != NULL)
        {
            delete[] colNoArr[resCode];
        }
            rowNoArr[resCode] = NULL;
            colNoArr[resCode]  = NULL;
    }

    else
    {
        cout << "Invalid reservation code: Reservation Code " << resCode + 1 << endl;
    }
}


void Reservation::showReserv(const int resCode)
{
    if( passangers[resCode - 1] != 0)
    {
        if(resCode -  1 <= numberOfReservs )
        {
            cout << "Reservations under Code " <<  resCode << " in Flight " << flights[resCode - 1] << ": ";

            for(int i = 0 ; i < passangers[resCode - 1] ; i++)
            {
                cout << rowNoArr[resCode - 1][i] << intToLetter(colNoArr[resCode - 1][i]) ;

                if(i != passangers[resCode - 1] - 1)
                {
                    cout << "/";
                }
            }
            cout << endl;
        }

        else
        {
            cout << "No reservation under code " << resCode << endl;
        }
    }

    else
    {
         cout << "No reservation under code " << resCode << endl;
    }
}

int Reservation::reserv(const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol)
{
    if(numberOfReservs == 0)
    {
       flights = new int[1];
       rowNoArr = new int*[1];
       colNoArr = new int*[1];
       passangers = new int[1];

        flights[numberOfReservs] = flightNo;
        rowNoArr[numberOfReservs] = new int[numPassengers];
        colNoArr[numberOfReservs] = new int[numPassengers];
        passangers[numberOfReservs] = numPassengers;

        for(int i = 0 ; i < numPassengers ; i++)
        {
            rowNoArr[numberOfReservs][i] = seatRow[i];
            colNoArr[numberOfReservs][i] = letterToInt(seatCol[i]);
        }

        numberOfReservs = numberOfReservs + 1;
        return numberOfReservs;
    }

    else
    {
        int counter = 0;

        for(int i = 0 ; i < numPassengers ; i++)
        {
            if(hasReserved(flightNo,seatRow[i] , letterToInt(seatCol[i])))
            {
                counter++;
                cout << seatRow[i] << (seatCol[i]) << " " ;
            }
        }

        if( counter == 0)
        {
            int* tmpFlights = flights;
            int** newrowNoArr = rowNoArr;
            int** newcolNoArr = colNoArr;
            int* tmpPassangerArr = passangers;

            flights = new int[numberOfReservs + 1];
            rowNoArr = new int*[numberOfReservs + 1];
            colNoArr = new int*[numberOfReservs + 1];
            passangers = new int[numberOfReservs + 1];

            for(int i = 0 ; i < numberOfReservs ; i++)
            {
                flights[i] = tmpFlights[i];
                rowNoArr[i] = new int[passangers[i]];
                colNoArr[i] = new int[passangers[i]];
                passangers[i] = tmpPassangerArr[i];

                for(int j = 0 ; j < passangers[i] ; j++)
                {
                    rowNoArr[i][j] = newrowNoArr[i][j];
                    colNoArr[i][j]  = newcolNoArr[i][j];
                }
            }

            flights[numberOfReservs] = flightNo;
            rowNoArr[numberOfReservs] = new int[numPassengers];
            colNoArr[numberOfReservs] = new int[numPassengers];
            passangers[numberOfReservs] = numPassengers;

            for(int i = 0 ; i < numPassengers ; i++)
            {
                rowNoArr[numberOfReservs][i] = seatRow[i];
                colNoArr[numberOfReservs][i] = letterToInt(seatCol[i]);
            }

            delete[] tmpPassangerArr;
            delete[] tmpFlights;

            for (int i = 0 ; i < numberOfReservs ; i++)
            {
                delete[] newrowNoArr[i];
                delete[] newcolNoArr[i];
            }

            delete[] newrowNoArr;
            delete[] newcolNoArr;

            numberOfReservs = numberOfReservs + 1;

            return numberOfReservs;
        }

        else if(counter == 1)
            {
                cout << "is not available." << endl;
                return -1;
            }

        else
            {
                cout << "are not available." << endl;
                return -1;
            }
    }
}

int Reservation::letterToInt(const char x)
{
    return (x - 'A') + 1;
}

bool Reservation::hasReserved(const int flightNo, const int rowInput, const int colInput)
{
    if(numberOfReservs == 0)
    {
        return false;
    }

    else
    {
        for(int i = 0 ; i < numberOfReservs ; i++)
        {
            if(flights[i] == flightNo)
            {
                for(int j = 0 ; j < passangers[i] ; j++)
                {
                    if(getRowArr(i,j) == rowInput && getColArr(i,j) == colInput)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

char Reservation::intToLetter(const int x)
{
    if (x > 0 && x < 27 )
   {
           return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[x - 1];
   }
    return '-';
}

int Reservation::getRowArr(int i,int j)
{
    return rowNoArr[i][j];
}

int Reservation :: getColArr(int i, int j)
{
    return colNoArr[i][j];
}

