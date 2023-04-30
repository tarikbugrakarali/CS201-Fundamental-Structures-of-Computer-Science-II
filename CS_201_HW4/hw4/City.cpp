#include "City.h"
#include <string>
#include <iostream>
#include <iomanip>


 City :: City(  )
 {
     name = "";
     connected = new string [0];
     price = new int [0];
     connected = new string [0];
     counter = 0;
 }
City :: ~City()
{

}
string City :: getName()
{
 return name;
}
void City :: setName(string cityName)
{
    name = cityName;
}

void City :: addCon(string conCity)
{
    counter ++;
    //cout<< counter <<endl;
    string* temp = new string [counter];
    temp[counter - 1] = conCity;

    for(int i = 0; i < counter - 1; i ++)
       temp[i] = connected [i];

    connected = temp;

}
void City :: addPrice(int cost)
{
    int* temp = new int [counter];
    temp[counter - 1] = cost;

    for(int i = 0; i < counter - 1; i ++)
       temp[i] = price [i];

    price = temp;

}
void City :: addId(int Id)
{
    int* temp = new int [counter];
    temp[counter - 1] = Id;

    for(int i = 0; i < counter - 1; i ++)
       temp[i] = id [i];

    id = temp;
}
void City :: displayConnected()
{

 // cout<< counter <<endl;
  cout<<name<< " -> ";
  for(int i = 0; i < counter; i++)
  {
      //cout<< ed[i]<<" , price :" << price[i] << " , ID : "<< id[i] <<endl;
      cout<< connected[i] <<" , " ;
  }
  cout<<endl;
}


