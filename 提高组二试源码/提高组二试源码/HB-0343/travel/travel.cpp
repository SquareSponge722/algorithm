#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,u[5005],v[5005],a[5005],b[5005];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d\n",&u[i],v[i]);
		if(u[1]=1)
		a[1]=1;
		if(i>1)
		{
			a[i]=v[i];
			a[i+1]=u[i];
		}
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
}
