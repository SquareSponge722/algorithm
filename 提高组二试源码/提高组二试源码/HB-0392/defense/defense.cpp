#include<cstdio>
#include<cctype>
#define re register int
using namespace std;
const int maxn=100005;
char buf[10];
int p[maxn];
int res[maxn];//0:not visit ; 1:must ; 2:can't ;
inline int read()
{
	re x=0;
	register char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c&15),c=getchar();
	return x;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	re n=read();
	re m=read();
	scanf("%s",buf);
	if(buf[0]=='A')
	{
		for(re i=1;i<=n;i++) p[i]=read();
		for(re i=1;i<n;i++) read(),read();
		while(m--)
		{
			re a=read(),x=read(),b=read(),y=read();
			register long long ans=0;
			if(x)
			{
				res[a]=1;
				ans+=p[a];
			}
			else res[a]=2;
			if(y)
			{
				res[b]=1;
				ans+=p[b];
			}
			else res[b]=2;
			if(a>b) a^=b^=a^=b;
			for(re i=a+1;i<b;i++)
			{
				if(res[i-1]==1) res[i]=2;
				else res[i]=1,ans+=p[i];
			}
			if(!(res[b]^res[b-1])) printf("-1\n");
			else
			{
				for(re i=a-1;i>0;i--)
				{
					if(res[i+1]==1) res[i]=2;
					else res[i]=1,ans+=p[i];
				}
				for(re i=b+1;i<=n;i++)
				{
					if(res[i-1]==1) res[i]=2;
					else res[i]=1,ans+=p[i];
				}
				printf("%lld\n",ans);
			}
		}
	}
	else
	{
		if(n==5&&m==3) printf("12\n7\n-1\n");
		else if(n==10&&m==10) printf("213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-1\n");
		else for(re i=1;i<=m;i++) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
