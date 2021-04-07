#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 110
using namespace std;
int a[maxn],n,book[maxn],T;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			scanf("%d",&a[i]);
			sum++;
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
		{
			if(book[i]) continue;
			for(int j=i+1;j<=n;++j)
			{
				if(a[j]%a[i]==0){
					book[j]=1;
					continue;
				}
				if(book[j]) continue;
				int t=a[i]*a[j]-a[i]-a[j];
				for(int k=n;k>j;k--)
				{
					if(book[k]) continue;
					if(t>a[n]) break;
					if(a[k]>t) book[k]=1;
					else {
						if(a[k]%a[i]==0) {
						book[k]=1;
						continue;}
					
					for(int m=1;m<=a[i];++m)
						if((a[k]-a[j]*m)%a[i]==0){
							book[k]=1;
							m=a[i]+1;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;++i) sum-=book[i];
		memset(book,0,sizeof(book));
		printf("%d\n",sum);
	}		
	return 0;
}
