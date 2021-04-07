#include <bits/stdc++.h>
using namespace std;
int read()
{
	int sum=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch<='9'&&ch>='0'){sum=sum*10+ch-'0';ch=getchar();}
	return sum;
}
const int N = 1e5+10;
struct node
{
	int l,r,mi,pos;
}a[N*4];
int data[N],n;
void pushup(int p)
{
	if(a[p*2].mi<a[p*2+1].mi){a[p].mi=a[p*2].mi;a[p].pos=a[p*2].pos;}
	else a[p].mi=a[p*2+1].mi,a[p].pos=a[p*2+1].pos;
}
void build(int p,int l,int r)
{
	a[p].l=l,a[p].r=r;
	if(l==r){a[p].mi=data[l],a[p].pos=l;return;}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
int query(int p,int l,int r)
{
	if(a[p].l==l&&a[p].r==r){return a[p].pos;}
	int mid=(a[p].l+a[p].r)/2;
	if(r<=mid)return query(p*2,l,r);
	else if(l>mid)return query(p*2+1,l,r);
	else {
			int d=query(p*2,l,mid),dd=query(p*2+1,mid+1,r);
			if(data[d]<data[dd])return d;
			else return dd; 
	}
}
int ans=0;
void fenzhi(int l,int r,int hig)
{
	if(l<1||l>n||r>n||r<1||l>r)return;
	int now=query(1,l,r);
	ans+=data[now]-hig;
	fenzhi(l,now-1,data[now]);
	fenzhi(now+1,r,data[now]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)data[i]=read();
	build(1,1,n);
	fenzhi(1,n,0);
	printf("%d\n",ans);
	return 0;
}
