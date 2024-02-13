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

struct Takai
{
    string pavadinimas;
    int laikas;
};

void skaitymas(Takai A[], int & n)
{
    char eil[21];
    ifstream in(Cin);
    in>>n;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 21);
        A[i].pavadinimas=eil;
        in>>A[i].laikas;
        in.ignore(100, '\n');
    }

    in.close();
}

void rikiavimas(Takai A[], int n)
{
    Takai laik;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(A[i].pavadinimas>A[j].pavadinimas)
            {
                laik=A[i];
                A[i]=A[j];
                A[j]=laik;
            }
}

void skaiciavimas(Takai A[], string P[], int S[], int n, int & x)
{
    P[0]=A[0].pavadinimas;
    x=1;

    for(int i=1; i<n; i++)
    {
       int sum=0;

        for(int j=0; j<x; j++)
        {
            if(A[i].pavadinimas==P[j])
                sum=sum+1;
        }
        if(sum==0)
        {
            x=x+1;
            P[x-1]=A[i].pavadinimas;
        }
    }

    /*for(int i=0; i<n; i++)
    {
        if(A[i-1].pavadinimas!=A[i].pavadinimas)
        {
            P[x]=A[i].pavadinimas;
            x++;
        }
    }*/

    for(int i=0; i<x; i++)
    {
        int sum=0;

        for(int j=0; j<n; j++)
        {
            if(P[i]==A[j].pavadinimas)
            {
                sum=sum+A[j].laikas;
            }
        }

        S[i]=sum;
    }
}

void isvedimas(int S[], string P[], int x)
{
    ofstream out(Cout);

    for(int i=0; i<x; i++)
    {
        out<<P[i]<<" "<<S[i]<<endl;
    }

    out.close();
}

int main()
{
    Takai A[30];
    string P[30];
    int S[30];
    int n, x;

    skaitymas(A, n);
    rikiavimas(A, n);
    skaiciavimas(A, P, S, n, x);
    isvedimas(S, P, x);

    return 0;
}
