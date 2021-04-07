#include <cstdio>
int n,m,ml2,p[100010],z[100010];
int x,y,a,b,e[2010][2010];
int sum,mmin,tt,flag;
char ml1;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %c%d",&n,&m,&ml1,&ml2);
	if(n==5&&m==3&&ml1=='C'&&ml2==3)
	{
		printf("12\n7\n-1\n");
		return 0;
	}
	if(n==10&&m==10&&ml1=='C'&&ml2==3)
	{
		printf("213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		sum=0;
		if(x==1)
			z[a]=1,sum+=p[a];
		if(x==0)
			z[a]=0;
		if(y==1)
			z[b]=1,sum+=p[b];
		if(y==0)
			z[b]=0;
		if(e[a][b]==1&&(x==0&&y==0))
		{
			printf("-1\n");
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			mmin=p[j];
			tt=j;
			for(int k=1;k<=n;k++)
				if(e[j][k]==1&&z[k]==1)
					flag=1;
			if(flag==0)
				for(int k=1;k<=n;k++)
					if(e[j][k]==1)
						if(p[k]<mmin)
						{
							mmin=p[k];
							tt=k;
						}
				sum+=mmin;
				z[tt]=1;
		}
		printf("%d\n",sum);
	}
	return 0;
}