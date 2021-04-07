#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int dist[1005][1005];
int main(){
	freopen("track.in","r",stdin);
	frepoen("track.out","w",stdout);
	int n;
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%d",&dist[a][b]);
		dist[b][a]=dist[a][b];
	}
	int ans=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]);
				ans=max(ans,dist[i][j]);
			}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
