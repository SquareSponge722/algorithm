#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	
	int s=0,p=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') p=-1;ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*p;
}
int n,m;
struct edge
{
	int u,v,w;
	int next;
}a[100001];
int head[50001];
int cnt=0;
void add(int x,int y,int z)
{
	cnt++;
	a[cnt].u=x;
	a[cnt].v=y;
	a[cnt].w=z;
	a[cnt].next=head[x];
	head[x]=cnt;
}
long long mmax=0;
int b[100001];
int sa(int x)
{
	if (x%2==1) return x+1;
	else return x-1;
}
void dfs(int now,long long sum)
{
	mmax=max(mmax,sum);
	for (int i=head[now];i;i=a[i].next)
	{
		if (b[i]==0&&b[sa(i)]==0)
		{
		 b[i]=b[sa(i)]=1;	
		 int g=a[i].v;
		 sum+=a[i].w;
		 dfs(g,sum);
		 b[i]=b[sa(i)]=0;	
		 sum-=a[i].w;		 
	    }
	}
}
void pianfen1()
{
	mmax=0;
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		dfs(i,0);
	}
	cout<<mmax;
}

bool cmp(edge x,edge y)
{
	return x.w>y.w;
}

void pianfen2()
{
	sort(a+1,a+cnt+1,cmp);
	if (m>=cnt/4)
	cout<<max(a[cnt].w+a[cnt-2].w,a[m+1].w+a[m+3].w);
	else
	{
		cout<<a[4*m+1].w+a[4*m+3].w;
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);	
	n=read();m=read();
	int flag=1;
    for (int i=1;i<=n-1;i++)
    {
    	int x,y,z;
    	x=read();y=read();z=read();
    	if (x!=1&&y!=1) flag=0; 
		add(x,y,z);
    	add(y,x,z);
	}
	if (m==n-1)
	{
		sort(a+1,a+cnt+1,cmp);
		cout<<a[cnt].w;
		return 0;
	}	
	if (m==1)
	{
		pianfen1();
		return 0;
	}
	if (flag)
	{
		pianfen2();
		return 0;
	}
	sort(a+1,a+cnt+1,cmp);
	long long ans=0;
	for (int i=cnt;i>=m;i-=2)
	{
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
/*
7 2
1 2 10
1 3 5
1 4 6
1 5 7
1 6 8
1 7 2
*/
