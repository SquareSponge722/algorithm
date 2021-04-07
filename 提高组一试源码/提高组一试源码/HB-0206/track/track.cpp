#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=50005;
int n,m,maxl=0,st=1,sum=0;
bool vis[maxn];
struct node
{
    vector<int> v,w;
} s[maxn];
inline int read()
{
    int x=0,f=1;
    char ch;
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
        if(ch=='-')f=-1;
    }
    while(ch>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
void dfs(int cur,int len)
{
    bool flag=0;
    for(int i=0; i<s[cur].v.size(); i++)
    {
        if(!vis[s[cur].v[i]])
        {
            flag=1;
            vis[s[cur].v[i]]=1;
            dfs(s[cur].v[i],len+s[cur].w[i]);
            vis[s[cur].v[i]]=0;
        }
    }
    if(!flag)
    {
        if(len>maxl)
        {
            maxl=len;
            st=cur;
        }
    }
}
void dfs2(int cur,int len)
{
    bool flag=0;
    for(int i=0; i<s[cur].v.size(); i++)
    {
        if(!vis[s[cur].v[i]])
        {
            flag=1;
            vis[s[cur].v[i]]=1;
            dfs(s[cur].v[i],len+s[cur].w[i]);
            vis[s[cur].v[i]]=0;
        }
    }
    if(!flag&&len>maxl)maxl=len;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read();
    int a,b,l;
    memset(vis,0,sizeof vis);
    for(int i=1; i<n; i++)
    {
        a=read(),b=read(),l=read();
        sum+=l;
        s[a].v.push_back(b);
        s[a].w.push_back(l);
        s[b].v.push_back(a);
        s[b].w.push_back(l);
    }
    if(m==1)
    {
        vis[1]=1;
        dfs(1,0);
        vis[1]=0;
        vis[st]=1;
        maxl=0;
        dfs2(st,0);
        cout<<maxl<<endl;
    }
    else
    {
        cout<<sum/m-1<<endl;
    }
    return 0;
}
