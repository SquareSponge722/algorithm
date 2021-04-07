//chf sj ycy -||- 
#include<bits/stdc++.h>

using namespace std;

#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rrep(i,x,y) for(register int i=x;i>=y;i--)

typedef long long ll;
typedef double db;

const int maxn=1e5;

int n,m,a,b,l;
int Maxx,id;
int A[maxn+10],B[maxn+10];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int tot;
int ver[maxn+10];
int edge[maxn+10];
int nxt[maxn+10];
int head[maxn+10];
int v[maxn+10];
int d[maxn+10];

void insert(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}

void dfs(int x)
{
	v[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i],z=edge[i];
		if(!v[y])
		{
			d[y]=d[x]+z;
			if(d[y]>Maxx){Maxx=d[y];id=y;}
			dfs(y);
		}
	}
}

void work()
{
	n=read();m=read();
	if(m==1)
	{
		rep(i,1,n-1)
		{
			a=read();b=read();l=read();
			insert(a,b,l);
			insert(b,a,l);
		}
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		Maxx=0,id=1;
		dfs(1);
		int iid=id;
		Maxx=0,id=1;
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		dfs(iid);
		printf("%d\n",Maxx);
	}
	else//ai=1
	{
		rep(i,1,n-1)
		{
			a=read();b=read();l=read();
			A[i]=l;
		}
		sort(A+1,A+n);
//		rep(i,1,n-1) printf("%d\n",A[i]);
//		printf("\n");
		int now=0;
		rrep(i,n-1,n-m) B[++now]=A[i]+A[n-(2*m)+(n-i)-1];
		sort(B+1,B+now+1);
//		rep(i,1,n-1) printf("%d\n",B[i]);
		printf("%d\n",B[1]);
	}
} 

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	work();
	return 0;
}
