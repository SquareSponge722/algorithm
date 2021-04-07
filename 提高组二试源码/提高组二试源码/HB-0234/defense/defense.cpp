#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include  <stack>
using namespace std;
int n,m,p[100000],a[2000][2000],u,v,ans;
int aa,bb,x,y;
bool b[100000];
string s;
void dfs(int k){
		if(b[k-1]==0){
			ans+=p[k];
			b[k]=1;
			dfs(k+1);
			}
				if(k==n) return;
	}
int main()
{
freopen("defense.in","r",stdin);
freopen("defense.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=1;i<=n;i++) cin>>p[i];
 for(int i=1;i<n;i++){
 	cin>>u>>v;
 	a[u][v]=1;
 	a[v][u]=1;
}
	if(s=="A3"){
		
		dfs(1);
		cout<<ans;
		return 0;	
		}
for(int i=1;i<=m;i++){
	cin>>aa>>x>>bb>>y;
	if(s=="A3"){
		if(x==0&&y==0) cout<<'-1';
	}
	}
	return 0;
}
