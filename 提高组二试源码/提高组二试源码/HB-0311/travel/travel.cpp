#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=10010;
priority_queue <int ,vector <int>,greater <int > >q;
priority_queue <int ,vector <int>,greater <int > >q1;
int head[N],n,m,tt,t,ord[N],ord1[N],vis[N],dl[N],sta[N],st[N],l,r;
int co[N],b[N],temp;
struct pr {
	int next,to,usd;
}a[N*2];
struct edge {
	int l,r;
}e[N*2];
inline int read ()
{
	int s=0;
	char ch=getchar ();
	while (ch<'0'||ch>'9') ch=getchar ();
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar ();}
	return s;	
}

int find (int x)
{
	if (b[x]==x) return x;
	return b[x]=find (b[x]);
}

void add (int u,int v)
{
	tt++;
	a[tt].next=head[u];
	a[tt].to=v;
	head[u]=tt;
	st[u]=min (st[u],v);
}

void dfs2 (int x)
{
	int y,tempp=0;
	t++;
	ord[t]=x;
	vis[x]=1;
	for (int i=head[x];i;i=a[i].next) {
		if (!co[a[i].to]) {
			t--;
			vis[x]=0;
			return ;
		}
	}
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]&&co[y]) {
			dfs2 (y);
		}
	}
}

void dfs1 (int x)
{
	int y,z,tempp=0;
	t++;
	ord[t]=x;
	vis[x]=1;
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			q.push(y);
		}
	}
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			y=q.top();
			a[i].to=y;
			q.pop();
		}
	}
	if (!temp) {
		for (int i=head[x];i;i=a[i].next) {
			y=a[i].to;
			if (co[y]&&!vis[y]) tempp++;
		}
	}
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (co[y]&&!temp&&tempp>1) {
			dfs2 (y);
			temp=1;
		}
		if (!vis[y]) {
			dfs1 (y);
		}
	}
}

void dfs (int x)
{
	int y;
	t++;
	ord[t]=x;
	vis[x]=1;
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			q.push(y);
		}
	}
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			y=q.top();
			a[i].to=y;
			q.pop();
		}
	}
	
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			dfs (y);
		}
	}
}
int main ()
{
	int x,y,k,l1,l2;
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	n=read (),m=read ();
	for (int i=1;i<=m;i++) {
		x=read (),y=read ();
		add (x,y);add (y,x);
		e[i].l=x;e[i].r=y;
	}
	if (m==n-1) dfs (1);
	else {
		for (int i=1;i<=n;i++) b[i]=i;
		for (int i=1;i<=m;i++) {
			x=e[i].l;y=e[i].r;
			l1=find (x);l2=find (y);
			if (l1==l2) {
				for (int i=1;i<=n;i++) {
					if (find (i)==l1) co[i]=1;
				}
				break;
			}
			b[l2]=l1;
		}
		dfs1 (1);
	}
	for (int i=1;i<=n;i++)
		cout<<ord[i]<<" ";
}
/*
4 4
1 2
2 3
3 4
4 2
*/
