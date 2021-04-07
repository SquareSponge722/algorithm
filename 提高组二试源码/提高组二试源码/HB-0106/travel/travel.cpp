#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,a,b,l,t;
int best[5001],past[5001],fir[5001];
bool bb[5001];
vector<vector<int> >v;
bool mini()
{
    for(int j=1; j<=n; ++j)if(past[j]>best[j])return 0;
    return 1;
}
void dfs(int x,int t)
{
    if(t>n)
    {
        if(mini())for(int i=1; i<=n; ++i)best[i]=past[i];
        return;
    }
    if(fir[x]!=x)dfs(fir[x],t);
    for(int i=0,j=v[x].size(); i<j; i++)
        if(!bb[v[x][i]])
        {
            bb[v[x][i]]=1;
            past[t]=v[x][i];
            fir[v[x][i]]=x;
            dfs(v[x][i],t+1);
            bb[v[x][i]]=0;
            fir[v[x][i]]=v[x][i];
        }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)best[i]=9999;
    v.clear();
    v.resize(n+1);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        t=v[a].size()-1;
        while(v[a][t-1]>v[a][t]&&t>0)
        {
            swap(v[a][t-1],v[a][t]);
            t--;
        }
        v[b].push_back(a);
        t=v[b].size()-1;
        while(v[b][t-1]>v[b][t]&&t>0)
        {
            swap(v[b][t-1],v[b][t]);
            t--;
        }
    }
    if(n<=10)
    {
        for(int i=1; i<=n; ++i)
        {
            past[1]=i;
            bb[i]=1;
            fir[i]=i;
            dfs(i,2);
            fir[i]=i;
            bb[i]=0;
        }
        for(int i=1; i<=n; ++i)printf("%d ",best[i]);
    }
    return 0;
}
