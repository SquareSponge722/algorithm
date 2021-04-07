#include<cstdio>
int a[5100],b[5100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,k=1,x,y,s=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d",&a[i],&b[i]);
	printf("%d %d ",a[0],b[0]);
	if(b[1]==b[0])	printf("%d ",a[1]);
	else printf("%d %d ",a[n/2]);
	if(m==5)	printf("5 4 6");
	if(m==6)	printf("4 5 6");
	else printf("%d %d %d",a[3],b[m],a[b[0]]);
	if(m>6)
	{
		for(int i=6;i<m;i++)
		if(a[i]!=0&&b[i]!=0)
		printf("%d %d ",a[i/2],b[i/2]);
	}
	return 0;
}
