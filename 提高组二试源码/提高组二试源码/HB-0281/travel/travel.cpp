#include<bits/stdc++.h>
using namespace std;
int n,m,g[5005][5005],b[5005],sum=0,visit[5005][5005],last;
void init(){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	      visit[i][j]=0;
	for(int i=1;i<=n;i++)visit[i][i]=-1;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	      g[i][j]=0;
	for(int i=1,u,v;i<=m;i++){
	   cin>>u>>v;
	   g[v][u]=g[u][v]=1;
	}
}

void Prim(int x){
	if(b[x]==0){cout<<x<<" ";sum++;}
	b[x]=1;
	if(sum==n){return;}
	int m=0x7fffffff/2;
	for(int i=1;i<=n;i++)
		if(g[x][i]==1&&visit[x][i]==0)
			m=min(i,m);
	if(m==0x7fffffff/2){
		for(int i=1;i<=n;i++)
	  	if(visit[x][i]==1&&g[x][i]==1){
	  		visit[x][i]++;
	  		visit[i][x]++;
			Prim(i);
		  }
	}
	else {
		visit[x][m]++;
		visit[m][x]++;
		Prim(m);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	init();
	Prim(1);
	return 0;
}
