# include<cstdio>
# include<cstring>
# include<algorithm>

using namespace std;

int a[20];
int book[20];

void chuli(int n)
{
	int N=n;
	int i,j;
	for(i=N;i>=1;i--)
	{
		for(j=1;j<i;j++)
		{
			if(a[i]%a[j]==0) book[i]=1;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(book[i]) continue;
		
	}
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		memset(a,0,sizeof(a));
		memset(book,0,sizeof(book));
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		chuli(n);
	}
}
