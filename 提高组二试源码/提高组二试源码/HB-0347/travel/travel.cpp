#include<cstdio>
#include<algorithm>
using namespace std;
int x[5005][2],y[5005][2],a[5005][5005],t,t1[5005];
int travel(int i)
{
	for(int o=1;o<=t;o++)
	if(i==t1[o])
		return 0;
	t++;
	t1[t]=i;
	printf("%d ",i);
	int j=1;
	while(a[i][j+1]!=0)
		j++;
	if(a[i][1]>a[i][2]&&j==2)
		swap(a[i][1],a[i][2]);
	for(int k=1;k<=j;k++)
	{	
		travel(a[i][k]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[0][0],&x[0][1]);
		x[x[0][0]][1]++;
		x[x[0][1]][1]++;
		a[x[0][0]][x[x[0][0]][1]]=x[0][1];
		a[x[0][1]][x[x[0][1]][1]]=x[0][0];
	}
	travel(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}      
