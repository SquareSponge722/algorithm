# include <iostream>
# include <cstdio>
using namespace std;
int zhen[5005][5005];
int n,m;
int biao=0;
int guo[5005];//一个桶，把已到的城市标1 
int yiguo[5005];//第一的城市是1号，第二个城市是。。。 
int ji=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5001;++i){
		zhen[i][i]=7;
	}
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		zhen[u][v]=1;
		zhen[v][u]=1;
	}
	cout<<1<<' ';
	guo[1]=1;
	yiguo[1]=1;	
	for(int j=2;j<=n;++j){
		if(guo[j]==1) continue;
		biao=0;	
		for(int i=1;i<=ji;++i){
			if(zhen[yiguo[i]][j]==1){
				ji++;
				guo[j]=1;
				yiguo[ji]=j;
				cout<<j<<' ';
				biao=1;
				break;
			}
		}
		if(biao==1) j=1;
	}
	return 0;
}
