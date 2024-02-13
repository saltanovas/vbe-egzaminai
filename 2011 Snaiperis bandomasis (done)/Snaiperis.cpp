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

struct Snaiperis
{
    int sk;
    int metimas[25];
};

void skaitymas(Snaiperis A[], int & n)
{
    int a;
    ifstream in(Cin);
    in>>a>>n;
    for(int i=0; i<n; i++)
    {
        A[i].sk=a;
        for(int j=0; j<A[i].sk; j++)
        {
            in>>A[i].metimas[j];
        }
    }
    in.close();
}

void daugiausiai(Snaiperis A[], int n, int & max, int & maxnr)
{
    max=0;

    for(int i=0; i<n; i++)
    {
        int sum=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(A[i].metimas[j]==1)
            {
                sum=sum+1;
            }
        }
        if(sum>max)
        {
            max=sum;
            maxnr=i+1;
        }
    }
}

void serija(Snaiperis A[], int n, int & did, int & didnr)
{
    did=0;

    for(int i=0; i<n; i++)
    {
        int k=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(A[i].metimas[j]==1) k++;
            if(A[i].metimas[j]==0)
            {
                if(did<k)
                {
                    did=k;
                    didnr=i+1;
                }
                k=0;
            }
                if(did<k)
                {
                    did=k;
                    didnr=i+1;
                }
        }
    }
}

void isvedimas(Snaiperis A[], int n, int maxnr, int max, int didnr, int did)
{
    ofstream out(Cout);

    out<<maxnr<<" "<<max<<endl;
    out<<didnr<<" "<<did<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    Snaiperis A[100];
    int n;
    int max, maxnr, did, didnr;

    skaitymas(A, n);
    daugiausiai(A, n, max, maxnr);
    serija(A, n, did, didnr);
    isvedimas(A, n, maxnr, max, didnr, did);

    return 0;
}
