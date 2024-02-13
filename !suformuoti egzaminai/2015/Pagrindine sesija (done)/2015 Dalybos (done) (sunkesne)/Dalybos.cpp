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

void skaitymas(int A[], int B[])
{
    ifstream in(Cin);

    for(int i=0; i<10; i++)
    {
        in>>A[i];
        B[i]=10-A[i];
    }

    for(int i=10; i<20; i++)
        A[i]=0;

    in.close();
}

void skaiciavimas(int A[], int B[])
{
    for(int i=0; i<10; i++)
    {
        int j=i+1;
        while(B[i]>0)
        {
            A[j]=A[j]+1;
            B[i]=B[i]-1;
            j++;
        }
    }
}

void isvedimas(int A[])
{
    ofstream out(Cout);

    for(int i=0; i<20; i++)
        out<<A[i]<<" ";

    out.close();
}

int main()
{
    int A[20], B[10];

    skaitymas(A, B);
    skaiciavimas(A, B);
    isvedimas(A);

    return 0;
}
