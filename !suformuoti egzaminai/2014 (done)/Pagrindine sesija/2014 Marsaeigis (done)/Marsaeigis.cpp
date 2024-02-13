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

struct Marsaeigis
{
    int sk;
    int komanda[300]; //ar gerai aprasiau?
    int stabdymas[300];
    int kiekis;
    string priezastis;
};


void skaitymas(Marsaeigis A[], int & x0, int & y0, int & x1, int & y1, int & n)
{
    ifstream in(Cin);
    in>>x0>>y0;
    in>>x1>>y1;
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>A[i].sk;
        for(int j=0; j<A[i].sk; j++)
        {
            in>>A[i].komanda[j];
        }
    }
    in.close();
}

void skaiciavimas(Marsaeigis A[], int x0, int y0, int x1, int y1, int n)
{
    int kopijax=x0; // issaugojama marsaeigio pradine padetis
    int kopijay=y0;

    for(int i=0; i<n; i++)
    {
        int x=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(x0!=x1 || y0!=y1)
            {
                if(A[i].komanda[j]==1) y0++;
                else if(A[i].komanda[j]==2) x0++;
                else if(A[i].komanda[j]==3) y0--;
                else if(A[i].komanda[j]==4) x0--;

                A[i].stabdymas[j]=A[i].komanda[j]; //irasomos marsaeigio komandos
                x++; //marsaeigio komandu skaicius
            }
        }
        A[i].kiekis=x;//marsaeigio komandu skaiciaus irasymas i masyva

        if(x0==x1 && y0==y1)
        {
            A[i].priezastis="pasiektas tikslas";
        }
        else
        {
            A[i].priezastis="sekos pabaiga";
        }

        x0=kopijax; // grazina pradine marsaeigio padeti
        y0=kopijay;
    }
}

void isvedimas(Marsaeigis A[], int n)
{
    ofstream out(Cout);

    for(int i=0; i<n; i++)
    {
        out<<left<<setw(20)<<A[i].priezastis<<" ";

        for(int j=0; j<A[i].kiekis; j++)
        {
            out<<A[i].stabdymas[j]<<" ";
        }
        out<<A[i].kiekis<<endl;
    }

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Litxuanian");

    Marsaeigis A[300];
    int x0, y0, x1, y1;
    int n;

    skaitymas(A, x0, y0, x1, y1, n);
    skaiciavimas(A, x0, y0, x1, y1, n);
    isvedimas(A, n);

    return 0;
}
