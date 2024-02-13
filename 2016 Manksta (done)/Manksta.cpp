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

struct Manksta
{
    string pratimas;
    int sk;
};

void skaitymas(Manksta A[], int & n)
{
    char eil[21];
    ifstream in(Cin);
    in>>n;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 21);
        A[i].pratimas=eil;
        in>>A[i].sk;
        in.ignore(100, '\n');
    }
    in.close();
}

void atrinkimas(Manksta A[], string B[], int n, int & x)
{
    Manksta laik;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(A[i].pratimas>A[j].pratimas)
            {
                laik=A[i];
                A[i]=A[j];
                A[j]=laik;
            }

    x=0;
    for(int i=0; i<n; i++)
    {
        if(A[i-1].pratimas!=A[i].pratimas)
        {
            B[x]=A[i].pratimas;
            x++;
        }
    }
}

void suma(Manksta A[], string B[], int S[], int n, int x)
{
    for(int i=0; i<x; i++)
    {
        int sum=0;

        for(int j=0; j<n; j++)
        {
            if(B[i]==A[j].pratimas)
            {
                sum=sum+A[j].sk;
            }
        }
        S[i]=sum;
    }
}

void rikiavimas(string B[], int S[], int x)
{
    int laik;
    string laik1;

    for(int i=0; i<x-1; i++)
        for(int j=i+1; j<x; j++)
            if(S[i]<S[j])
            {
                laik=S[i];
                S[i]=S[j];
                S[j]=laik;

                laik1=B[i];
                B[i]=B[j];
                B[j]=laik1;
            }
}

void isvedimas(string B[], int S[], int x)
{
    ofstream out(Cout);
    for(int i=0; i<x; i++)
        out<<B[i]<<" "<<S[i]<<endl;
    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Manksta A[100];
    string B[100]; // atrinkti pratimu pavadinimai
    int S[100]; // kiekvieno atlikto pratimo suma
    int n, x;

    skaitymas(A, n);
    atrinkimas(A, B, n, x);
    suma(A, B, S, n, x);
    rikiavimas(B, S, x);
    isvedimas(B, S, x);

    return 0;
}
