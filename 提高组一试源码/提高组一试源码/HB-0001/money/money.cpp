#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 105
using namespace std;
int n,t,book[N];
int a[N],maxn,minn;
int m;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(book,0,sizeof(book));
		scanf("%d",&n);
		m=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			book[i]=0;
			if(a[i]==1)
		      m=1;
		}
		for(int i=1;i<n;i++)
		  for(int j=i+1;j<=n;j++)
		  {
		  	maxn=max(a[i],a[j]);
		  	minn=min(a[i],a[j]);
		  	if(maxn%minn==0&&book[i]==0&&book[j]==0&&m!=1)
		  	{
		  	  	m-=2;
		  	  	book[i]=1;book[j]=1;
			}
		  	else if(minn%maxn==0&&((book[i]==0&&book[j]==1)||(book[i]==1&&book[j]==0))&&m!=1)
		  	{
		  	  	m-=1;
		  	  	book[i]=1;book[j]=1;
			}
		  }
		printf("%d\n",m);
	}
	return 0;
}
