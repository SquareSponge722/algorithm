#include<bits/stdc++.h>
int req[100005]={0},w[100005],p[100005],mapn[20010]={0};
using namespace std;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,b,u,v;
	char a;
	cin>>n>>m>>a>>b;
	for(int i=0;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<n;i++){
		mapn[u][v]=1;mapn[v][u]=1
		if(a=='A') {mapn[i][i+1]=1;mapn[i+1][i]=1;
		}
		if(a=='B'){
			mapn[1][i]=1;mapn[i][1]=1;
		}
	}
	for(int i=1;i<=m;i++){
		int x1,x2,y1,y2;
		cin>>x1>>x2>>y1>>y2;
		if(x2==0&&y2==0&&mapn[x1][y1]==1) cout<<-1;
	}
	   if(a=='A'&&b==2){
		
	}
		if(a=='A'&&b==3){
		
	}
		if(a=='B'&&b==1){
		
	}
		if(a=='B'&&b==2){
		
	}
		if(a=='B'&&b==3){
		
	}
	}
	
	return 0;
}
