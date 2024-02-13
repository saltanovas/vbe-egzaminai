#include <fstream>
#include <iostream>
using namespace std;

const char Cin[]="U1.txt";
const char Cout[]="U1rez.txt";

void skaitymas(int VM[], int KD[], int D[], int & n)
{
    ifstream in(Cin);
    in>>n;
    for(int i=0; i<n; i++)
        in>>VM[i]>>KD[i]>>D[i];

    in.close();
}

void poros(int VM[], int KD[], int D[], int L[], int n, int & mot, int & vyr)
{
    mot=0;
    vyr=0;

    for(int i=0; i<n; i++) //padaro vyriskos ir moteriskos pirstines kopija
        L[i]=VM[i];

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(VM[i]==VM[j] && KD[i]!=KD[j] && D[i]==D[j])
            {
                if(VM[i]==4 && VM[j]==4)
                {
                    mot=mot+1;

                    for(int x=j; x<n; x++)
                    {
                        VM[x]=VM[x+1];
                        KD[x]=KD[x+1];
                        D[x]=D[x+1];
                    }
                    n--;
                }

                if(VM[i]==3 && VM[j]==3)
                {
                    vyr=vyr+1;

                    for(int y=j; y<n; y++)
                    {
                        VM[y]=VM[y+1];
                        KD[y]=KD[y+1];
                        D[y]=D[y+1];
                    }
                    n--;
                }
                break;
            }
        }
    }
}

void likutis(int L[], int n, int mot, int vyr, int & likom, int & likov)
{
    int msum=0;
    int vsum=0;

    for(int i=0; i<n; i++)
    {
        if(L[i]==4) msum++;
        if(L[i]==3) vsum++;
    }

    likom=msum-mot*2;
    likov=vsum-vyr*2;
}

void isvedimas(int mot, int vyr, int likom, int likov)
{
    ofstream out(Cout);

    out<<mot<<endl;
    out<<vyr<<endl;
    out<<likom<<endl;
    out<<likov;

    out.close();
}

int main()
{
    int VM[100], KD[100], D[100];
    int L[100]; //vyriskos ir moteriskos pirstines kopija
    int n;
    int mot, vyr, likom, likov;

    skaitymas(VM, KD, D, n);
    poros(VM, KD, D, L, n, mot, vyr);
    likutis(L, n, mot, vyr, likom, likov);
    isvedimas(mot, vyr, likom, likov);

    return 0;
}
