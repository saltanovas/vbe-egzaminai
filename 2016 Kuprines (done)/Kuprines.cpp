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

int sunkiausia(int & max)
{
    int n, a;
    max=0;

    ifstream in(Cin);
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>a;
        if(a>max) max=a;
    }
    in.close();

    return max;
}

int kiekis(int max, int & k)
{
    int n, a;
    k=0;

    ifstream in(Cin);
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>a;
        if(a*2<=max) k++;
    }
    in.close();

    return k;
}

int isvedimas(int max, int k)
{
    ofstream out(Cout);

    out<<max<<" "<<k<<endl;

    out.close();
}

int main()
{
setlocale (LC_ALL, "Lithuanian");

int max, k;

sunkiausia(max);
kiekis(max, k);
isvedimas(max, k);

return 0;
}
