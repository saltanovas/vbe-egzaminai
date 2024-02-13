#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>

using namespace std;

const char Cin[]="U2.txt";
const char Cout[]="U2rez.txt";

struct Varzybos
{
    string vardas[50];
    int laikas[50];
    int sk;

    string nvardas;
    int nlaikas;
};

void skaitymas(Varzybos A[], int & n)
{
    char eil[21];
    int min, sek;
    ifstream in(Cin);
    in>>n;
    in.ignore();
    for(int i=0; i<n; i++)
    {
        in>>A[i].sk;
        in.ignore();
        for(int j=0; j<A[i].sk; j++)
        {
            in.get(eil, 21);
            A[i].vardas[j]=eil;
            in>>min>>sek;
            A[i].laikas[j]=min*60+sek;
            in.ignore();
        }
    }
    in.close();
}

void rikiavimas(Varzybos A[], int n)
{
    int laik;
    string laik1;

    for(int i=0; i<n; i++)
        for(int j=0; j<A[i].sk-1; j++)
            for(int k=j+1; k<A[i].sk; k++)
                if(A[i].laikas[j]>A[i].laikas[k])
                {
                    laik=A[i].laikas[j];
                    A[i].laikas[j]=A[i].laikas[k];
                    A[i].laikas[k]=laik;

                    laik1=A[i].vardas[j];
                    A[i].vardas[j]=A[i].vardas[k];
                    A[i].vardas[k]=laik1;
                }
}

void atrinkimas(Varzybos A[], int n, int & x)
{
    x=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<A[i].sk/2; j++)
        {
            A[x].nlaikas=A[i].laikas[j];
            A[x].nvardas=A[i].vardas[j];
            x++;
        }
    }

    int laik;
    string laik1;

    for(int i=0; i<x-1; i++)
        for(int j=i+1; j<x; j++)
            if(A[i].nlaikas>A[j].nlaikas)
            {
                laik=A[i].nlaikas;
                A[i].nlaikas=A[j].nlaikas;
                A[j].nlaikas=laik;

                laik1=A[i].nvardas;
                A[i].nvardas=A[j].nvardas;
                A[j].nvardas=laik1;
            }
}

void isvedimas(Varzybos A[], int x)
{
    ofstream out(Cout);

    for(int i=0; i<x; i++)
        out<<A[i].nvardas<<" "<<A[i].nlaikas/60<<" "<<A[i].nlaikas%60<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Varzybos A[50]; //kiek cia elementu reikia apsirasyti?
    int n, x;

    skaitymas(A, n);
    rikiavimas(A, n);
    atrinkimas(A, n, x);
    isvedimas(A, x);


    return 0;
}
