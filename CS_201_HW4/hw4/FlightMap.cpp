#include "FlightMap.h"
#include "Stack.h"
#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
 FlightMap :: FlightMap( const string cityFile , const string flightFile)
 {
     const char* name = cityFile.c_str();
     numberOfCity = number(name);

     cities = new City[numberOfCity];
     readCity(name);

     const char* cf = flightFile.c_str();
     int lineNo = number(cf);
     lines = new string [lineNo];
     readLine(cf);

     first = new string [lineNo];
     second = new string [lineNo];
     price = new string [lineNo];
     id = new string [lineNo];

     for(int index = 0; index < lineNo; index ++)
     {
         addConnected(lines[index], index);
     }

     for(int j = 0; j < lineNo; j ++)
     {
         for(int i = 0; i < numberOfCity ; i ++)
         {
            if(cities[i].getName().compare(first[j]) == 0)
            {
                cities[i].addCon(second[j]);
                stringstream hold(price[j]);
                int x = 0;
                hold >> x;
                cities[i].addPrice(x);
                stringstream holder(id[j]);
                int y = 0;
                holder >> y;
                cities[i].addId(y);
            }
         }
     }

 }

FlightMap :: ~FlightMap()
{

}
int FlightMap :: number(const char* name)
{
    int cc=1;
    char ch;
    FILE *m;
    m=fopen(name,"r");
    while(!feof(m))
    {
        ch=getc(m);

        if(ch=='\n')
        {
           cc++;
        }
    }

    fclose(m);


return cc;
}

void FlightMap :: readCity(const char* name)
{
    ifstream input;
    string s;
    string b;
    string file = name;
    int counter = 0;
    input.open(file.c_str(),ios_base::in);
    while(input.eof() == false)

    {

       getline(input,s,'\n');
       cities[counter].setName(s);
       counter++;
    }

    input.close();
}

void FlightMap :: readLine(const char* name)
{
    ifstream input;
    string s;
    string b;
    string file = name;
    int counter = 0;
    input.open(file.c_str(),ios_base::in);
    while(input.eof() == false)

    {

       getline(input,s,'\n');
       lines[counter] = s;
       counter++;
    }

    input.close();
}

void FlightMap :: displayAllCities() const
{
    for(int i = 0; i < numberOfCity; i++)
    {
        cout<<cities[i].getName()<<endl;
    }
}

void FlightMap :: addConnected(string s, int index)
{
    int counter = 0;
    int place = 0;
    int size = s.length();
    string b ="";
    for(int i = 0; i < size; i++)
    {

        if(s[i] == ',')
        {
           cout << "b : "<< b <<endl;
           if(place == 0)
           {
              first[index] = b;
           }
           if(place == 1)
           {
              second[index] = b;
           }
           if(place == 2)
           {
              price[index] = b;
           }
           if(place == 3)
           {
              id[index] = b;
           }

           b = "";
           place ++;
        }

        else
            b = b + s[i];
    }
    cout << "b : "<< b <<endl;
    counter ++;
}

void FlightMap :: displayFlightMap()
{
  cout << "The whole flight map is shown below :" << endl;

  for(int i = 0; i < numberOfCity; i ++)
  {
      cities[i].displayConnected();
  }
}

void FlightMap :: displayAdjacentCities( const string cityName) const
{
    cout << "The cities adjacent to " << cityName << " are :" << endl;
    for(int i = 0; i < numberOfCity; i ++)
  {
      if(cities[i].getName().compare(cityName) == 0)
            cities[i].displayConnected();
  }
}

void FlightMap :: findFlights( const string deptCity, const string destCity ) const
{

}
void FlightMap :: findLeastCostFlight( const string deptCity, const string destCity )const
{

}
void FlightMap :: runFlightRequests( const string requestFile ) const
{

}
