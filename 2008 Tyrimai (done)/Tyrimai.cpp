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

void skaitymas(int A[], int B[], int & n)
{
    ifstream in(Cin);
    in>>n;
    for(int i=0; i<n; i++)
        in>>A[i]>>B[i];
    in.close();
}

void atrinkimas(int A[], int B[], int C[], int n, int & x)
{
    int laik;

    for(int i=0; i<n-1; i++) //isrikiuoja stoteliu numerius didejimo tvarka
        for(int j=i+1; j<n; j++)
            if(A[i]>A[j])
            {
                laik=A[i];
                A[i]=A[j];
                A[j]=laik;

                laik=B[i];
                B[i]=B[j];
                B[j]=laik;
            }
    x=0;

    for(int i=0; i<n; i++) //atrenka nepasikartojancias stoteles
        if(A[i]!=A[i+1])
        {
            C[x]=A[i];
            x++;
        }
}

void keleiviai(int A[], int B[], int C[], int S1[], int S2[], int n, int x)
{
    for(int i=0; i<x; i++) //nunulina iliptu ir isliptu keleiviu sumu masyvus
    {
        S1[i]=0;
        S2[i]=0;
    }

    for(int i=0; i<x; i++)
        for(int j=0; j<n; j++)
        {
            if(C[i]==A[j] && B[j]>0) S1[i]=S1[i]+B[j];

            if(C[i]==A[j] && B[j]<0) S2[i]=S2[i]+B[j];
        }
}

void daugiausia(int C[], int S1[], int x, int & did)
{
    int max=0;

    for(int i=0; i<x; i++)
        if(S1[i]>max)
        {
            max=S1[i];
            did=C[i];
        }
}

void isvedimas(int C[], int S1[], int S2[], int x, int did)
{
    ofstream out(Cout);

    for(int i=0; i<x; i++)
        out<<right<<setw(5)<<C[i]<<" ";

    out<<endl;

    for(int i=0; i<x; i++)
        out<<right<<setw(5)<<S1[i]<<" ";

    out<<endl;

    for(int i=0; i<x; i++)
        out<<right<<setw(5)<<S2[i]<<" ";

    out<<endl;

    out<<right<<setw(5)<<did<<endl;

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    int A[100], B[100]; //pradiniai duomenys;
    int C[100], S1[100], S2[100]; //atrinktos stoteles bei iliptu ir isliptu keleiviu sumos;
    int n, x, did;

    skaitymas(A, B, n);
    atrinkimas(A, B, C, n, x);
    keleiviai(A, B, C, S1, S2, n, x);
    daugiausia(C, S1, x, did);
    isvedimas(C, S1, S2, x, did);

    return 0;
}
