#include <iostream>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

void combineOne(int arr1[], int arr2[], int n);
void display(int arr[],int n);
void combineTwo(int a[], int b[], int n);

void combineOne(int  arr1[], int arr2[], int n)
{
    double duration1;
    clock_t startTime1 = clock();

    int indexOne = 0;
    int indexTwo = 0;
    int current = 0;
    int* combined = new int[2*n];

    while (indexOne<n && indexTwo <n)
    {
        if (arr1[indexOne] < arr2[indexTwo])
        {
           combined[current] = arr1[indexOne];
           current++;
           indexOne++;
        }

        else
        {
            combined[current] = arr2[indexTwo];
            current++;
            indexTwo++;
        }
    }

    while (indexOne < n)
    {
        combined[current] = arr1[indexOne];
        current++;
        indexOne++;
    }

    while (indexTwo < n)
    {
        combined[current] = arr2[indexTwo];
        current++;
        indexTwo++;
    }

    //display(combined,2*n);

    delete[] combined;

    duration1 = 1000 * double( clock() - startTime1) / CLOCKS_PER_SEC;
    cout <<" Execution took (algorithm 2)" << duration1 << " milliseconds." << endl;
}

void display(int arr[],int n)
{
    cout<<"{ ";

    for(int i = 0; i < n; i++)
    {
       cout<< arr[i]<<" ";
    }

    cout<< "}"<<endl;
}

void combineTwo(int a[], int b[], int n)
{
    double duration1;
    clock_t startTime1 = clock();

    int* combined = new int[2*n];
    int big = 0;

    for(int i = 0; i < n; i++)
    {
        combined[i] = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(b[i] > a[n-1])
        {
            big++;
        }
    }

    if(big == n)
    {
        for(int i = 0; i < n; i++)
        {
            combined[i+n] = b[i];
        }
    }

    else
    {
      for(int j = 0; j < n; j++)
      {
        int index = 0;

        if( b[j] < a[n-1])
        {
            while(b[j] > combined[index] )
            {
               index++;
            }

            for(int k = 2*n - 1; k > index-1; k--)
            {
                combined [k + 1] = combined [k];
            }

            combined[index] = b[j];
        }
        //display(combined,2*n);
      }

      if(big > 0)
      {
        for(int h = 0; h < big; h ++)
        {
            combined[2*n - h-1] = b[n - h-1];
        }
      }
    }

    //display(combined,2*n);

    delete[] combined;
    duration1 = 1000 * double( clock() - startTime1) / CLOCKS_PER_SEC;
    cout <<" Execution took (algorithm 1) " << duration1 << " milliseconds." << endl;
}


int main()
{
    cout<<"CASE 1 ------------------------"<<endl;
    //CASE 1 ********************************************************
    int* ar1 = new int[1000000];
    int* ar2 = new int[1000000];

    for(int i = 0; i < 1000000; i++)
    {
        ar1[i] = i;
        ar2[i] = i + 3000000;
    }

    combineTwo(ar1,ar2,1000000);
    combineOne(ar1,ar2,1000000);

    int* ar3 = new int[2000000];
    int* ar4 = new int[2000000];

    for(int i = 0; i < 2000000; i++)
    {
        ar3[i] = i;
        ar4[i] = i + 2000000;
    }

    combineTwo(ar3,ar4,2000000);
    combineOne(ar3,ar4,2000000);

    int* ar5 = new int[3000000];
    int* ar6 = new int[3000000];

    for(int i = 0; i < 3000000; i++)
    {
        ar5[i] = i;
        ar6[i] = i + 3000000;
    }

    combineTwo(ar5,ar6,3000000);
    combineOne(ar5,ar6,3000000);

    int* ar7 = new int[4000000];
    int* ar8 = new int[4000000];

    for(int i = 0; i < 4000000; i++)
    {
        ar7[i] = i;
        ar8[i] = i + 4000000;
    }

    combineTwo(ar7,ar8,4000000);
    combineOne(ar7,ar8,4000000);


    int* ar9 = new int[5000000];
    int* ar10 = new int[5000000];

    for(int i = 0; i < 5000000; i++)
    {
        ar9[i] = i;
        ar10[i] = i + 5000000;
    }

    combineTwo(ar9,ar10,5000000);
    combineOne(ar9,ar10,5000000);


    //CASE 2 ********************************************************
    cout<<"CASE 2 ------------------------"<<endl;
    combineTwo(ar2,ar1,10000);
    combineOne(ar2,ar1,1000000);

    combineTwo(ar4,ar3,20000);
    combineOne(ar4,ar3,2000000);

    combineTwo(ar6,ar5,30000);
    combineOne(ar6,ar5,3000000);

    combineTwo(ar8,ar7,40000);
    combineOne(ar8,ar7,4000000);

    combineTwo(ar10,ar9,50000);
    combineOne(ar10,ar9,5000000);

    delete[] ar1;
    delete[] ar2;
    delete[] ar3;
    delete[] ar4;
    delete[] ar5;
    delete[] ar6;
    delete[] ar7;
    delete[] ar8;
    delete[] ar9;
    delete[] ar10;


    //CASE 3
    cout<<"CASE 3 ------------------------"<<endl;

    int* a = new int[5000000];
    int* b = new int[5000000];
    for(int i = 0; i < 1000; i++)
      {

            int k;
            k = rand();
            a[i] = k;
      }

    for(int i = 0; i < 1000; i++)
    {
            int k;
            k = rand();
            b[i] = k;
    }

    for(int i = 1000; i < 5000000; i++)
    {
            b[i] = i + 5;
            a[i] = i;
    }

    sort(a, a + 5000000);
    sort(b, b + 5000000);
    combineTwo(a,b,10000);
    combineOne(a,b,1000000);

    combineTwo(a,b,20000);
    combineOne(a,b,2000000);

    combineTwo(a,b,30000);
    combineOne(a,b,3000000);

    combineTwo(a,b,40000);
    combineOne(a,b,4000000);

    combineTwo(a,b,50000);
    combineOne(a,b,5000000);

    delete[] a;
    delete[] b;

   return 0;
}
