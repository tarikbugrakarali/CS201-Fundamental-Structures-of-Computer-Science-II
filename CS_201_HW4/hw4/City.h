#ifndef  CITY_H
#define  CITY_H
#include <string>

using namespace std;

class City
{
    public:
          City();
          ~City();
          string getName();
          void setName(string cityName);
          void addCon(string conCity);
          void addPrice(int cost);
          void addId(int Id);
          void displayConnected();

    private:

           string name;
           int counter;
           string* connected;
           int * price;
           int * id;
};
#endif
