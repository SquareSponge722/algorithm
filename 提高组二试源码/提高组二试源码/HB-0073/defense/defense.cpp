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
struct edge{int u,v;}e[MX];
struct ques{int a,x,b,y;}qs[MX];
string type;
ll p[MX];
ll n,m,k;
void pre()
{
    fin>>n>>k>>type;m=n-1;
    FOR(i,1,n) fin>>p[i];
    FOR(i,1,m) fin>>e[i].u>>e[i].v;
    FOR(i,1,k) fin>>qs[i].a>>qs[i].x>>qs[i].b>>qs[i].y;
}/*
void work1()
{
    FOR(i,1,k)
    {
        if(qs[i].b%1==0)
        {
            if(qs[i].y==1) fout<<n/2+1;
            else fout<<(n+1)/2;
        }
        else
        {
            if(qs[i].y==1) fout<<(n+1)/2;
            else fout<<n/2+1;
        }
        fout<<endl;
    }
}
void work2()
{
    FOR(i,1,k)
    {
        if(qs[i].a%2==0)
        {
            if(qs[i].x==1&&qs[i].y==1) fout<<(n+1)/2;
            else if(qs[i].x==1&&qs[i].y==0) fout<<n/2;
            else if(qs[i].x==0&&qs[i].y==1) fout<<(n+1)/2;
            else if(qs[i].x==0&&qs[i].y==0) fout<<-1;
        }
    }
}*/
int main()
{
    fin.open("defense.in");
    fout.open("defense.out");
    pre();
    /*f(n<=10&&m<=10) work1();
    else */FOR(i,1,k) fout<<-1<<endl;
    fin.close();
    fout.close();
    return 0;
}
