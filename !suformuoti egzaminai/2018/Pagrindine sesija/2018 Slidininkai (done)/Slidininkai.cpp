#include <fstream>
#include <iostream>
using namespace std;

const char Cin[]="U2.txt";
const char Cout[]="U2rez.txt";

struct Slidininkai
{
    string vardas;
    int laikas;
    string fvardas;
    int flaikas;
    int rezultatas;
};

void skaitymas(Slidininkai A[], int & n, int & m)
{
    char eil[21];
    int val, min, sek;
    ifstream in(Cin);
    in>>n;
    in.ignore(100, '\n');
    for(int i=0; i<n; i++)
    {
        in.get(eil, 21);
        A[i].vardas=eil;
        in>>val>>min>>sek;
        A[i].laikas=(val*60*60)+(min*60)+sek;
        in.ignore(100, '\n');
    }

    in>>m;
    in.ignore(100, '\n');
    for(int i=0; i<m; i++)
    {
        in.get(eil, 21);
        A[i].fvardas=eil;
        in>>val>>min>>sek;
        A[i].flaikas=(val*60*60)+(min*60)+sek;
        in.ignore(100, '\n');
    }
    in.close();
}

void skaiciavimas(Slidininkai A[], int n, int m)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i].fvardas==A[j].vardas)
            {
                A[i].rezultatas=A[i].flaikas-A[j].laikas;
            }
        }
    }
}

void rikiavimas(Slidininkai A[], int m)
{
    Slidininkai laik;

    for(int i=0; i<m-1; i++)
        for(int j=i+1; j<m; j++)
            if(A[i].rezultatas>A[j].rezultatas)
            {
                laik=A[i];
                A[i]=A[j];
                A[j]=laik;
            }

    for(int i=0; i<m-1; i++)
        for(int j=i+1; j<m; j++)
            if(A[i].rezultatas==A[j].rezultatas)
            {
                if(A[i].fvardas>A[j].fvardas)
                {
                    laik=A[i];
                A[i]=A[j];
                A[j]=laik;
                }
            }
}

void isvedimas(Slidininkai A[], int m)
{
    ofstream out(Cout);
    for(int i=0; i<m; i++)
    {
        out<<A[i].fvardas<<" "<<A[i].rezultatas/60<<" "<<A[i].rezultatas%60<<endl;
    }
    out.close();
}

int main()
{

    Slidininkai A[30];
    int n, m;

    skaitymas(A, n, m);
    skaiciavimas(A, n, m);
    rikiavimas(A, m);
    isvedimas(A, m);

    return 0;
}
