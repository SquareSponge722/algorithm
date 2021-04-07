#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn=5005;
int n,m,len=1,r[maxn],pre[maxn];
vector<int> a[maxn];
set<int> canvis;
bool vis[maxn];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
bool full()
{
    for(int i=1; i<=n; i++)
        if(!vis[i])return 0;
    return 1;
}
void debug(int g)
{
    cout<<g<<":"<<endl;
    for(set<int>::iterator i=canvis.begin(); i!=canvis.end(); i++)
        cout<<*(i)<<' ';
    cout<<endl;
}
void travel1(int z)
{
    for(int i=0; i<a[z].size(); i++)
        if(!vis[a[z][i]])canvis.insert(a[z][i]);
    //debug(z);
    if(!canvis.empty())
    {
        int nex=*(canvis.begin());
        canvis.erase(nex);
        r[++len]=nex;
        vis[nex]=1;
        travel1(nex);
    }
}
void travel2(int cur)
{
    canvis.clear();
    for(int i=0; i<a[cur].size(); i++)
        if(!vis[a[cur][i]])canvis.insert(a[cur][i]);
    //debug(cur);
    if(!canvis.empty())
    {
        int nex=*(canvis.begin());
        canvis.erase(nex);
        r[++len]=nex;
        vis[nex]=1;
        pre[nex]=cur;
        travel2(nex);
    }
    else if(!full())travel2(pre[cur]);
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(vis,0,sizeof(vis));
    memset(r,0,sizeof(r));
    memset(pre,0,sizeof(pre));
    n=read(),m=read();
    int u,v;
    for(int i=1; i<=m; i++)
    {
        u=read();
        v=read();
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(m==n)
    {
        r[len]=1;
        vis[1]=1;
        travel1(1);
    }
    else
    {
        r[len]=1;
        vis[1]=1;
        pre[1]=1;
        travel2(1);
    }
    for(int i=1; i<=n; i++)
        cout<<r[i]<<' ';
    cout<<endl;
    return 0;
}
