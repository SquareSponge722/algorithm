#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,u,v,a,x,b,y,ans,ans1;
string type;
int spend[100005],vis[100005][100005];
int A(int s,int a,int x,int b,int y) {
	int p=a+1,o=a-1,i=b+1,u=b-1;
	for(int i=0; i<n; i++) {
		vis[i][i+1]=1;
		vis[i+1][i]=1;
	}
	if(s==1) {
		vis[a][a]=1;
		vis[a][p]=0;
		vis[a][o]=0;
		if(y==0) {
			if(vis[b][i]==0||vis[b][u]==0||vis[b][b]==1||vis[i][b]==0||vis[u][b]==0)return -1;
			vis[b][i]=1;
			vis[b][u]=1;
			vis[b][b]=0;
			vis[i][b]=1;
			vis[u][b]=1;
		}
		if(y==1) {
			if(vis[b][i]==1||vis[b][u]==1||vis[b][b]==0||vis[i][b]==1||vis[u][b]==1)return -1;
			vis[b][i]=0;
			vis[b][u]=0;
			vis[b][b]=1;
			vis[i][b]=0;
			vis[u][b]=0;
		}
	}
	if(s==2) {
		if(x==y)return -1;
		if(x==1&&y==0) {
			if(vis[a][p]==1||vis[a][o]==1||vis[a][a]==0||vis[p][a]==1||vis[o][a]==1)return -1;
			vis[a][p]=0;
			vis[a][o]=0;
			vis[a][a]=1;
			vis[p][a]=0;
			vis[o][a]=0;
			if(x==0&&y==1) {
				if(vis[b][i]==1||vis[b][u]==1||vis[b][b]==0||vis[i][b]==1||vis[u][b]==1)return -1;
				vis[b][i]=0;
				vis[b][u]=0;
				vis[b][b]=1;
				vis[i][b]=0;
				vis[u][b]=0;
			}
		}
	}
	if(s==3) {
		if(x==0) {
			if(vis[a][p]==0||vis[a][o]==0||vis[a][a]==1||vis[p][a]==0||vis[o][a]==0)return -1;
			vis[a][p]=1;
			vis[a][o]=1;
			vis[a][a]=0;
			vis[p][a]=1;
			vis[o][a]=1;
		}
		if(x==1) {
			if(vis[a][p]==1||vis[a][o]==1||vis[a][a]==0||vis[p][a]==1||vis[o][a]==1)return -1;
			vis[a][p]=0;
			vis[a][o]=0;
			vis[a][a]=1;
			vis[p][a]=0;
			vis[o][a]=0;
		}
		if(y==0) {
			if(vis[b][i]==0||vis[b][u]==0||vis[b][b]==1||vis[i][b]==0||vis[u][b]==0)return -1;
			vis[b][i]=1;
			vis[b][u]=1;
			vis[b][b]=0;
			vis[i][b]=1;
			vis[u][b]=1;
		}
		if(y==1) {
			if(vis[b][i]==1||vis[b][u]==1||vis[b][b]==0||vis[i][b]==1||vis[u][b]==1)return -1;
			vis[b][i]=0;
			vis[b][u]=0;
			vis[b][b]=1;
			vis[i][b]=0;
			vis[u][b]=0;
		}

	}
	for(int i=0; i<n; i++)
		if(vis[i]!=0)
			ans=ans+spend[i];
	return ans;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>type;
	for(int i=0; i<n; i++)cin>>spend[i];
	for(int i=1; i<n; i++) {
		cin>>u>>v;
		vis[u][v]=1;
		vis[v][u]=1;
	}
	for(int i=0; i<m; i++) {
		cin>>a>>x>>b>>y;
		if(type[0]=='A')ans1=A(type[1],a,x,b,y);
	}
	cout<<ans1;
	return 0;
}
