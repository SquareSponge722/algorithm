#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using std::sort;
using std::vector;
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
struct node
{
    int key,id,sz,rdm;
    node *ls,*rs;
    node(int key,int id)
    {
        this->key=key;
        this->id=id;
        sz=1;
        rdm=rand();
        ls=NULL;
        rs=NULL;
    }
    node(){}
    void maintain()
    {
        sz=(ls?ls->sz:0)+1+(rs?rs->sz:0);
    }
}Node[200100],*root;
int ncnt=-1;
node *Newnode(int x,int y)
{
    Node[++ncnt]=node(x,y);
    return &Node[ncnt];
}
node *Merge(node *a,node *b)
{
    if(!a||!b)
        return a?a:b;
    if(a->rdm<b->rdm)
    {
        a->rs=Merge(a->rs,b);
        a->maintain();
        return a;
    }
    b->ls=Merge(a,b->ls);
    b->maintain();
    return b;
}
void split(node *rt,int x,node *&a,node *&b)
{
    if(!rt)
    {
        a=NULL;
        b=NULL;
        return;
    }
    if(rt->key<=x)
    {
        a=rt;
        split(a->rs,x,a->rs,b);
    }
    else
    {
        b=rt;
        split(b->ls,x,a,b->ls);
    }
    rt->maintain();
    return;
}
void Insert(int x,int y)
{
    node *a,*b;
    split(root,x,a,b);
    root=Merge(Merge(a,Newnode(x,y)),b);
}
int Delete(int x)//·µ»ØÒ»¸öid
{
    node *a,*b,*c;
    split(root,x-1,a,b);
    split(b,x,b,c);
    int ans=b->id;
    b=Merge(b->ls,b->rs);
    root=Merge(Merge(a,b),c);
    return ans;
}
int kth(node *rt,int x)
{
    int ls=rt->ls?rt->ls->sz:0;
    if(x<=ls)
        return kth(rt->ls,x);
    if(ls+1==x)
        return rt->key;
    return kth(rt->rs,x-1-ls);
}
struct edge
{
    int n,nxt,v;
    edge(int n,int nxt,int v)
    {
        this->n=n;
        this->nxt=nxt;
        this->v=v;
    }
    edge(){}
}e[100100];
int head[50010],ecnt=-1;
void add(int from,int to,int v)
{
    e[++ecnt]=edge(to,head[from],v);
    head[from]=ecnt;
    e[++ecnt]=edge(from,head[to],v);
    head[to]=ecnt;
}
int f[50010],g[50010];
bool used[50010];
void dfs(int x,int from,int p)
{
    vector<int> h;
    for(int i=head[x];~i;i=e[i].nxt)
        if(e[i].n!=from)
        {
            dfs(e[i].n,x,p);
            g[e[i].n]+=e[i].v;
            if(g[e[i].n]>=p)
                ++f[x];
            else
                h.push_back(g[e[i].n]);
            f[x]+=f[e[i].n];
        }
    sort(h.begin(),h.end());
    int tt=h.size();
    root=NULL;
    ncnt=-1;
    for(int i=0;i<tt;++i)
    {
        Insert(h[i],i);
        used[i]=0;
    }
    for(int i=0;i<tt;++i)
        if(!used[i])
        {
            Delete(h[i]);
            node *a,*b;
            split(root,p-h[i]-1,a,b);
            if(b)
            {
                int tmp=kth(b,1);
                root=Merge(a,b);
                tmp=Delete(tmp);
                used[tmp]=1;
                used[i]=1;
                ++f[x];
            }
            else
                root=Merge(a,b);
        }
    for(int i=0;i<tt;++i)
        if(!used[i])
            g[x]=h[i];
    return;
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    memset(head,-1,sizeof(head));
    int n=read();
    int m=read();
    int u,v,w;
    for(int i=1;i<n;++i)
    {
        u=read();
        v=read();
        w=read();
        add(u,v,w);
    }
    int l=1,r=500000100,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        dfs(1,1,mid);
        if(f[1]>=m)
            l=mid+1;
        else
            r=mid;
    }
    printf("%d\n",l-1);
    return 0;
}

