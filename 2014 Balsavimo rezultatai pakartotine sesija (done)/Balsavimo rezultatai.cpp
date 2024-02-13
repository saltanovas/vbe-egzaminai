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

void skaitymas(int A[], int B[], int C[], int & n, int & d)
{
    ifstream in(Cin);

    in>>n;

    for(int i=0; i<n; i++)
        in>>A[i]>>B[i]>>C[i];

    in>>d;

    in.close();
}

void kartai(int A[], int B[], int C[], int n, int d, int & t1, int & t2, int & t3)
{
    t1=0;
    t2=0;
    t3=0;

    for(int i=0; i<n; i++)
    {
        if(A[i]<B[i] && A[i]<C[i]) t1=t1+1;
        if(B[i]<A[i] && B[i]<C[i]) t2=t2+1;
        if(C[i]<A[i] && C[i]<B[i]) t3=t3+1;

        if(A[i]==B[i] && C[i]>A[i] && C[i]>B[i])
        {
            if(d==1) t1=t1+1;
            if(d==2) t2=t2+1;
            if(d==3) t3=t3+1;
        }

        if(A[i]==C[i] && A[i]<B[i] && C[i]<B[i])
        {
            if(d==1) t1=t1+1;
            if(d==2) t2=t2+1;
            if(d==3) t3=t3+1;
        }

        if(B[i]==C[i] && B[i]<A[i] && C[i]<A[i])
        {
            if(d==1) t1=t1+1;
            if(d==2) t2=t2+1;
            if(d==3) t3=t3+1;
        }

        if(A[i]==B[i] && A[i]==C[i])
        {
            if(d==1) t1=t1+1;
            if(d==2) t2=t2+1;
            if(d==3) t3=t3+1;
        }
    }
}

void blogiausias(int t1, int t2, int t3, int & min)
{
    min=0;

    if(t1>t2 && t1>t3) min=1;
    if(t2>t1 && t2>t3) min=2;
    if(t3>t1 && t3>t2) min=3;
}

void isvedimas(int t1, int t2, int t3, int min)
{
    ofstream out(Cout);

    out<<t1<<" "<<t2<<" "<<t3<<endl;
    out<<min;

    out.close();
}

int main()
{
    int A[10], B[10], C[10];
    int n, d, t1, t2, t3, min;

    skaitymas(A, B, C, n, d);
    kartai(A, B, C, n, d, t1, t2, t3);
    blogiausias(t1, t2, t3, min);
    isvedimas(t1, t2, t3, min);

    return 0;
}
