#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>

using namespace std;

const char Cin[]="P2.txt";
const char Cout[]="P2rez.txt";

struct Mokykla
{
    string miestas, mokykla[100];
    int sk, reit[100];

    string nmokykla;
    int nreit;
};

void skaitymas(Mokykla A[], int & n)
{
    ifstream in(Cin);
    char eil[16];
    char eil1[31];
    in>>n;
    in.ignore();
    for(int i=0; i<n; i++)
    {
        in.get(eil, 16);
        A[i].miestas=eil;
        in>>A[i].sk;
        in.ignore();
        for(int j=0; j<A[i].sk; j++)
        {
            in.get(eil1, 31);
            A[i].mokykla[j]=eil1;
            in>>A[i].reit[j];
            in.ignore();
        }
    }
}


void rikiavimas(Mokykla A[], int n)
{
    int laik;
    string laik1;

    for(int i=0; i<n; i++)
        for(int j=0; j<A[i].sk-1; j++)
            for(int k=j+1; k<A[i].sk; k++)
                if(A[i].reit[j]<A[i].reit[k])
                {
                    laik1=A[i].mokykla[j];
                    A[i].mokykla[j]=A[i].mokykla[k];
                    A[i].mokykla[k]=laik1;

                    laik=A[i].reit[j];
                    A[i].reit[j]=A[i].reit[k];
                    A[i].reit[k]=laik;
                }
}

void atrinkimas(Mokykla A[], Mokykla B[], int n, int & x)
{
    x=0;

    for(int i=0; i<n; i++)
    {
        while(A[i].sk!=0)
        {
            A[x].nmokykla=A[i].mokykla[0];
            A[x].nreit=A[i].reit[0];
            A[i].sk=0;
        }
        x++;
    }

    int laik;
    string laik1;

         for(int i=0; i<x-1; i++)
            for(int j=i+1; j<x; j++)
                if(A[i].nreit<A[j].nreit)
                {
                    laik1=A[i].nmokykla;
                    A[i].nmokykla=A[j].nmokykla;
                    A[j].nmokykla=laik1;

                    laik=A[i].nreit;
                    A[i].nreit=A[j].nreit;
                    A[j].nreit=laik;

                    laik1=A[i].miestas;
                    A[i].miestas=A[j].miestas;
                    A[j].miestas=laik1;

                }
}

void isvedimas(Mokykla A[], int n, int x)
{
    ofstream out(Cout);

    for(int i=0; i<n; i++)
    {
        out<<A[i].miestas<<" ";
        for(int j=0; j<1; j++)
        {
            out<<A[i].nmokykla<<" "<<A[i].nreit<<endl;
        }
    }

    out.close();
}


int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Mokykla A[100], B[100];
    int n, x;

    skaitymas(A, n);
    rikiavimas(A, n);
    atrinkimas(A, B, n, x);
    isvedimas(A, n, x);

    return 0;
}
