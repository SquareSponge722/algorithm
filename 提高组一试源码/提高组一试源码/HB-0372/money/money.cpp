#include<cstdio>
int a[25500];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,s,m;
	scanf("%d",&t);
	for(int r=1;r<=t;r++)
	{
		scanf("%d",&n);
		m=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1)	{printf("1\n");continue;}
		for(int i=1;i<=n;i++)
			if(a[i]==1)	{printf("1\n");continue;}
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
			{
				if(a[i]==0)	break;
				s=0;
				while(s<a[i])
				{
					s+=a[j];
					if(a[i]==s)	m--,i++;
				}
			}
		printf("%d\n",m);
	}
	return 0;
}
