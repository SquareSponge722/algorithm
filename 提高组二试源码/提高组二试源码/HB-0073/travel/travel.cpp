#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
#define FOR(i,a,b) for(register int i=a;i<=b;++i)
#define For(i,a,b) for(register int i=a;i>=b;--i)
#define qxx(i,x) for(register int i=first[x];i;i=next[i])
ifstream fin;
ofstream fout;
typedef long long ll;
const int MX=10010;
const int inf=99999999;
struct edge{int u,v;}e[MX];
int first[MX],next[MX];
bool vis[MX],b[MX],flag,huan[MX];
int dq[MX],zy[MX],cc;
int n,m,xx,by1,by2;
bool cmp(edge x,edge y){return x.v>y.v;}
void pre()
{
    fin>>n>>m;
    FOR(i,1,m)
    {
        fin>>e[i].u>>e[i].v;
        e[i+m].u=e[i].v;
        e[i+m].v=e[i].u;
    }
    sort(e+1,e+2*m+1,cmp);
    FOR(i,1,2*m) next[i]=first[e[i].u],first[e[i].u]=i;
}
void dfs1(int x)
{
    fout<<x<<" ";vis[x]=1;
    qxx(i,x) if(!vis[e[i].v]) dfs1(e[i].v);
}
void work1(){dfs1(1);}
void zh(int x,int fa)
{
    b[x]=1;qxx(i,x)
    {
        if(b[e[i].v])
        {
            if(e[i].v==fa) continue;
            flag=1;xx=e[i].v;
            ///fout<<xx<<endl;
            huan[x]=huan[e[i].v]=1;return;
        }
        zh(e[i].v,x);
        if(flag)
        {
            huan[x]=1;
            if(x==xx) {flag=0;}
            return;
        }
    }
}
void dfs2(int x)
{
    dq[++cc]=x;vis[x]=1;
    qxx(i,x) if((!((x==by1&&e[i].v==by2)||(x==by2&&e[i].v==by1)))&&(!vis[e[i].v]))
        dfs2(e[i].v);
}
bool jg()
{
    FOR(i,1,n)
    {
        if(dq[i]<zy[i]) return 1;
        else if(dq[i]>zy[i]) return 0;
    }
    return 0;
}
void judge()
{
    if(jg())FOR(i,1,n) zy[i]=dq[i];
}
void work2()
{
    zh(1,0);FOR(i,1,n) zy[i]=inf;
    ///FOR(i,1,n) if(huan[i]) fout<<i<<" ";fout<<endl;
    FOR(i,1,2*m) if(huan[e[i].u]&&huan[e[i].v])
    {
        by1=e[i].u;by2=e[i].v;
        memset(vis,0,sizeof(vis));
        cc=0;dfs2(1);
        judge();/*
        if(e[i].u==2&&e[i].v==6)
        {
            qxx(j,3) cerr<<e[j].v<<" ";cerr<<endl;
            FOR(i,1,n) cerr<<dq[i]<<" ";cerr<<endl;
            FOR(i,1,n) cerr<<zy[i]<<" ";cerr<<endl;
        }*/
    }
    FOR(i,1,n) fout<<zy[i]<<" ";
}
int main()
{
    fin.open("travel.in");
    fout.open("travel.out");
    pre();
    if(m==n-1) work1();
    else work2();
    fin.close();
    fout.close();
    return 0;
}
