#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
vector <int> f[5000];
int ans[5005],n,m,cnt=0;
bool vis[5005]={0};
void dfs(int p){
	if(vis[p])return ;
	int t=f[p].size();
	vis[p]=1;{ans[cnt++]=p;}
	fo(i,t)dfs(f[p][i]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==m+1){
		fo(i,m){
			int x,y;
			scanf("%d%d",&x,&y);
			f[x].push_back(y);
			f[y].push_back(x);
		}
		fo(i,n)sort(f[i].begin(),f[i].end());
		dfs(1);
		fo(i,cnt)printf("%d ",ans[i]);
		return 0;
	}
}
