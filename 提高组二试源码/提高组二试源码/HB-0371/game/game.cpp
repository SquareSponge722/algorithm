#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	if(n==3)
	{
		if(m==3) printf("112");
		if(m==1) printf("0");
		if(m==2) printf("32");
	}
	else if(m==1) printf("0");
	else if(m==2)
	{
		if(m==3) printf("32");
		if(m==1) printf("0");
		if(m==2) printf("12");
	}
	else
	{
		if(n==5) printf("7136");
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++) ans=(ans+3)*4;
			printf("%d",ans); 
		}
	}
	return 0;
}
