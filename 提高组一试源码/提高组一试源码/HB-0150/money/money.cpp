#include <bits/stdc++.h>
using namespace std;

int T,n;
int a[1100];
bool book[30000];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(book,0,sizeof(book));
		scanf("%d",&n);
		int maxx=0;
		for(int i=1;i<=n;i++) { scanf("%d",&a[i]);maxx=max(maxx,a[i]); }
		sort(a+1,a+1+n);
		int m=n;
		for(int i=1;i<=n;i++)
		{
			if(book[a[i]]) { m--;continue; }
			for(int j=1;j<=maxx;j++)
			{
				if(!book[j]) continue;
				for(int k=1;j+k*a[i]<=maxx;k++) book[j+k*a[i]]=1;	
			}
			for(int j=1;j*a[i]<=maxx;j++) book[j*a[i]]=1;
		}
		printf("%d\n",m);
	}
	return 0;
}
