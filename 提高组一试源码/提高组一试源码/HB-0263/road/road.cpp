#include<cstdio>
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((l+r)>>1)
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
    int l,r,v;//v存位置
    node(int l,int r)
    {
        this->l=l;
        this->r=r;
    }
    node(){}
}t[400100];
//维护区间最小值
int a[100100];
void build(int k,int l,int r)
{
    t[k]=node(l,r);
    if(l==r)
    {
        t[k].v=l;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[k].v=a[t[ls].v]<a[t[rs].v]?t[ls].v:t[rs].v;
}
int ask(int k,int l,int r)//return一个位置即可
{
    if(r<t[k].l||l>t[k].r)
        return 0;
    if(l<=t[k].l&&r>=t[k].r)
        return t[k].v;
    int L=ask(ls,l,r),R=ask(rs,l,r);
    return a[L]<a[R]?L:R;
}
int sum=0;
void div(int p,int l,int r)//p是原始深度
{
    if(l>r)
        return;
    int ans=ask(1,l,r);
    sum+=a[ans]-p;
    div(a[ans],l,ans-1);
    div(a[ans],ans+1,r);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    a[0]=0x7fffffff;
    int n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    div(0,1,n);
    printf("%d\n",sum);
    return 0;
}

