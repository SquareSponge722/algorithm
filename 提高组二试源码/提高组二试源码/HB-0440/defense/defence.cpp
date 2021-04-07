#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=100005;
int p[maxn],s[maxn],ss[maxn];
char s[5];
int n,m;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,&s);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&p[i]);
	}
	if(s[0]=='A')
	{
		for(int i=1; i<n; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
		}
		for(int i=0;i<=n;i++)
		{
			ss[i]=-1;
			s[i]=-1;
		}
		for(int i=1; i<=m; i++)
		{
			int a,x,b,y;
			scanf("%d %d %d %d",&a,&x,&b,&y);
			if(x==0&&y==0&&(a==b-1||a==b+1))
			{
				printf("-1\n");
			}
			if(x==1)
			{
				ss[a]=1;
				ss[a-1]=1;
				ans+=p[a];
			}
			else if(x==0)
			{
				s[a]=0;
			}
			if(y==1)
			{
				ss[b]=1;
				ss[b-1]=1;
				ans+=p[b];
			}
			else if(y==0)
			{
				s[b]=0;
			}
			long long ans=0;
			for(int i=1;i<n;i++)
			{
				if(ss[i-1]==-1&&ss[i]==-1&&s[i]!=0)
				{
					ans+=p[i];
				}
			}
			printf("%lld\n",ans);
			ss[a]=-1;
			ss[a-1]=-1;
			ss[b]=-1;
			ss[b-1]=-1;
			s[a]=-1;
			s[b]=-1;
		}
	}
	return 0;
}
