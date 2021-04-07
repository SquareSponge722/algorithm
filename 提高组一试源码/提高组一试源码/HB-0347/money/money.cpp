#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,tot,a[100];
int n2(int i,int j)
{
		int b,c;
		c=a[j]/a[i];
		if(a[i]*c==a[j]&&tot>1)
		tot--;	
		return 0;
}	
int n3(int i,int j,int k)
{
	sort(a+1,a+3);
	n2(i,j);
	n2(i,k);
	if(tot==n&&a[1]*a[2]-a[1]-a[2]<a[3])
	tot--;
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		tot=n;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}	
		if(n==2)
		{	
			n2(1,2);
		}
		if(n==3)
		{
			n3(1,2,3);
		}
		printf("%d\n",tot);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
