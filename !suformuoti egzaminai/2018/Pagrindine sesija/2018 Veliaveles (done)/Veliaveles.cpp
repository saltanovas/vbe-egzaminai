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

void skaitymas(char A[], int B[], int & n)
{
    ifstream in(Cin);
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>A[i]>>B[i];
    }
    in.close();
}

void kruveliusk(char A[], int B[], int C[], int n) // suskaiciuoja kiekvienos spalvos suma
{
    for(int i=0; i<3; i++)
    {
        C[i]=0;
    }

    for(int i=0; i<n; i++)
    {
        if(A[i]=='G')
        {
            C[0]=C[0]+B[i];
        }

        if(A[i]=='Z')
        {
            C[1]=C[1]+B[i];
        }

        if(A[i]=='R')
        {
            C[2]=C[2]+B[i];
        }
    }
}


void veliaveliusk(int C[], int & veliaveles) // suskaiciuoja veliavelius skaiciu
{
    int min=C[0];

    for(int i=1; i<3; i++)
    {
        if(min>C[i])
        {
            min=C[i];
        }
    }
    veliaveles=min/2;
}

void isvedimas(int C[], int veliaveles)
{
    ofstream out(Cout);
    out<<veliaveles<<endl;
    out<<"G = "<<C[0]-veliaveles*2<<endl;
    out<<"Z = "<<C[1]-veliaveles*2<<endl;
    out<<"R = "<<C[2]-veliaveles*2<<endl;;
    out.close();
}


int main()
{
    setlocale (LC_ALL, "Lithuanian");

    char A[30]; // kruveles masyvas
    int B[30]; // kruveles skaiciaus masyvas
    int C[3]; // atrinktu spalvu skaiciaus masyvas
    int veliaveles; // veliaveliu skaicius
    int n;

    skaitymas(A, B, n);
    kruveliusk(A, B, C, n);
    veliaveliusk(C, veliaveles);
    isvedimas(C, veliaveles);

    return 0;
}
