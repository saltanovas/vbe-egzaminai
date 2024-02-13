#include <fstream>
#include <iostream>
using namespace std;

const char Cin[]="U1.txt";
const char Cout[]="U1rez.txt";

void skaitymas(int A[], int B[], int & k, int & n)
{
    ifstream in(Cin);

    in>>k;
    for(int i=0; i<k; i++)
        in>>A[i];

    in>>n;
    for(int i=0; i<n; i++)
        in>>B[i];

    in.close();
}

void suma(int A[], int k, int & sum)
{
    sum=0;

    for(int i=0; i<k; i++)
        sum=sum+A[i];
}

void skaiciavimas(int A[], int B[], int n, int ES[], int sum, int & x, int & esum, int & liko)
{
    esum=0;
    x=0;

    for(int i=0; i<n; i++)
    {
        ES[x]=sum/B[i];
        x++;
        sum=sum%B[i];
    }

    for(int i=0; i<x; i++)
        esum=esum+ES[i];
}

void isvedimas(int B[], int ES[], int x, int sum, int esum, int liko)
{
    ofstream out(Cout);

    int likos=0;

    out<<sum<<endl;

    for(int i=0; i<x; i++)
        out<<B[i]<<" "<<ES[i]<<endl;

    out<<esum<<endl;

    for(int i=0; i<x; i++)
        likos=likos+B[i]*ES[i];

    liko=sum-likos;
    out<<liko<<endl;

    out.close();
}

int main()
{
    int A[100], B[100], ES[100];
    int k, n, x, sum, esum, liko;

    skaitymas(A, B, k, n);
    suma(A, k, sum);
    skaiciavimas(A, B, n, ES, sum, x, esum, liko);
    isvedimas(B, ES, x, sum, esum, liko);

    return 0;
}
