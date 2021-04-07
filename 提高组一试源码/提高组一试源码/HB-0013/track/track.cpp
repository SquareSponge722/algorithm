#include <iostream>
#include <stdio.h>
using namespace std;

int n=0,m=0;
int maxroad=0;
int map[6][6]={-1};
int book[6][6]={0};
	
int min(int a,int b){
	if(a>b) return b;
	else return a;
}

int max(int a,int b){
	if(a<b) return b;
	else return a;
}

void dfs(int x,int nowroad){
	for(int i=1;i<=n;i++){
		if(i!=x&&book[x][i]==0&&map[x][i]!=-1){
			book[x][i]=1;
			book[i][x]=1;
			nowroad=nowroad+map[x][i];
			maxroad=max(nowroad,maxroad);
			dfs(i,nowroad);
			book[x][i]=0;
			book[i][x]=0;
		}
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a=0,b=0,l=0;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a>>b>>l;
		map[a][b]=l;
	}
	for(int i=1;i<=n;i++) dfs(i,0);
	cout<<maxroad;
	return 0;
}	
