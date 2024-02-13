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

struct Kauliukai
{
    int skaicius[10];
    int suma;
    int lyginiai;
    string vardas;
};

void skaitymas(Kauliukai A[], int & n, int & k)
{
    char eil[11];
    ifstream in(Cin);
    in>>n>>k;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 11);
        A[i].vardas=eil;
        for(int j=0; j<k; j++)
        {
            in>>A[i].skaicius[j];
        }
        in.ignore(100, '\n');
    }
    in.close();
}

void skaiciavimas(Kauliukai A[], int n, int k)
{
    for(int i=0; i<n; i++) //skaiciuojama kauliuku suma
    {
        int sum=0;
        int lyginiai=0;

        for(int j=0; j<k; j++)
        {
            if(A[i].skaicius[j]%2==0) // lyginiai skaiciai
            {
                sum=sum+A[i].skaicius[j];
                lyginiai=lyginiai+1; // suskaiciuoja lyginiu kauliuku skaiciu suma
            }

            if(A[i].skaicius[j]%2!=0) // nelyginiai skaiciai
            {
                sum=sum-A[i].skaicius[j];
            }
        }
        A[i].suma=sum;
        A[i].lyginiai=lyginiai;
    }
}

void atrinkimas(Kauliukai A[], int n, int & max, string & valdovas)
{
    max=A[0].suma;
    valdovas=A[0].vardas;

    for(int i=1; i<n; i++) //isrenka valdova pagal didziausia suma
    {
        if(A[i].suma>max)
        {
            max=A[i].suma;
            valdovas=A[i].vardas;
        }
    }

    int maxlyginis=A[0].lyginiai;

    for(int i=1; i<n; i++) // jei suma pasikartoja, valdovas isrenkamas pagal lyginiu kauliuku didziausia skaiciu suma
    {
        if (A[i-1].suma==max)
        {
            if(A[i].lyginiai>maxlyginis)
            {
                max=A[i].suma;
                valdovas=A[i].vardas;
                maxlyginis=A[i].lyginiai;
            }
        }
    }
}

void isvedimas(string valdovas, int max)
{
    ofstream out(Cout);
    out<<valdovas<<" "<<max<<endl;
    out.close();
}

int main()
{
    Kauliukai A[50];
    int n, k, max;
    string valdovas;

    skaitymas(A, n, k);
    skaiciavimas(A, n, k);
    atrinkimas(A, n, max, valdovas);
    isvedimas(valdovas, max);

    return 0;
}
