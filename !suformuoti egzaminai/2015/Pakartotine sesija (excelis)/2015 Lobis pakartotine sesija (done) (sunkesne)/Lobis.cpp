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

    for(int i=0; i<5; i++)
        in>>A[i];

    for(int i=0; i<10; i++)
        B[i]=0;

    in.close();
}

void skaiciavimas(int A[], int B[])
{
    for(int i=0; i<5; i++)
    {
        int j=i+1;
        while(A[i]>0 && j<10)
        {
            A[i]=A[i]-1;
            B[j]=B[j]+1;
            j++;
        }
        B[i]+=A[i]; //nesuprantama vieta
    }
}

void isvedimas(int B[])
{
    ofstream out(Cout);

    for(int i=0; i<10; i++)
        out<<B[i]<<" ";

    out.close();
}

int main()
{
    int A[5], B[10];

    skaitymas(A, B);
    skaiciavimas(A, B);
    isvedimas(B);

    return 0;
}
