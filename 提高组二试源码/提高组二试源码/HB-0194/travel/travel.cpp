#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[105],b[105],c[105];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==a[i+1]&&b[i]==b[i+1]) a[i]=b[i];
		else break;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",a[i]);
	}
	fclose(stdin);fclose(stdout);
}
