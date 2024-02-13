#include <fstream>
#include <iostream>
using namespace std;

const char Cin[]="U1.txt";
const char Cout[]="U1rez.txt";

void skaitymas(int A[], int B[], int C[], int & n, int & a, int & b, int & c)
{
    ifstream in(Cin);

    in>>n;

    for(int i=0; i<n; i++)
        in>>A[i]>>B[i]>>C[i];

    in>>a>>b>>c;

    in.close();
}

void balsai(int A[], int B[], int C[], int n, int & sum1, int & sum2, int & sum3)
{
    sum1=0;
    sum2=0;
    sum3=0;

    for(int i=0; i<n; i++)
    {
        sum1=sum1+A[i];
        sum2=sum2+B[i];
        sum3=sum3+C[i];
    }
}

void taskai(int A[], int B[], int C[], int n, int a, int b, int c, int & t1, int & t2, int & t3)
{
    t1=0;
    t2=0;
    t3=0;
    for(int i=0; i<n; i++)
    {
        if(A[i]>B[i] && A[i]>C[i]) t1=t1+4;
        if(B[i]>A[i] && B[i]>C[i]) t2=t2+4;
        if(C[i]>A[i] && C[i]>B[i]) t3=t3+4;

        if(A[i]==B[i] && A[i]>C[i])
        {
            t1=t1+2;
            t2=t2+2;
        }
        if(A[i]==C[i] && A[i]>B[i])
        {
            t1=t1+2;
            t3=t3+2;
        }
        if(B[i]==C[i] && B[i]>A[i])
        {
            t2=t2+2;
            t3=t3+2;
        }

        if( t1==t2 && t1==t3 || t2==t1 && t2==t3 )
        {
            t1=t1+a;
            t2=t2+b;
            t3=t3+c;
        }
    }
}

void isvedimas(int sum1, int sum2, int sum3, int t1, int t2, int t3)
{
    ofstream out(Cout);

    out<<sum1<<" "<<sum2<<" "<<sum3<<endl;
    out<<t1<<" "<<t2<<" "<<t3<<endl;

    if(t1>t2 && t1>t3 ) out<<"1"<<endl;
    else if(t2>t1 && t2>t3) out<<"2"<<endl;
    else out<<"3"<<endl;

    out.close();
}

int main()
{
    int A[100], B[100], C[100];
    int n, a, b, c, sum1, sum2, sum3, t1, t2, t3;

    skaitymas(A, B, C, n, a, b, c);
    balsai(A, B, C, n, sum1, sum2, sum3);
    taskai(A, B, C, n, a, b, c, t1, t2, t3);
    isvedimas(sum1, sum2, sum3, t1, t2, t3);

    return 0;
}
