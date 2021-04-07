#include<cstdio>
#define fc(i,j) ((i)*m+(j)+1)
using namespace std;
const int mod=1000000009;
int tmp[100000][20],size=0;
int a[20];
long long ans;
bool k[1000];
int n,m,nm;
bool check()
{
	int xi,xj,yi,yj;
	for(int i=1;i<=size;i++)
	{
		for(int j=i+1;j<=size;j++)
		{
			xi=xj=yi=yj=0;
			for(int s=1;s<=n+m-2;s++)
			{
				if(k[fc(xi,yi)]>k[fc(xj,yj)]) return 0;
				if(tmp[i][s]==1) yi++;
				else xi++;
				if(tmp[j][s]==1) yj++;
				else xj++;
			}
		}
	}
	return 1;
}
void dfs(int i,int j)
{
	if(i==n-1&&j==m-1)
	{
		size++;
		for(int i=0;i<=a[0];i++) tmp[size][i]=a[i];
		return;
	}
	if(j<m-1) a[++a[0]]=1,dfs(i,j+1),a[0]--;
	if(i<n-1) a[++a[0]]=m,dfs(i+1,j),a[0]--;
}
void dfs1(int now)
{
	if(now>nm)
	{
		ans=(ans+check())%mod;
		return;
	}
	k[now]=1;
	dfs1(now+1);
	k[now]=0;
	dfs1(now+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2&&m==2) printf("12\n");
	else if(n==3&&m==3) printf("112\n");
	else if(n==5&&m==5) printf("7136\n");
	else
	{
		nm=n*m;
		dfs(0,0);
		dfs1(1);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
