#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(long long i=a;i<=b;++i)
#define For(i,a,b) for(long long i=a;i>=b;--i)
ifstream fin;
ofstream fout;
typedef long long ll;
const ll MX=50010;
const ll inf=99999999;
struct edge{ll u,v,w;}e[MX*2];
ll first[MX],next[MX*2];
ll ran[MX],ww[MX];
ll n,m,k;
ll cnt;
bool flag1=1,flag2=1;
bool cmp(ll x,ll y){return e[x].u<e[y].u;}
bool judge(ll mid)
{
    ll x=0,t;FOR(i,1,k)
    {
        t=0;
        while(x<m&&t<mid) t+=ww[++x];
        if(t<mid) return false;
    }
    return 1;
}
void work1()
{
    ///cerr<<cnt<<" "<<m<<endl;
    ll l=0,r=cnt/k,mid;
    FOR(i,1,m) ran[i]=i;
    sort(ran+1,ran+m+1,cmp);
    FOR(i,1,m) ww[i]=e[ran[i]].w;
    ///FOR(i,1,m) cerr<<ww[i]<<" ";cerr<<endl;
    while(l<r)
    {
        mid=(l+r+1)>>1;
        ///cerr<<l<<" "<<r<<" "<<mid<<endl;
        if(judge(mid)) l=mid;
        else r=mid-1;
    }
    fout<<l;
}
int main()
{
    fin.open("track.in");
    fout.open("track.out");
    fin>>n>>k;m=n-1;
    FOR(i,1,n-1)
    {
        fin>>e[i].u>>e[i].v>>e[i].w;
        ///if(e[i].u!=1) flag1=0;
        if(e[i].v!=e[i].u+1) flag2=0;
        cnt+=e[i].w;
    }///FOR(i,1,m) cerr<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
    if(flag2) work1();
    else fout<<cnt/k;
    fin.close();
    fout.close();
    return 0;
}
