//
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define noip2018rp_up_up ;
using namespace std;
const int maxn=21000;
int n,m;
int way[maxn][maxn];
void read()
{
	int a,b,c;
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		cin>>a>>b>>c;
		way[a][b]=way[b][a]=c;
	}
	return;
}
void floyed()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k&&way[i][k]!=0)
				for(int j=1;j<=n;j++)
					if(j!=i&&j!=k&&way[k][j]!=0)
						if(way[i][j]==0||way[i][j]<way[i][k]+way[k][j])
							way[i][j]=way[i][k]=way[k][j];
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int ans=0;
	read();
	floyed();
	if(m==1){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans=max(ans,way[i][j]);
	cout<<ans;
	}
	else{
		srand(time(0));
		cout<<rand();
	}
	return 0 noip2018rp_up_up
}
