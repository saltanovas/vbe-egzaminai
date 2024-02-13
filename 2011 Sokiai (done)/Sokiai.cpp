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

struct Sokiai
{
    string vardas;
    int tech[10], art[10];
};

void skaitymas(Sokiai A[], int & n, int & k)
{
    char eil[21];
    ifstream in(Cin);
    in>>n>>k;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 21);
        A[i].vardas=eil;
        in.ignore(100, '\n');

        for(int j=0; j<k; j++)
            in>>A[i].tech[j];

        for(int x=0; x<k; x++)
            in>>A[i].art[x];

        in.ignore(100, '\n');
    }

    in.close();
}

void rikiavimas(Sokiai A[], int n, int k)
{
    int laik;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k-1; j++)
        {
            for(int x=j+1; x<k; x++)
            {
                if(A[i].tech[j]<A[i].tech[x])
                {
                    laik=A[i].tech[j];
                    A[i].tech[j]=A[i].tech[x];
                    A[i].tech[x]=laik;
                }

            }

            for(int y=j+1; y<k; y++)
            {
                if(A[i].art[j]<A[i].art[y])
                {
                    laik=A[i].art[j];
                    A[i].art[j]=A[i].art[y];
                    A[i].art[y]=laik;
                }
            }
        }
    }
}

void suma(Sokiai A[], int S[], int n, int k)
{
    for(int i=0; i<n; i++)
    {
        int sum=0;

        for(int j=1; j<k-1; j++)
        {
            sum=sum+A[i].tech[j];
        }

        for(int y=1; y<k-1; y++)
        {
            sum=sum+A[i].art[y];
        }
        S[i]=sum;
    }

    int laik;
    string laik1;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(S[i]<S[j])
            {
                laik=S[i];
                S[i]=S[j];
                S[j]=laik;

                laik1=A[i].vardas;
                A[i].vardas=A[j].vardas;
                A[j].vardas=laik1;
            }
}

void isvedimas(Sokiai A[], int S[], int n, int k)
{
    ofstream out(Cout);

    for(int i=0; i<n; i++)
        out<<A[i].vardas<<" "<<S[i]<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Sokiai A[50];
    int S[50];
    int n, k;

    skaitymas(A, n, k);
    rikiavimas(A, n, k);
    suma(A, S, n, k);
    isvedimas(A, S, n, k);

    return 0;
}
