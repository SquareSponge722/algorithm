#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100005
#define INF 100009
#define lowbit(x) x&(-x)
using namespace std;
typedef long long ll;

ll n,a[MAXN],bit[MAXN];
ll ans;

void add(int k,ll x)
{
	while(k <= n)
	{
		bit[k]+=x;
		k+=lowbit(k);
	}
	return;
}

ll get_sum(int k)
{
	ll sum=0;
	while(k)
	{
		sum+=bit[k];
		k-=lowbit(k);
	}
	return sum;
}

void change(ll x,int l,int r)
{
	add(l,x);
	add(r+1,-x);
	return;
}

ll read()
{
	ll r=0;
	char c=getchar();
	while(c < '0' || c > '9') c=getchar();
	while(c >= '0' && c <= '9') 
	{
		r=r*10+(c-'0');
		c=getchar();
	}
	return r;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		add(i,a[i]-a[i-1]);
	}
	bool ok=1;
	while(ok)
	{
		int l=1,r=0;
		ll tem=INF;
		ok=0;
		for(int i=1;i<=n+1;i++)
		{
			ll x;
			x=get_sum(i);
			if((!x || i == n+1))
			{
				if(tem!=INF)
				{
					ans+=tem;
					change(-tem,l,r);
					tem=INF;
					ok=1;
				}
				l=r=i;
				l++;
			}
			else if(x)
			{
				tem=min(tem,x); r++;
			}
			
		}
	}
	cout<<ans;
	return 0;
}

