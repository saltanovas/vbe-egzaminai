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

struct Miestai
{
    string miestas;
    string apskritis;
    int gyventojai;
};

struct Atrinkta
{
    string apskritis;
    int min;
    int suma;
};

void skaitymas(Miestai A[], int & k)
{
    char eil[21];
    char eil1[14];
    ifstream in(Cin);
    in>>k;
    in.ignore(100, '\n');
    for(int i=0; i<k; i++)
    {
        in.get(eil, 21);
        A[i].miestas=eil;

        in.get(eil1, 14);
        A[i].apskritis=eil1;

        in>>A[i].gyventojai;

        in.ignore(100, '\n');
    }
    in.close();
}

void rikiavimas(Miestai A[], int k)
{
    Miestai laik;

    for(int i=0; i<k-1; i++)
        for(int j=i+1; j<k; j++)
            if(A[i].gyventojai>A[j].gyventojai)
            {
                laik=A[i];
                A[i]=A[j];
                A[j]=laik;
            }

    for(int i=0; i<k-1; i++)
        for(int j=i+1; j<k; j++)
            if(A[i].gyventojai==A[j].gyventojai)
            {
                if(A[i].apskritis>A[j].apskritis)
                {
                    laik=A[i];
                    A[i]=A[j];
                    A[j]=laik;
                }
            }
}

void atrinkimas(Miestai A[], Atrinkta B[], int k, int & x)
{
    B[0].apskritis=A[0].apskritis;
    x=1;

    for(int i=1; i<k; i++)
    {
        int sum=0;

        for(int j=0; j<x; j++)
        {
            if(B[j].apskritis==A[i].apskritis)
            {
                sum=sum+1;
            }
        }
        if(sum==0)
        {
            B[x].apskritis=A[i].apskritis;
            x++;
        }
    }
}

void maziausias(Miestai A[], Atrinkta B[], int k, int x)
{
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(B[i].apskritis==A[j].apskritis)
            {
                B[i].min=A[j].gyventojai;
                j=k;
            }
        }
    }
}

void suma(Miestai A[], Atrinkta B[], int k, int x)
{
    for(int i=0; i<x; i++)
    {
        int sum=0;

        for(int j=0; j<k; j++)
        {
            if(B[i].apskritis==A[j].apskritis)
            {
                sum=sum+A[j].gyventojai;
            }
        }
        B[i].suma=sum;
    }
}

void isvedimas(Atrinkta B[], int x)
{
    ofstream out(Cout);
    out<<x<<endl;
    for(int i=0; i<x; i++)
    {
        out<<B[i].apskritis<<" "<<B[i].min<<" "<<B[i].suma<<endl;
    }
    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Miestai A[103];
    Atrinkta B[103];
    int k, x;

    skaitymas(A, k);
    rikiavimas(A, k);
    atrinkimas(A, B, k, x);
    maziausias(A, B, k, x);
    suma(A, B, k, x);
    isvedimas(B, x);

    return 0;
}
