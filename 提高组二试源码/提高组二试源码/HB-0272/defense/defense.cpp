#include <cstdio>
#include <cstdlib>
using namespace std;
int n,m;
char ty[2];
bool dl[2010][2010];
int hf[2010];
bool zz[2010];
int p1,m1,p2,m2;
bool first=true;
int min;
void init()
{
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
		{
			dl[k][i]=false;
			dl[i][k]=false;
		}	
}
bool zz_ok()
{
	for(int k=1;k<=n;k++)
	{
		bool flag=false;
		for(int i=1;i<=n;i++)
			if(dl[k][i] &&( zz[i] || zz[k] ))
			{
				flag=true;
				break;
			}
		if(!flag)
			return false;
	}
	return true;
}
void dfs(int wz,int money)
{
	if(wz==n+1)
	{
		if(first)
		{
			if(zz_ok())
			{
				min=money;
				first=false;
			}
		}
		else
			if(money<min && zz_ok())
				min=money;
		return ;
	}
	if(wz==p1)
	{
		if(m1==0)
			dfs(wz+1,money);
		else
		{
			zz[wz]=true;
			dfs(wz+1,money+hf[wz]);
		}
	}
	if(wz==p2)
	{
		if(m2==0)
			dfs(wz+1,money);
		else
		{
			zz[wz]=true;
			dfs(wz+1,money+hf[wz]);
		}
	}
	if(wz!=p1 && wz!=p2)
	{	
		zz[wz]=true;
		dfs(wz+1,money+hf[wz]);
		zz[wz]=false;
		dfs(wz+1,money);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,ty);
	for(int k=1;k<=n;k++)
		scanf("%d",&hf[k]);
	for(int k=1;k<n;k++)
	{
		int p,q;
		scanf("%d %d",&p,&q);
		dl[p][q]=true;
		dl[q][p]=true;
	}
	for(int k=1;k<=m;k++)
	{
		first=true;
		for(int k=1;k<=n;k++)
			zz[k]=false;
		scanf("%d %d %d %d",&p1,&m1,&p2,&m2);
		dfs(1,0);
		if(first)
			printf("-1\n");
		else
			printf("%d\n",min);
	}
	return 0;
}
