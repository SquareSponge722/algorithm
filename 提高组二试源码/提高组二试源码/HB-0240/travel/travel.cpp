#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
bool book[5005][5005];
int aa[100],e=0;
bool f;
int n;
void dfs(int a,int b){
	f=0;  
	if(b>n||a>n) return ;
	if(book[a][b]=/*=*/1){
		e++;
		aa[e]=b;
//		book[a][b]=0;
		f=1;
	}
//	dfs(a,b+1);
	if(f==0)
		dfs(a+1,b);
	dfs(a,b+1);
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m;
	cin>>n>>m;
	int a,b;
	int p[100],q[100];
	for(int i=1;i<=m;i++){
		scanf("%d %d",&p[i],&q[i]);
		a=p[i];
		b=q[i];
		book[a][b]=1;
		book[b][a]=1;
	}
	int t;
	for(int i=1;i<=m;i++){
			if(p[i]>p[i+1]){
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=p[i];
				t=q[i];
				q[i]=q[i+1];
				q[i+1]=t;
			}
	}
	dfs(1,1);
	for(int i=1;i<=e;i++){
		cout<<aa[i]<<" ";
	}
	return 0;
}
