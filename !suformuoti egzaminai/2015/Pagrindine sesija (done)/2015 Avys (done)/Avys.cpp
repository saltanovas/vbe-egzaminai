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

struct Avys
{
    string vardas;
    char dnr[20];
    int suma;
};

void skaitymas(Avys A[], int & n, int & m, int & nr, string & avis)
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
            in>>A[i].dnr[j];
        }
        in.ignore(100, '\n');
    }
    avis=A[nr-1].vardas;

    in.close();
}

void palyginimas(Avys A[], int n, int m, int nr)
{
    for(int i=0; i<n; i++)
    {
        int sum=0;

        for(int j=0; j<m; j++)
        {
            if(A[i].dnr[j]==A[nr-1].dnr[j])
            {
                sum++;
            }
        }
        A[i].suma=sum;
    }
}

void rikiavimas(Avys A[], int n, int m, int nr)
{
    Avys laik;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i].suma<A[j].suma)
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

void isvedimas(Avys A[], int n, int nr, string avis)
{
    ofstream out(Cout);
    out<<avis<<endl;
    for(int i=0; i<n; i++)
    {
        if(A[i].vardas!=avis)
        {
            out<<A[i].vardas<<" "<<A[i].suma<<endl;
        }
    }
    out.close();
}

int main()
{
    Avys A[20];
    string avis;
    int n, m, nr;

    skaitymas(A, n, m, nr, avis);
    palyginimas(A, n, m, nr);
    rikiavimas(A, n, m, nr);
    isvedimas(A, n, nr, avis);

    return 0;
}
