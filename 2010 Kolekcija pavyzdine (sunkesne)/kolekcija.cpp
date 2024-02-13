#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>

using namespace std;

const char Cin[]="U1duom.txt";
const char Cout[]="U1rez.txt";

void skaitymas(int L[], int J[], int & n, int & m)
{
    ifstream in(Cin);
    in>>n>>m;
    for(int i=0; i<n; i++)
        in>>L[i];
    for(int i=0; i<m; i++)
        in>>J[i];
    in.close();
}

void pasikartojantys(int A[], int S[], int n, int & z) // atreankmai pasikartojantys zaisliuku numeriai
{
    int B[500]; // masyvas, kuriame yra nepasikartojantys zaisliuku numeriai
    B[0]=A[0];
    int x=1;
    z=0;

    for(int i=1; i<n; i++)
    {
        int sum=0;

        for(int j=0; j<x; j++)
        {
            if(B[j]==A[i])
                sum=sum+1;
        }

        if(sum==0)
        {
            B[x]=A[i];
            x++;
        }

        if(sum>0)
        {
            S[z]=A[i];
            z++;
        }
    }
}

void bendra(int L[], int J[], int D[], int n, int m, int & d)
{
    int C[500]; // masyvas, kuriame laikomi Jurgio ir Linos zaisliuku numeriai
    int c=0;
    for(int i=0; i<n; i++)
    {
        C[c]=L[i];
        c++;
    }

    for(int i=0; i<m; i++)
    {
        C[c]=J[i];
        c++;
    }

    D[0]=C[0]; // atrenkami masyvo C nepasikartojantys elementai
    d=1;
    for(int i=1; i<c; i++)
    {
        int sum=0;

        for(int j=0; j<d; j++)
        {
            if(D[j]==C[i])
                sum=sum+1;
        }

        if(sum==0)
        {
            D[d]=C[i];
            d++;
        }
    }

    int laik;
    for(int i=0; i<d-1; i++)
        for(int j=i+1; j<d; j++)
        if(D[i]>D[j])
    {
        laik=D[i];
        D[i]=D[j];
        D[j]=laik;
    }
}

void isvedimas(int L[], int J[], int SL[], int SJ[], int D[], int n, int m, int x, int y, int d)
{
    ofstream out(Cout);

    int sk=0; // lygina Linos pasikartojanciu zaisliuku numerius su Jurgio zaisliuku numeriais
    for(int i=0; i<x; i++)
    {
        int sum=0;
        for(int j=0; j<m; j++)
        {
            if(SL[i]==J[j])
                sum++;
        }
        if(sum==0)
        {
            out<<SL[i]<<" ";
            sk++;
        }
        if(sk==0) out<<"0";
    }
    if(x==0) out<<"0";

    out<<endl;


        int sk1=0;
    for(int i=0; i<y; i++) // lygina Jurgio pasikartojanciu zaisliuku numerius su Linos zaisliuku numeriais
    {
        int sum=0;
        for(int j=0; j<m; j++)
        {
            if(SJ[i]==L[j])
                sum++;
        }
        if(sum==0)
        {
            out<<SJ[i]<<" ";
            sk1++;
        }
        if(sk1==0) out<<"0";
    }
    if(y==0) out<<"0";

    out<<endl;

    for(int i=0; i<d; i++)
        out<<D[i]<<" ";

    out.close();

}

int main()
{
    setlocale (LC_ALL, "Lithuanian");

    int L[500], J[500];
    int SL[500], SJ[500]; // pasikartojantys Linos ir Jurgio zaisliuku numeriu masyvai
    int D[500]; // Jurgio ir Linos bendros kolekcijos masyvas
    int n, m;
    int x, y, d;

    skaitymas(L, J, n, m);
    pasikartojantys(L, SL, n, x);
    pasikartojantys(J, SJ, m, y);
    bendra(L, J, D, n, m, d);
    isvedimas(L, J, SL, SJ, D, n, m, x, y, d);

    return 0;
}
