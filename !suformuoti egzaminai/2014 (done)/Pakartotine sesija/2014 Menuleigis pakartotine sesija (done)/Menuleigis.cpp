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

struct Menuleigis
{
    int sk;
    int komanda[300]; //ar gerai aprasiau?
    int stabdymas[300]; // ivykdytu komandu skaicius
    int kiekis; //komandu skaicius
    int koordinatex; //paskutinio langelio koordinate x
    int koordinatey; //paskutinio langelio koordinate y
    string priezastis; //stabdymo priezastis
};

void skaitymas(Menuleigis A[], int & x0, int & y0, int & n)
{
    ifstream in(Cin);
    in>>x0>>y0;
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>A[i].sk;
        for(int j=0; j<A[i].sk; j++)
        {
            in>>A[i].komanda[j];
        }
    }
    in.close();
}

void skaiciavimas(Menuleigis A[], int x0, int y0, int n)
{
    int kopijax=x0;
    int kopijay=y0;

    for(int i=0; i<n; i++)
    {
        int x=0;

        for(int j=0; j<A[i].sk; j++)
        {
            if(A[i].komanda[j]==1)
            {
                y0++;
                x0++;
            }

            else if(A[i].komanda[j]==2)
            {
                x0++;
                y0--;
            }
            else if(A[i].komanda[j]==3)
            {
                y0--;
                x0--;
            }

            else if(A[i].komanda[j]==4)
            {
                x0--;
                y0++;
            }
            A[i].stabdymas[j]=A[i].komanda[j];
            x++;

            if(x0==kopijax && y0==kopijay)
                j=A[i].sk;
        }

        A[i].kiekis=x;

        if(x0==kopijax && y0==kopijay)
        {
            A[i].priezastis="pasiektas tikslas";
            A[i].koordinatex=kopijax;
            A[i].koordinatey=kopijay;
        }

        else
        {
            A[i].priezastis="sekos pabaiga";
            A[i].koordinatex=x0;
            A[i].koordinatey=y0;
        }

        x0=kopijax;
        y0=kopijay;
    }
}

void isvedimas(Menuleigis A[], int x0, int y0, int n)
{
    ofstream out(Cout);

    for(int i=0; i<n; i++)
    {
        out<<left<<setw(20)<<A[i].priezastis<<" ";

        for(int j=0; j<A[i].kiekis; j++)
        {
            out<<A[i].stabdymas[j]<<" ";
        }

        if(A[i].priezastis=="sekos pabaiga")
            out<<A[i].kiekis<<" "<<A[i].koordinatex<<" "<<A[i].koordinatey<<endl;

        if(A[i].priezastis=="pasiektas tikslas")
            out<<A[i].kiekis<<" "<<endl;
    }

    out.close();
}

int main()
{
    setlocale (LC_ALL, "Litxuanian");

    Menuleigis A[300];
    int x0, y0;
    int n;

    skaitymas(A, x0, y0, n);
    skaiciavimas(A, x0, y0, n);
    isvedimas(A, x0, y0, n);

    return 0;
}
