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

struct Slepynes
{
    string vardas;
    int skaicius[10];
    int suma;
    int nelyginiai;
    int sk;
};

void skaitymas(Slepynes A[], int & n)
{
    char eil[11];
    ifstream in(Cin);
    in>>n;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 11);
        A[i].vardas=eil;
        in>>A[i].sk;
        for(int j=0; j<A[i].sk; j++)
        {
            in>>A[i].skaicius[j];
        }
        in.ignore(100, '\n');
    }
    in.close();
}

void skaiciavimas(Slepynes A[], int n)
{
    for(int i=0; i<n; i++) //skaiciuojama kauliuku suma
    {
        int sum=0;
        int nelyginiai=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(A[i].skaicius[j]%2==0) // lyginiai skaiciai
            {
                sum=sum-A[i].skaicius[j];
            }

            if(A[i].skaicius[j]%2!=0) // nelyginiai skaiciai
            {
                sum=sum+A[i].skaicius[j];
                nelyginiai=nelyginiai+1;
            }
        }
        A[i].suma=sum;
        A[i].nelyginiai=nelyginiai;
    }
}

void atrinkimas(Slepynes A[], int n, int & max, string & ieskotojas)
{
    max=A[0].suma;
    ieskotojas=A[0].vardas;

    for(int i=1; i<n; i++) //isrenka valdova pagal didziausia suma
    {
        if(A[i].suma>max)
        {
            max=A[i].suma;
            ieskotojas=A[i].vardas;
        }
    }

    int maxnelyginis=A[0].nelyginiai;

    for(int i=1; i<n; i++) // jei suma pasikartoja, ieskotojas isrenkamas pagal lyginiu kauliuku didziausia skaiciu suma
    {
        if (A[i-1].suma==max)
        {
            if(A[i].nelyginiai>maxnelyginis)
            {
                max=A[i].suma;
                ieskotojas=A[i].vardas;
                maxnelyginis=A[i].nelyginiai;
            }
        }
    }
}

void isvedimas(string ieskotojas, int max)
{
    ofstream out(Cout);
    out<<ieskotojas<<" "<<max<<endl;
    out.close();
}

int main()
{
    Slepynes A[50];
    int n, max;
    string ieskotojas;

    skaitymas(A, n);
    skaiciavimas(A, n);
    atrinkimas(A, n, max, ieskotojas);
    isvedimas(ieskotojas, max);

    return 0;
}
