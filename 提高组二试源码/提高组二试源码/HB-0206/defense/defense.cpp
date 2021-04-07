#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100005;
int n,m,w[maxn],p[maxn],maxc;
double c[maxn];
string cfg;
vector<int> a[maxn];
void place(int st,int cost)
{
    int flag=1;
    for(int i=0; i<a[st].size(); i++)
    {
        if(p[i]!=1)p[i]=1,flag=0;
        place(a[st][i],cost+w[a[st][i]]);
    }
    if(flag&&cost<=maxc)maxc=cost;
}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>cfg;
    for(int i=1; i<=n; i++)
        cin>>w[i];
    int u,v;
    for(int i=1; i<n; i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ca,cb,pa,pb;
    for(int i=1; i<=m; i++)
    {
        memset(p,0,sizeof p);
        cin>>ca>>pa>>cb>>pb;
        if(pa)p[ca]=1;
        else p[ca]=-1;
        if(pb)p[cb]=1;
        else p[cb]=-1;
        maxc=0x7fffffff;
        for(int i=1; i<=n; i++)
            if(p[i]==0)place(i,w[i]);
        for(int i=1; i<=n; i++)
            if(!p[i])
            {
                cout<<-1;
                continue;
            }
        cout<<maxc<<endl;
    }
    return 0;
}
