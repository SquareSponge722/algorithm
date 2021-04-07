#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long 
#define lson 2*p
#define rson 2*p+1
using namespace std;
const int N=1e5+110;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,data[N],minn=(1<<30),maxx;
ll ans;
vector<int>ve;
struct node
{
	int lt,rt,val,ma,mi,pos;
}a[N*4];
void pushup(int p)
{
	a[p].ma=max(a[lson].ma,a[rson].ma);
	a[p].mi=min(a[lson].mi,a[rson].mi);
	if(a[lson].mi<a[rson].mi)a[p].pos=a[lson].pos;
	else a[p].pos=a[rson].pos;
}
void build(int p,int l,int r)
{
	a[p].lt=l;a[p].rt=r;
	if(l==r){a[p].ma=a[p].mi=data[l];a[p].pos=l;return ;}
	int mid=(l+r)/2;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(p);
}
void pushdown(int p)
{
	if(a[p].val)
	{
		a[lson].val+=a[p].val;
		a[rson].val+=a[p].val;
		a[lson].ma+=a[p].val;a[lson].mi+=a[p].val;
		a[rson].ma+=a[p].val;a[rson].mi+=a[p].val;
		a[p].val=0;
	}
}
void add(int p,int l,int r,int d)
{
	if(a[p].lt==l&&a[p].rt==r){a[p].val+=d;a[p].ma+=d;a[p].mi+=d;return;}
	pushdown(p);
	int mid=(a[p].lt+a[p].rt)/2;
	if(r<=mid)add(lson,l,r,d);
	else if(l>mid)add(rson,l,r,d);
	else add(lson,l,mid,d),add(rson,mid+1,r,d);
	pushup(p);
}
int query_min(int p,int l,int r)
{
	if(a[p].lt==l&&a[p].rt==r)return a[p].mi;
	pushdown(p);
	int mid=(a[p].lt+a[p].rt)/2;
	if(r<=mid)return query_min(lson,l,r);
	else if(l>mid)return query_min(rson,l,r);
	else return min(query_min(lson,l,mid),query_min(rson,mid+1,r));
}
int query_max(int p,int l,int r)
{
	if(a[p].lt==l&&a[p].rt==r)return a[p].ma;
	pushdown(p);
	int mid=(a[p].lt+a[p].rt)/2;
	if(r<=mid)return query_max(lson,l,r);
	else if(l>mid)return query_max(rson,l,r);
	else return max(query_max(lson,l,mid),query_max(rson,mid+1,r));
}
int query_pos(int p,int l,int r)
{
	if(a[p].lt==l&&a[p].rt==r)return a[p].pos;
	pushdown(p);
	int mid=(a[p].lt+a[p].rt)/2;
	if(r<=mid)return query_pos(lson,l,r);
	else if(l>mid)return query_pos(rson,l,r);
	else 
	{
		if(query_min(lson,l,mid)<query_min(rson,mid+1,r))return query_pos(lson,l,mid);
		else return query_pos(rson,mid+1,r);
	}
}
void update(int l,int r)
{
	int tmp=query_min(1,l,r);
	if(l==r){ans+=tmp;return;}
	int pos=query_pos(1,l,r);
	if(pos==l||pos==r){ans+=query_max(1,l,r);return;}
	else 
	{
		add(1,l,r,-tmp);
		ans+=tmp;
		update(l,pos-1);
		update(pos+1,r);
		return;
	}
}
int sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		data[i]=read();
		minn=min(minn,data[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(data[i]==minn)ve.push_back(i),sum++;
	}
    
	build(1,1,n);
	if(sum==1)
      	update(1,n);
  	else 
  	{
  		int last=1;
  		for(int i=1;i<=n;i++)
  		data[i]-=minn;
  		ans+=minn;
	  for(int i=0;i<ve.size();i++)
	  {
		{	
		   update(last,ve[i]-1);
	     	last=ve[i]+1;
		}
	  
	  }
	  int tmp=ve.size()-1;
	  if(ve[tmp]!=n)update(ve[tmp]+1,n);
	}
	printf("%lld",ans);
  	return 0;	
}
