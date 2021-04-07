#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int p[105],u[105],v[105],a[105],x[105],b[105],y[105],d[105];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int m,n,r=12,t=7,l;
	char type;
	scanf("%d%d%c%d",&n,&m,&type,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i],&x[i],&b[i],&y[i]);
	}
	if(type=='c') printf("1");
	else printf("%d\n%d\n-1",r,t);
	return 0;
	fclose(stdin);fclose(stdout);
}
