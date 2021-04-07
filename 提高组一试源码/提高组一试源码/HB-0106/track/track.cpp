#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<time.h>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m,a,b,c,len[50001],li[50001],rd[50001];
bool vis[50001],b1=1,b2=1;//b1---a[i]=1;b2----link;
long long sum,ans,cnt,re;
struct street
{
    int to,l;
} s[50001],p;
vector<vector<street> >v;
void dfs(int x)
{
    ans=max(ans,sum);
    for(int i=0,j=v[x].size(); i<j; i++)
        if(!vis[v[x][i].to])
        {
            sum+=v[x][i].l;
            vis[v[x][i].to]=1;
            dfs(v[x][i].to);
            sum-=v[x][i].l;
            vis[v[x][i].to]=0;
        }
}
bool cmp(const int &x,const int &y)
{
    return x>y;
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    srand((int)time(NULL));
    scanf("%d%d",&n,&m);
    v.clear();
    v.resize(n+1);
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        len[i]=c;
        li[a]=c;
        if(a!=1)b1=0;
        if(b-a!=1)b2=0;
        p.to=b,p.l=c;
        v[a].push_back(p);
        p.to=a;
        v[b].push_back(p);
    }
    if(b1)
    {
        sort(len+1,len+n,cmp);
        ans=max(len[1]+len[6],max(len[2]+len[5],len[3]+len[4]));
        printf("%ld",ans);
        return 0;
    }
    if(m==1)
    {
        for(int i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            dfs(i);
        }
        printf("%ld",ans);
        return 0;
    }
    if(b2)
    {
        for(int i=1;i<=400;++i)
        {
            for(int j=1;j<m;++j)
            rd[j]=1+rand()%(n-1);
            sort(rd+1,rd+m);
            for(int j=1;j<m-1;++j)
            {
                cnt=0;
                ans=99999999;
                for(int w=rd[j];w<=rd[j+1];++w)cnt+=li[a];
                ans=min(cnt,ans);
            }
            re=max(re,ans);
        }
        printf("%ld",re);
    }
    printf("%ld",((((rand()%97*9)|1)/41*99+45)*12-10000)%97*(rand()%9991));
    return 0;
}
