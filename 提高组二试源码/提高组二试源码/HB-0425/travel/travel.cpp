#include<bits/stdc++.h>
#define N 5001 
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
		s=s*10+ch-'0';ch=getchar();
	}
	return s*p;
}
int n,m;
struct EDGE
{
	int u,v,next;
}a[N*2];
int head[N];
int cnt=0;
void add(int x,int y)
{
	cnt++;
	a[cnt].u=x;
	a[cnt].v=y;
	a[cnt].next=head[x];
	head[x]=cnt;
}
void input()
{
	n=read();m=read();
	int x,y;
	for (int i=1;i<=m;i++)
    {
    	x=read();y=read();
    	add(x,y);add(y,x);
	}
}
int e[N];
int b[N];
int pre[N];
int mmin;
int cat(int x)
{
	int flag=1;
	for (int i=head[x];i;i=a[i].next)
    {
    	int g=a[i].v;
    	if (b[g]==0)
        {
        	flag=0;
        	mmin=min(mmin,g);
		}
	}
	if (flag) 
	{
		mmin=min(mmin,cat(pre[x]));
	}
	return mmin;
}
int tot;
void playing(int now)
{
	if (tot==n) return ;
	mmin=6001;
	int g=cat(now);
	if (b[g]==1)
	{
		playing(g);
	}
//	cout<<now<<" "<<g<<endl;
	if (b[g]==0)
	{
		tot++;
		b[g]=1;
		cout<<g<<" ";
		pre[g]=now;
		playing(g);
	}
}
void hhh()
{
	b[1]=1;
	tot=1;
	cout<<1<<" ";
	playing(1);
}
//int c[N];
void init()
{
	memset(e,0,sizeof(e));
	for (int i=1;i<=n;i++)
	{
		int g=head[i];
		if (a[g].next==0) e[i]=1;
	}
	/*for (int i=1;i<=n;i++)
	cout<<e[i]<<" ";*/
}
int sum=0;
int find(int now)
{
//	int flag=0;
	for (int i=head[now];i;i=a[i].next)
	{
		int g=a[i].v;
		if (b[g]==0)
		{
//			flag=1;
			mmin=min(mmin,g);
		}
	}
//	if (now==2) cout<<mmin<<endl;	
	if (pre[now]!=0&&e[pre[now]]!=1)
	{
//		flag=1;
		mmin=min(mmin,find(pre[now]));
	}	
//	if (flag==0) return 0;
	return mmin;
}
void dfs(int now)
{
	if (sum==n) return;
	mmin=6001;
	int g=find(now);
//    cout<<g<<endl;
//	cout<<now<<" "<<g<<endl;
//if (g==0) return;
	if (b[g]==0)
	{
		sum++;
		b[g]=1;
		pre[g]=now;
		cout<<g<<" ";
		dfs(g);
	}
	else
	{
		dfs(g);
	}
}
void work()
{
	pre[1]=0;
	cout<<1<<" ";
	sum=1;
	b[1]=1;
	dfs(1);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    input();
    if (m==n-1)
    {
    	hhh();
	}
	if (m==n)
	{
    init();
	work();
    }
	return 0;
}
/*
10 9
1 2 
2 4
6 1
3 1
2 5
6 8
7 6
9 3
10 9
*/
