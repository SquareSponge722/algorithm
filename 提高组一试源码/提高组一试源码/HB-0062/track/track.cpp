//track
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
using namespace std;
int n,m,cnt=0,ans=0,tot=0;
struct EDGE {int u,v,w,next;} a[100010];
int head[50010];
bool b[50010];

inline int read()
{
	int x=0,p=1; char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') p=0,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return p?x:-x;
}

void add(int x,int y,int z)
{
	a[++cnt].u=x; a[cnt].v=y; a[cnt].w=z;
	a[cnt].next=head[x]; head[x]=cnt;
}

int pd(int x)//有几条路可走 
{
	int t=0;
	for(int i=head[x];i;i=a[i].next)
		if(!b[a[i].v]) t++;
	return t;
}

void dfs(int st)
{
	if(!pd(st))
	{
		ans=max(tot,ans);
		return ;
	}
	b[st]=1;
	for(int i=head[st];i;i=a[i].next)
	{
		if(!b[a[i].v])
		{
			b[a[i].v]=1;
			tot+=a[i].w;
			dfs(a[i].v);
			tot-=a[i].w;
			b[a[i].v]=0;
		}
	}
}

void part_1()
{
	FOR(i,1,n)
	{
		memset(b,0,sizeof(b));
		tot=0;
		if(pd(i)==1) dfs(i);
	}
	cout<<ans;
}

bool cmp(EDGE x,EDGE y) { return x.w>y.w; }

void part_2()
{
	ans=0;
	sort(a+1,a+2*n-2+1,cmp);
	if(2*m>n-1)
	{
		FOR(i,1,2*n-2) if(i%2==1) ans+=a[i].w;
		cout<<ans;
		return ;
	}
	for(int i=1;i<=4*m;i+=2)
	{
		if(i%2==1) ans+=a[i].w;
	}
	cout<<ans;
	return ;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	FOR(i,1,n-1)
	{
		int x,y,z;
		x=read(); y=read(); z=read();
		add(x,y,z); add(y,x,z);
	}
//	FOR(i,1,n) cout<<i<<' '<<pd(i)<<endl;
	if(m==1) {part_1(); return 0;}
	else part_2();
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
