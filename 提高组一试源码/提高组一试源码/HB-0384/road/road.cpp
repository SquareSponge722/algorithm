#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mlr ll mid((l+r)>>1)
using namespace std;
ll a[100010];
ll ans1[400040];
ll ans2[400040];
ll tag[400040];
ll data[400040];
map<ll,ll> mp;
ll n;
ll opt(0);
ll tot(1);
ll k;
struct node
{
	int x,y;
	node(){}
	node(int x,int y):x(x),y(y){}
};
bool operator <(node xi,node yi)
{
	return xi.x<yi.x;
}
ll ls(ll x)
{
	return x<<1;
}
ll rs(ll x)
{
	return x<<1|1;
}
void push_up(ll p)
{
	ans1[p]=min(ans1[ls(p)],ans1[rs(p)]);
	ans2[p]=max(ans2[ls(p)],ans2[rs(p)]);
}
void build(ll p,ll l,ll r)
{
	tag[p]=0;
	if(l==r){ans1[p]=a[l];ans2[p]=a[l];data[l]=p;return;}
	mlr;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void f(ll p,ll l,ll r,ll k)
{
	tag[p]+=k;
	ans1[p]+=k;
	ans2[p]+=k;
}
void push_down(ll p,ll l,ll r)
{
	mlr;
	f(ls(p),l,mid,tag[p]);
	f(rs(p),mid+1,r,tag[p]);
	tag[p]=0;
}
ll query1(ll nl,ll nr,ll l,ll r,ll p)
{
	if(nl>nr)return 0;
	ll res(INF);
	if(nl<=l&&nr>=r)return ans1[p];
	mlr;
	push_down(p,l,r);
	if(nl<=mid)res=min(res,query1(nl,nr,l,mid,ls(p)));
	if(nr>mid)res=min(res,query1(nl,nr,mid+1,r,rs(p)));
	return res;
}
ll query2(ll nl,ll nr,ll l,ll r,ll p)
{
	if(nl>nr)return 0;
	ll res(-1);
	if(nl<=l&&nr>=r)return ans2[p];
	mlr;
	push_down(p,l,r);
	if(nl<=mid)res=max(res,query2(nl,nr,l,mid,ls(p)));
	if(nr>mid)res=max(res,query2(nl,nr,mid+1,r,rs(p)));
	return res;
}
void update(ll nl,ll nr,ll l,ll r,ll p,ll k)
{
	if(nl<=l&&nr>=r){f(p,l,r,k);return;}
	mlr;
	push_down(p,l,r);
	if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
	if(nr>mid)update(nl,nr,mid+1,r,rs(p),k);
	push_up(p);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	priority_queue<node> q;
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	k=query1(1,n,1,n,1);
	opt+=k;
	update(1,n,1,n,1,-k);
	for(ll i=1;i<=n;i++)if(!(ans1[data[i]]-k)){ans1[data[i]]=INF;q.push(node(i-1,i+1));push_up(data[i]);}
	while(query2(1,n,1,n,1))
	{
		node now=q.top();
		q.pop();
		while(!q.empty())
		{	
			while(q.top().y==now.x+1)
			{
				now.x=q.top().x;
				q.pop();
			}
			tot++;
		}
		ll k=query1(1,n,1,n,1);
		opt+=k*tot;
		for(ll i=1;i<=n;i++)if(!(ans1[data[i]]-k)){ans1[data[i]]=INF;q.push(node(i-1,i+1));push_up(data[i]);}
	}
	printf("%lld",opt);
	return 0;
}
