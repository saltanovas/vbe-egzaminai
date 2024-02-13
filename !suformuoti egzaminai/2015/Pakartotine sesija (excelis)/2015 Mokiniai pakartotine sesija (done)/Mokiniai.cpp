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
const char Cout[]="U2Rez.txt";

struct Mokiniai
{
    string vardas;
    char atsakymai[10];
    int suma;
};

void skaitymas(Mokiniai A[], int & n, int & m, int & nr, string & mokytojas)
{
    char eil[11];
    ifstream in(Cin);
    in>>n>>m;
    in>>nr;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 11);
        A[i].vardas=eil;
        for(int j=0; j<m; j++)
        {
            in>>A[i].atsakymai[j];
        }
        in.ignore(100, '\n');
    }
    mokytojas=A[nr-1].vardas;

    in.close();
}

void palyginimas(Mokiniai A[], int S[], int n, int m, int nr)
{
    for(int i=0; i<n; i++)
    {
        int sum=0;

        for(int j=0; j<m; j++)
        {
            if(A[i].atsakymai[j]==A[nr-1].atsakymai[j])
            {
                sum++;
            }
        }
        A[i].suma=sum;
    }
}

void rikiavimas(Mokiniai A[], int n, int m, int nr)
{
    Mokiniai laik;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i].suma>A[j].suma)
            {
                laik=A[i];
                A[i]=A[j];
                A[j]=laik;
            }
        }
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i].suma==A[j].suma)
            {
                if(A[i].vardas>A[j].vardas)
                {
                    laik=A[i];
                    A[i]=A[j];
                    A[j]=laik;
                }
            }
        }
    }
}

void isvedimas(Mokiniai A[], int n, int nr, string mokytojas)
{
    ofstream out(Cout);
    out<<mokytojas<<endl;
    for(int i=0; i<n; i++)
    {
        if(A[i].vardas!=mokytojas)
        {
            out<<A[i].vardas<<" "<<A[i].suma<<endl;
        }
    }
    out.close();
}

int main()
{
    Mokiniai A[10];
    string mokytojas;
    int S[10];
    int n, m, nr;

    skaitymas(A, n, m, nr, mokytojas);
    palyginimas(A, S, n, m, nr);
    rikiavimas(A, n, m, nr);
    isvedimas(A, n, nr, mokytojas);

    return 0;
}
