#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=50010;
const int INF=0x7fffffff;
int tt,n,m,nmin=INF,nmax,t1,t2,sum,head[N],vis[N],fa[N];
int de[N],dep[N],num[N],st[N],sta[N],id[N];
struct pr {
	int next,to,data,usd;
}a[N*2];
struct edge {
	int l,r,w,id;
}e[N*2];

bool cmp (edge x,edge y) {return x.w<y.w;}

void add (int u,int v,int w)
{
	tt++;
	a[tt].next=head[u];
	a[tt].to=v;
	a[tt].data=w;
	head[u]=tt;
	st[u]++;
}

inline int read ()
{
	int s=0;
	char ch=getchar ();
	while (ch<'0'||ch>'9') ch=getchar ();
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar ();}
	return s;
}

void dfs (int x)
{
	int y,z;
	vis[x]=1;
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;z=a[i].data;
		if (!vis[y]) {
			fa[y]=x;
			id[y]=i;
			de[y]=de[x]+1;
			dep[y]=dep[x]+z;
			if (dep[y]>nmax) nmax=dep[y],t1=y;
			dfs (y);
		}
	}
}

void work3 ()
{
	int s,t=0,l1,l2,y,nm,u;
	dfs (1);
	sort (e+1,e+n,cmp);
	t=n-m-1;
	cout<<e[t+1].w;
}
//---------------------------------------------------------------------
void work1 ()
{
	dfs (1);
	for (int i=1;i<=n;i++) vis[i]=0;
	dep[t1]=0;nmax=0;
	dfs (t1);
	cout<<dep[t1];
}
//---------------------------------------------------------------------
void dfss (int x,int s)
{
	int y;
	vis[x]=1;
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			fa[y]=x;
			num[s]=a[i].data;
			dfss (y,s+1);
		}
	}
}

bool checkk (int k)
{
	int l=1,s=0,sum=0;
	while (l<=n) {
		while (sum<k&&l<=n-1) sum+=num[l],l++;
		if (l<=n-1&&sum>=k) s++,sum=0;
		else break;
	}
	if (s>=m) return 1;
	else return 0;
}

void work2 ()
{
	int x,y;
	for (int i=1;i<=n;i++)
		if (st[i]==1) {t1=i;break;}
	dfss (t1,1);
	int l=nmin,r=sum/m,mid;
	while (l<=r) {
		mid=(l+r)/2;
		if (checkk (mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<mid;
}
//---------------------------------------------------------------------
int main ()
{
	int x,y,z,temp=1;
	freopen ("track.in","r",stdin);
	freopen ("track.out","w",stdout);
	n=read ();m=read ();
	for (int i=1;i<=n-1;i++) {
		x=read (),y=read (),z=read ();
		e[i].l=x;e[i].r=y;e[i].w=z;
		add (x,y,z);add (y,x,z);
		nmin=min (nmin,z);sum+=z;
		if (abs (x-y)!=1) temp=0;
	}
	if (m==1) work1 ();
	else if (m==n-1) {cout<<nmin;return 0;}
	else if (temp==1) work2 ();
	else  work3 ();
}
/*
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/
