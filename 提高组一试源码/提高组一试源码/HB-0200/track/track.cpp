#include<iostream>
#include<cstdio>
using namespace std;

const int inf = 1e8;

int n,m;
int dis[505][505];
long long ans = 1e9;
int main()
{
	int a,b,l;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);

	scanf("%d%d",&n,&m);

	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			dis[i][j] = inf;

	for(int i=1; i<n; i++)
		{
			scanf("%d%d%d",&a,&b,&l);
			dis[a][b] = l;
		}
	
	if(m>1)
		{
			for(int k=1; k<n; k++)
				for(int i=1; i<n; i++)
					for(int j=1; j<n; j++)
						if(dis[i][j]>dis[i][k]+dis[k][j])dis[i][j] = dis[i][k]+dis[k][j];
			
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					if(ans>dis[i][j])ans = dis[i][j];
			
			cout<<ans<<endl;		
		}
	
	return 0;
}
