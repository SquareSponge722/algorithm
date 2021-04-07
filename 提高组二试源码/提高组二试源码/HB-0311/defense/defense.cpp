#include <iostream> 
#include <cstdio>
using namespace std;
string ss;
const int N=100010;
const int INF=0x3f3f3f;
int n,m,r1,r2,t1,t2,tt,head[N],w[N],f[N][2],f1[N][2],vis[N],son[N],sta[N],sta1[N],top1,top;
int ls[N],ls1[N],fa[N];
struct pr {
	int next,to;
}a[N*2];

inline int read ()
{
	int s=0;
	char ch=getchar ();
	while (ch<'0'||ch>'9') ch=getchar ();
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar ();}
	return s;	
}

void add (int u,int v)
{
	tt++;
	a[tt].next=head[u];
	a[tt].to=v;
	head[u]=tt;
}

void search (int x)
{
	int y;
	if (!son[x]) {f[x][0]=0;f[x][1]=w[x];return ;}
	f[x][1]=w[x];
	if (x==r1&&t1==1||x==r2&&t2==1) f[x][0]=INF;
	if (x==r1&&t1==0||x==r2&&t2==0) f[x][1]=INF;
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (fa[y]==x) {
			search (y);
			f[x][1]+=min (f[y][0],f[y][1]);
			f[x][0]+=f[y][1];
		}
	}
}

void dfs (int x)
{
	int y;
	vis[x]=1;
	for (int i=head[x];i;i=a[i].next) {
		y=a[i].to;
		if (!vis[y]) {
			son[x]=1;
			fa[y]=x;
			dfs (y);
		}
	}
}

int main ()
{
	int x,y,k,ans,ans1,ans2,k1,k2;
	freopen ("defense.in","r",stdin);
	freopen ("defense.out","w",stdout);
	cin>>n>>m>>ss;
	for (int i=1;i<=n;i++) w[i]=read ();
	for (int i=1;i<n;i++) {
		x=read (),y=read ();
		add (x,y),add (y,x);
	}
	dfs (1);
	search (1);
	for (int i=1;i<=m;i++) {
		x=read (),t1=read (),y=read (),t2=read ();
		r1=x,r2=y;
		top=top1=ans=0;
		ans1=0;ans2=0;
		for (int i=1;i<=n;i++) f1[i][0]=f[i][0],f1[i][1]=f[i][1];
		for (int i=1;i<=n;i++) f[i][0]=f[i][1]=0;
		search (1);
		ans=min (f[1][1],f[1][0]);
		if (ans>100000) cout<<-1<<endl;
		else cout<<ans<<endl;
		for (int i=1;i<=n;i++) f[i][0]=f1[i][0],f[i][1]=f1[i][1];
	}
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/

