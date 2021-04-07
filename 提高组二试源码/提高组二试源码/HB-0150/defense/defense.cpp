#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+100;
const ll inf=1e17;
struct data
{
	int x,y;	
}len[maxn];
int book[maxn];
int A,X,B,Y,n,m;
char type[10];
ll p[maxn],sum[maxn];
ll ans,cost1;

bool check()
{
	if(book[A]!=X||book[B]!=Y) return 0;
	for(int i=1;i<=n-1;i++)
	{		
		if(!book[len[i].x]&&!book[len[i].y]) return 0;
	}
	return 1;
}

void dfs(int now)
{
	if(now==n+1)
	{
		bool kk=check();
		if(kk) ans=min(ans,cost1);
		return;	
	}
	book[now]=0;
	dfs(now+1);
	book[now]=1;
	cost1+=p[now];
	dfs(now+1);
	book[now]=0;
	cost1-=p[now];
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",type+1);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		len[i].x=x,len[i].y=y;
	}
if(n<=10&&m<=10)
{
	while(m--)
	{
		ans=inf;
		cost1=0;
		scanf("%d%d%d%d",&A,&X,&B,&Y);
		dfs(1);
		if(ans==inf) printf("-1\n");
		else printf("%lld\n",ans);
	}
}
else
{
	if(type[1]=='A')
	{
		sum[1]=p[1];
		for(int i=3;i<=n;i+=2) sum[i]=sum[i-2]+p[i];
		for(int i=2;i<=n;i+=2) sum[i]=sum[i-2]+p[i];
		if(type[2]=='1')
		{
			int pos1;
			if(Y==0)
			{
				if(B%2==1) pos1=0;
				else pos1=1;
			}
			else
			{
				if(B%2==1) pos1=1;
				else pos1=0;
			}
			if((n%2==0&&pos1==0)||(n%2==1&&pos1==1)) printf("%lld\n",sum[n]);
			else printf("%lld\n",sum[n-1]);
		}
		else
		{
			if(A>B) swap(A,B),swap(X,Y);
			if(X==0&&Y==0) printf("-1\n");
			else
			{
				if(X==1) ans+=sum[A];
				else ans+=sum[A-1];
				if(Y==1) ans+=sum[B];
				else ans+=sum[B-1];
				printf("%lld\n",ans);
				
			}
		}
	}
}
/*
else
{
	if(type[1]=='A')
	{
		sum[1]=p[1];
		for(int i=3;i<=n;i+=2) sum[i]=sum[i-2]+p[i];
		for(int i=2;i<=n;i+=2) sum[i]=sum[i-2]+p[i];
		if(A>B) swap(A,B),swap(X,Y);
		if(B==A+1&&X==0&&Y==0) printf("-1\n");
		else
		{
			if(X==0)
			{
				ans+=sum[A-1];
				if(Y==0)
				{
					ans+=	
				}
			}
			else
			{	
					
			}
		}
	}
}*/
	return 0;	
}
