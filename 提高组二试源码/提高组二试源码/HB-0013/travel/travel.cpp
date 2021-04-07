#include <iostream>
#include <stdio.h>
using namespace std;
int n=0,m=0;
int map[5001][5001]={0};
int book[5001]={0};
int now[5001]={0};
int waycf[5001]={0};//Where are you come from???
int ans[5001];

void dfs(int nowposition,int step,bool mark){
	int sum=0;
	bool flag=true;
	if(mark){
//		book[nowposition]=1;
		now[step]=nowposition;
		for(int i=1;i<=n;i++){
			sum=sum+book[i];
		}
		if(sum==n){
			for(int i=1;i<=n;i++){
				if(now[i]>=ans[i]){
					flag=false;
				}
			}
			if(flag){
				for(int i=1;i<=n;i++){
					ans[i]=now[i];
				}
			}
			return;
		}
	}
	for(int i=1;i<=step;i++){
		if(now[i]>=ans[i]) return;
	}
	for(int i=1;i<=n+1;i++){
		if(i==n+1&&step!=1){
			dfs(waycf[nowposition],step,false);
		}
		if(map[nowposition][i]==1&&book[i]==0){
			waycf[i]=nowposition;
			book[i]=1;
			dfs(i,step+1,true);
			waycf[i]=0;
			book[i]=0;
		}
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0;
	for(int i=1;i<=5000;i++){
		ans[i]=999999999;
	}
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		map[a][b]=1;
		map[b][a]=1;
	}
	for(int i=1;i<=n;i++){
		book[i]=1;
		dfs(i,1,true);
		book[i]=0;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;	
}
