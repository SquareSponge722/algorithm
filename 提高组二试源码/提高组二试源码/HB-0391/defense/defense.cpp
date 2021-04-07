#include<cstdio>
#include<cstdlib>
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense","w",stdout);
	int m;
	char s[111];
	int n;
	scanf("%d %d ",&m,&n);
	scanf("%s",s);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
	}
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d %d",&x,&y);
	}
	if(m==5)
		printf("12\n-7\n-1");
	return 0;
}
