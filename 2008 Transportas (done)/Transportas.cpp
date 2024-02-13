#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct Transportas
{
    string pavadinimas;
    int sk;
    int numeris[100];

};

const char Cin[]="U2.txt";
const char Cout[]="U2rez.txt";

void skaitymas(Transportas A[], int & n)
{
    char eil[21];
    ifstream in(Cin);
    in>>n;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 21);
        A[i].pavadinimas=eil;
        in>>A[i].sk;

        for(int j=0; j<A[i].sk; j++)
        {
            in>>A[i].numeris[j];
        }
        in.ignore(100, '\n');
    }
    in.close();
}

void atrinkimas(Transportas A[], int S[], int SUM[], int n, int & y)
{
    int B[100]; // masyvas naudojamas visiems duomenims laikyti
    int x=0;

    for(int i=0; i<n; i++) // visi numeriai sudedami i viena masyva
    {
        for(int j=0; j<A[i].sk; j++)
        {
            B[x]=A[i].numeris[j];
            x++;
        }
    }

    int laik;
    for(int i=0; i<x-1; i++) // isrikiuojami visi duomenys
        for(int j=i+1; j<x; j++)
            if(B[i]>B[j])
            {
                laik=B[i];
                B[i]=B[j];
                B[j]=laik;
            }

    y=0;
    for(int i=0; i<x; i++) // atreankami nepasikartojantys duomenys
    {
        if(B[i-1]!=B[i])
        {
            S[y]=B[i];
            y++;
        }
    }

    int z=0;
    for(int i=0; i<y; i++) // skaiciuojama kiek yra duomenu
    {
        for(int j=0; j<x; j++)
        {
            if(S[i]==B[j])
            {
                SUM[z]=SUM[z]+1;
            }
        }
        z++;
    }
}

void ilgiausias(int SUM[], int S[], int y, int & nr)
{
    int max=0;

    for(int i=0; i<y; i++)
    {
        if(SUM[i]>max)
        {
            max=SUM[i];
            nr=S[i];
        }
    }
}

void isvedimas(Transportas A[], int n, int nr)
{
    ofstream out(Cout);

    out<<nr<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<A[i].sk; j++)
        {
            if(nr==A[i].numeris[j])
            {
                out<<A[i].pavadinimas<<endl;
            }
        }
    }
    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Transportas A[100];
    int S[100]; //nepasikartojanciu duomenu masyvas
    int SUM[100]; // nepasikartojanciu duomenu sumos masyvas
    int n, y;
    int nr; //ilgiausio marsruto numeris

    skaitymas(A, n);
    atrinkimas(A, S, SUM, n, y);
    ilgiausias(SUM, S, y, nr);
    isvedimas(A, n, nr);

    return 0;
}
