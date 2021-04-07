#include<cstdio>
#include<iostream>
#define maxn 100010
using namespace std;
struct Se_tree{
	int l,r;
	int _min;
	#define l(p) se[p].l
	#define r(p) se[p].r
	#define _min(p) se[p]._min
}se[maxn<<2];
int add[maxn<<2],a[maxn],n,sum;
void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l==r) {
		_min(p)=a[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	_min(p)=min(_min(p<<1),_min(p<<1|1));
}
inline void lazydown(int p,int l,int mid,int r)
{
	_min(p<<1)-=add[p],_min(p<<1|1)-=add[p];
	add[p<<1]+=add[p],add[p<<1|1]+=add[p];
	add[p]=0;
}
void update(int p,int l,int r,int val)
{
	if(l<=l(p)&&r>=r(p))
	{
		_min(p)-=val;
		add[p]+=val;
	}
	int mid=l(p)+r(p)>>1;
	if(add[p]) lazydown(p,l(p),mid,r(p));
	if(l<=mid) update(p<<1,l,r,val);
	if(r>mid) update(p<<1|1,l,r,val);
	_min(p)=min(_min(p<<1),_min(p<<1|1));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(a[i]==_min(1))
			{
				a[i]=0;
				//sum+=_min(1,j);
				//s//um+=_min(j+1,n);
			}
		}
	}
}
