#include <iostream>
#include <cstdio>
using namespace std;


bool way[5000][5000],used[5000];
int n,m,c[5000]={};


int deep(int now){
	for(int i = 2;i<=n;i++){
		if(way[c[now]][i]==1&&used[i]==0){
			while(c[now]!=0) now++;
			c[now] = i;
			used[i] = 1;
			if(now==n){
				for(int i = 1;i<=n;i++) cout<<c[i]<<" ";
				return 0;
			}
			else return deep(now);
		}		
	}
	 return deep(now-1);
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int u,v;
		cin>>u>>v;
		way[u][v] = 1;
		way[v][u] = 1;
	}
	
	c[1] = 1;

	
	deep(1);	
	
	return 0;
}
