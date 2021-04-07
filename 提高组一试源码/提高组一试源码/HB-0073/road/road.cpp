#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(register int i=a;i<=b;++i)
#define For(i,a,b) for(register int i=a;i>=b;--i)
ifstream fin;
ofstream fout;
typedef long long ll;
const int MX=100010;
const int inf=99999999;
ll a[MX],t,x,n;
int main()
{
    fin.open("road.in");
    fout.open("road.out");
    fin>>n;FOR(i,1,n) fin>>a[i];
    FOR(i,1,n)
    {
        if(a[i]<=x) x=a[i];
        else
        {
            t+=a[i]-x;
            x=a[i];
        }
    }
    fout<<t;
    fin.close();
    fout.close();
    return 0;
}
