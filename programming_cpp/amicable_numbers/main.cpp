#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>

using namespace std;

int oszto_osszeg(int);
bool tokeletes(int);
bool bovelkedo(int);
bool hianyos(int);
bool baratsagos(int, int);
int beolvas_int(const string&);
int beolvas_nat(const string&);
int calcDivisorsSum(int);

int main()
{

    cout << "Onallo feladatok!" << endl;
    int n=beolvas_nat("Meddig irjam ki a szamokat:");
/*
    //  Tökéletes számok kiírása n-ig
    cout<<"\nTokeletes szamok\n";
    for(int i=1; i<=n; ++i)
        if(tokeletes(i)) cout<<i<<"\t";
    cout<<endl;


    //Bővelkedő számok kiírása n-ig
    cout<<"\nBovelkedo szamok\n";
    for(int i=1; i<=n; ++i)
        if(bovelkedo(i)) cout<<i<<"\t";
    cout<<endl;


    //Hiányos számok kiírása n-ig
    cout<<"\nHianyos szamok\n";
    for(int i=1; i<=n; ++i)
        if(hianyos(i)) cout<<i<<"\t";
    cout<<endl;

*/
    //Barátságos számpárok kiírása n-ig
    cout <<"\nBaratsagos szamok\n";

    // Start measuring runtime...
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int div_sum_x1;
    int div_sum_x2=1;
    int i=2;
    float limit;

    int already_found[1000]={0};
    int already_found_counter=0;
    int j=0;

    for(int x1=1; x1<=n; ++x1)
    {
        div_sum_x1 = calcDivisorsSum(x1);

        if(div_sum_x1 != x1) // if not perfect, continue
        {
            limit = sqrt(div_sum_x1);

            while(i < limit  && div_sum_x2 <= x1)
            {
                if(div_sum_x1 % i == 0)
                {
                    div_sum_x2 += i;
                    div_sum_x2 += div_sum_x1 / i;
                }
                ++i;
            }

            if(i == limit)
            {
                if(div_sum_x1 % i == 0)
                {
                    div_sum_x2 += i;
                }
            }

            if( div_sum_x2 == x1)
            {
                while(j < already_found_counter && x1 != already_found[already_found_counter-j-1])
                {
                    j++;
                }
                if(j == already_found_counter)
                {
                    cout << x1 << " " << div_sum_x1 << endl;
                    already_found[already_found_counter] = div_sum_x1;
                    already_found_counter++;
                }
                j=0;

            }
        }
        i=2;
        div_sum_x2 = 1;
    }

    // Stop measureing runtime and print time taken
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference (sec) = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0  <<std::endl;

    cout<<endl;
    return 0;
}

//bool baratsagos(int x1, int x2)
//{
//    if(x1 != x2 && x1 > 0 && x2 > 0)
//    {
//        if(x1 == calcDivisorsSum(x2) && x2 == calcDivisorsSum(x1))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        return false;
//    }
//}


int calcDivisorsSum(int input_number)
{
    int sum_of_divisors=1;

    int i=2;

    // Look for divisors only until the square root of a given number and if a divisor is found (eg. i|N),
    // add its divisor pair as well (N div i).
    float limit = sqrt(input_number);
    while(i < limit)
    {
        if(input_number % i ==0)
        {
            sum_of_divisors += i;
            sum_of_divisors += input_number / i;
        }
        i++;
    }

    // If input was a square number, add the divisor "at the center" without its divisor pair.
    // (eg. {1, 2, 4, 8, 16} | 16 then add 4 only once
    if(i == sqrt(input_number))
    {
        sum_of_divisors += i;
    }

    return sum_of_divisors;
}

bool tokeletes(int input_number)
{
    return input_number == calcDivisorsSum(input_number) ? true : false;
}

bool bovelkedo(int input_number)
{
    return input_number < calcDivisorsSum(input_number) ? true : false;
}

bool hianyos(int input_number)
{
    return input_number > calcDivisorsSum(input_number) ? true : false;
}

int beolvas_int(const string &sz){
    string s;
    bool hiba;
    int e;
    do{
        cout<<sz;
        cin>>e;
        hiba=cin.fail();
        if (hiba){
            cout<<"Ez nem egesz szam, add meg ujra!\n";
            cin.clear();  //hiba flag-ek tölése
        }
        getline(cin,s); //Enter-ig a puffer kitisztítása
        if(!hiba && s!="")
        {
            hiba=true;
            cout<<"A beirt szam utan felesleges karakterek vannak! Add meg ujra!\n";
        }
    }while (hiba);
    return e;
}

int beolvas_nat(const string &sz){
    bool hiba;
    int e;
    do{
        e=beolvas_int(sz);
        hiba=e<=0;
        if(hiba)
        {
            cout<<"Pozitiv legyen! Add meg ujra!\n";
        }
    }while(hiba);
    return e;
}


