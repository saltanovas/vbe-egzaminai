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


void skaitymas(int GN, int GM, int EN, int EM, int & g, int & e)
{
    ifstream in(Cin);

    in>>g;

    for(int i=0; i<g; i++)
        in>>GN[i];

    for(int i=0; i<g; i++)
        in>>GM[i];

    in>>e;

    for(int i=0; i<e; i++)
        in>>EN[i];

    for(int i=0; i<e; i++)
        in>>EM[i];

    in.close;
}

int pinigai(int EM[], int GM, int & n)
{
    int sum=0;

    for(int i=0; i<n; i++)
    sum=sum+EM[i]+GM[i];

    return sum;
}

int keitimas(int N[], int K[], int n)
{
    for(int i=0; i<n; i++)
    {
        K[i]=sum/N[i];
        sum=sum%N[i];
    }

}

int suma(int K[], int n)
{
    int k=0;
    for(int i=0; i<n; i++)
        k=k+K[i]
    return k;
}

void isvedimas(int N[], int K[], int n)
{
    ofstream out(Cout, ios::app);
    out(int i=0; i<n; i++)
    out<<N[i]<<" "<<K[i]<<endl;
    out<<suma(K, n)<<endl;
    out.close();
}

int main()
{
setlocale (LC_ALL, "Lithuanian");

int GN[100], GM[100], EN[100, EM[100], GK[100, EK[100];
int g, e;
int gs, es;

ofstream out(Cout); out.close();
skaitymas(GN, GM, EN, EM, g, e);
pinigai(EM, GM, n);
keitimas(N, K, n);
suma(K, n);
isvedimas(N, K, n);

  return 0;
}
