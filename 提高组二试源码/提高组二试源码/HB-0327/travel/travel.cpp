#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>E[5005],now;
bool used[5005];
priority_queue<int,vector<int>,greater<int> > a;
void bfs(){
	a.push(1);
	used[1]=1;
	while(!a.empty()){
		int v=a.top();
		a.pop();
		now.push_back(v);
		for(int i=0;i<E[v].size();i++)
			if(!used[E[v][i]]){a.push(E[v][i]);used[E[v][i]]=1;}
	}
	for(int i=0;i<now.size();i++) printf("%d ",now[i]);
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		E[v].push_back(u);
		E[u].push_back(v);
	}
	bfs();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
