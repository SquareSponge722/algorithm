#include<cstdio>//AFO
#include<cstring>
#define ll long long
#define inf 0x3ffffffffffff
ll Min(ll x,ll y)
{
    return x<y?x:y;
}
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
struct edge
{
    int n,nxt;
    edge(int n,int nxt)
    {
        this->n=n;
        this->nxt=nxt;
    }
    edge(){}
}e[10100];
int head[5050],ecnt=-1;
void add(int from,int to)
{
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
    e[++ecnt]=edge(from,head[to]);
    head[to]=ecnt;
}
char op[100];
ll a[100100];
ll f[2][100100];
int A,X,B,Y;
void dfs(int x,int from)
{
    f[0][x]=0;
    f[1][x]=a[x];
    for(int i=head[x];~i;i=e[i].nxt)
        if(e[i].n!=from)
        {
            dfs(e[i].n,x);
            f[0][x]+=f[1][e[i].n];
            f[1][x]+=Min(f[0][e[i].n],f[1][e[i].n]);
        }
    if(x==A)
        f[X^1][x]=inf;
    if(x==B)
        f[Y^1][x]=inf;
}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    memset(head,-1,sizeof(head));
    int n,m,u,v;
    n=read();
    m=read();
    scanf("%s",op);
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<n;++i)
    {
        u=read();
        v=read();
        add(u,v);
    }
    for(int i=1;i<=m;++i)
    {
        A=read();
        X=read();
        B=read();
        Y=read();
        dfs(1,1);
        ll ans=Min(f[0][1],f[1][1]);
        if(ans<inf)
            printf("%lld\n",ans);
        else
            puts("-1");
    }
    return 0;
}

