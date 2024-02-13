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

struct Gimtadienis
{
    int kaina;
    int kiekis[10];
    string produktas;
};

void skaitymas(Gimtadienis A[], int & n, int & p)
{
    char eil[16];
    ifstream in(Cin);
    in>>n>>p;

    for(int i=0; i<n; i++)
        in>>A[i].kaina;

    in.ignore(100, '\n');

    for(int i=0; i<p; i++)
    {
        in.get(eil, 16);
        A[i].produktas=eil;

        for(int j=0; j<n; j++)
        {
            in>>A[i].kiekis[j];
        }
        in.ignore(100, '\n');
    }
    in.close();
}

void skaiciavimas(Gimtadienis A[], int S[], int n, int p)
{
    for(int i=0; i<p; i++)
    {
        int sum=0;

        for(int j=0; j<n; j++)
        {
            sum=sum+(A[j].kaina*A[i].kiekis[j]);
        }
        S[i]=sum;
    }
}

void kaina(int S[], int p, int & sum)
{
    sum=0;
    for(int i=0; i<p; i++)
        sum=sum+S[i];
}

void isvedimas(Gimtadienis A[], int S[], int p, int sum)
{
    ofstream out(Cout);

    for(int i=0; i<p; i++)
        out<<A[i].produktas<<" "<<S[i]<<endl;

    out<<sum/100<<" "<<sum%100<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Gimtadienis A[12];
    int S[12]; // kiekvieno produkta kaina centais
    int n, p;
    int sum; //vieno sveciu pietu kaina centais

    skaitymas(A, n, p);
    skaiciavimas(A, S, n, p);
    kaina(S, p, sum);
    isvedimas(A, S, p, sum);

    return 0;
}
