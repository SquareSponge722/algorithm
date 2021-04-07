#include<bits/stdc++.h>
int req[100005]={0},w[100005],p[100005],mapn[20010][20010]={0},walk[20010]={0};
using namespace std;
int n,m,b,x,y,c1=1,min2=10000;
int dfs(int i,int j){
	if(mapn[c1][j]==1&&j<=min2&&walk[j]==0) {
			min2=j;
			}
			else return 19999;
    if(mapn[req[i-2]][j]==1&&j<=min2&&walk[j]==0) 
			min2=j;
		else return 19999;
		return	min(dfs(i-1,j),min2);
	
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	//c1 shangyige city LUOJIAODIAN
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		mapn[x][y]=1;
		mapn[y][x]=1;
	}req[0]=1;walk[1]=1;
	for(int i=1;i<n;i++){
		for(int j=2;j<=n;j++){
			
			walk[dfs(i,j)]=1;
		req[i]=min2;
		c1=min2;
		min2=19999;
	}}
	for(int i=0;i<n;i++) cout<<req[i]<<" ";
	return 0;
}
