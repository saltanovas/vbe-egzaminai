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

struct Krepsinis
{
    int sk;
    int laikas[40];
};

void skaitymas(Krepsinis A[], int NR[], int & n)
{
    ifstream in(Cin);
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>NR[i]>>A[i].sk;
        for(int j=0; j<A[i].sk; j++)
        {
            in>>A[i].laikas[j];
        }
    }
    in.close();
}

void rikiavimas(Krepsinis A[], int NR[], int n)
{
    int laik;
    Krepsinis laik1;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(NR[i]>NR[j])
            {
                laik=NR[i];
                NR[i]=NR[j];
                NR[j]=laik;

                laik1=A[i];
                A[i]=A[j];
                A[j]=laik1;
            }
}

void penketukas(Krepsinis A[], int NR[], int P[], int n, int & x)
{
    x=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<1; j++)
        {
            if(A[i].laikas[j]>0)
            {
                P[x]=NR[i];
                x++;
            }
            break;
        }
    }
}

void zaidesuma(Krepsinis A[], int ZS[], int n)
{
    for(int i=0; i<n; i++)
    {
        int sum=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(A[i].laikas[j]>0)
            {
                sum=sum+A[i].laikas[j];
            }
        }
        ZS[i]=sum;
    }
}

void daugiausiai(int ZS[], int NR[], int n, int & did, int & didnr)
{
    int max=0;

    for(int i=0; i<n; i++)
    {
        if(ZS[i]>max)
        {
            max=ZS[i];
            did=ZS[i];
            didnr=NR[i];
        }
    }
}

void nezaidesuma(Krepsinis A[], int NS[], int n)
{
    for(int i=0; i<n; i++)
    {
        int sum=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(A[i].laikas[j]<0)
            {
                sum=sum+A[i].laikas[j];
            }
        }
        NS[i]=sum;
    }
}

void maziausiai(int NS[], int NR[], int n, int & maz, int & maznr)
{
    int min=0;

    for(int i=0; i<n; i++)
    {
        if(NS[i]<min)
        {
            min=NS[i];
            maz=NS[i];
            maznr=NR[i];
        }
    }
}

void isvedimas(int C[], int x, int didnr, int did, int maznr, int maz)
{
    ofstream out(Cout);

    for(int i=0; i<x; i++)
        out<<C[i]<<" ";
    out<<endl;
    out<<didnr<<" "<<did<<endl;
    out<<maznr<<" "<<fabs(maz)<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Krepsinis A[100]; //koki nurodytyi masyvo dydi?
    int NR[95], P[5]; //krepsininku numeriai ir atrinktas penketukas
    int ZS[12], NS[12]; //zaidusiu ir nezaidusiu zaideju suma
    int n, x;
    int did, didnr, maz, maznr;

    skaitymas(A, NR, n);
    rikiavimas(A, NR, n);
    penketukas(A, NR, P, n, x);
    zaidesuma(A, ZS, n);
    daugiausiai(ZS, NR, n, did, didnr);
    nezaidesuma(A, NS, n);
    maziausiai(NS, NR, n, maz, maznr);
    isvedimas(P, x, didnr, did, maznr, maz);

    return 0;
}
