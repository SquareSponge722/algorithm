#include <cstdio>
//#define Z;
using namespace std;
int n,m,ans[5002],c[5002];
bool a[5002][5002],b[5002];
void print()
{
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return;
}
void dfs(int k,int last,int i)
{
	bool flag=false;
	if(b[k]==false)
	{
		b[k]=true;
		c[k]=last;
		ans[i]=k;
		int l=i+1;
	}
	if(i==n)
	{
		return;
	}
	for(int j=1;j<=n;j++)
		if(a[k][j]=true)
		{
			dfs(j,k,l);
			flag=true;
		}
	if(flag=false)
		dfs(c[k],k,i);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		a[p][q]=1;
		a[q][p]=1;
	}
	dfs(1,0,1);
	print();
	return 0;
}

