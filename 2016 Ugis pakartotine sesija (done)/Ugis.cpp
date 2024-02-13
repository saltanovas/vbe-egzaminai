#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>

using namespace std;

const char Cin[]="U1.txt";
const char Cout[]="U1rez.txt";


void vidurkis(int & vid)
{
    int sum=0;
    int ugis, x;

    ifstream in(Cin);

    in>>x;
    for(int i=0; i<n; i++)
    {
        in>>ugis;
        sum=sum+ugis;
    }
    vid=sum/x;

    in.close();
}

void didesnis(int vid, int & k)
{
    int ugis, x;
    k=0;

    ifstream in(Cin);

    in>>x;
    for(int i=0; i<n; i++)
    {
        in>>ugis;
        if(ugis>vid)k++;
    }

    in.close();
}

void isvedimas(int vid, int k)
{
    ofstream out(Cout);

    out<<vid<<" "<<k<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    int vid; //ugiu vidurkis
    int k; // mokiniu, aukstesniu uz vidurki, skaicius

    vidurkis(vid);
    didesnis(vid, k);
    isvedimas(vid, k);

    return 0;
}
