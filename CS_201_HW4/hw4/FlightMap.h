#ifndef  FLIGHTMAP_H
#define  FLIGHTMAP_H
#include <string>
#include "City.h"

using namespace std;

class FlightMap
{
    public:
          FlightMap( const string cityFile , const string flightFile);
          ~FlightMap();
          void displayAllCities() const;
          void displayAdjacentCities( const string cityName) const;
          void displayFlightMap();
          int number(const char* name);
          void readCity(const char* name);
          void  readLine(const char* name);
          void addConnected(string s, int index);
          void findFlights( const string deptCity, const string destCity ) const;
          void findLeastCostFlight( const string deptCity, const string destCity )const;
          void runFlightRequests( const string requestFile ) const;


    private:
           City* cities;
           int numberOfCity;
           string* lines;
           string* first;
           string* second;
           string* price;
           string* id;

};
#endif // BOOKLIST_H
