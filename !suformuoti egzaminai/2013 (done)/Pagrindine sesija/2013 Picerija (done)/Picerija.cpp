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

void skaitymas(string A[], int B[], int C[], int & n, int & m)
{
    ifstream in(Cin);
    char eil[11];
    in>>n>>m;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 11);
        A[i]=eil;
        in>>B[i]>>C[i];
        in.ignore(100, '\n');
    }

    in.close();
}

int pirmynatgal(int x, int y)
{
    return fabs(x*2)+fabs(y*2);
}

void skaiciavimas(string A[], int B[], int C[], int n, int m, int & km, int & kiek, string & pav)
{
    km=0;
    kiek=0;

    for(int i=0; i<n; i++)
    {
        if(m>=km+pirmynatgal(B[i], C[i]))
        {
            kiek++;
            km=km+pirmynatgal(B[i], C[i]);
            pav=A[i];
        }

        else break;
    }
}

void isvedimas(int kiek, int km, string pav)
{
    ofstream out(Cout);
        out<<kiek<<" "<<km<<" "<<pav<<endl;
    out.close();
}

int main()
{
    string A[50];
    int B[100], C[100];
    int n, m;
    int kiek, km;
    string pav;

    skaitymas(A, B, C, n, m);
    skaiciavimas(A, B, C, n, m, km, kiek, pav);
    isvedimas(kiek, km, pav);

return 0;
}
