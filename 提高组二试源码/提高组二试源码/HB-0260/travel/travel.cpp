#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf=0x3f3f3f3f;
int head[20000],cnt,dis[20000];
bool vis[20000];
int save[20000];
int tmp[20000];
int n,m;
int nowmin=0x3f3f3f;
bool can[5000][5000];
struct node
{
    int u,v;
}a[200000];
string tmp1;
void add(int u,int v)
{
    a[++cnt].u=v;
    a[cnt].v=head[u];
    head[u]=cnt;
}
queue<int>q;
bool pd(string s1,string s2)
{
    if(s1>s2)return false;
    return true;
}
void bfs(int s)
{
    q.push(s);
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;

        cout<<u<<" ";

        for(int i=1;i<=n;i++)
        {
            if(can[u][i]&&!vis[i])
            {
                q.push(i);
                vis[i]=1;
            }
        }
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        can[a][b]=1;
        can[b][a]=1;
    }
    bfs(1);
    return 0;
}
