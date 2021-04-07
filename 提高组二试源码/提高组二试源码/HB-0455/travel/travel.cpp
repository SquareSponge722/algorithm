#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
bool c[5005][5005],flag,vis[5005];
int k[5005][5005];
int p[5005],pp[5005];
void dfs(int s,int tot){
	if(tot==n+1){
		if(m==n-1){
			for(int i=1;i<=n;i++) cout<<p[i]<<" ";
			exit(0);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(vis[i]) cnt++;
		if(cnt==n) flag=1;
		return;
	}
	for(int i=1;i<=n;i++)
		if(c[s][i]==1&&i!=s&&(!k[s][i]||k[s][i]==s)){
			if(flag==1) return;
			if(k[s][i]==s) dfs(i,tot);
			if(!k[s][i]){
				k[s][i]=i;
				k[i][s]=i;
				p[tot]=i;
				vis[i]=1;
				dfs(i,tot+1);
				k[s][i]=0;
				k[i][s]=0;
				vis[i]=0;
			}
		}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		c[a][b]=1;
		c[b][a]=1;
	}
	if(m==n-1){
		p[1]=1;
		dfs(1,2);
	}
	for(int i=1;i<=n;i++) pp[i]=99999;
	if(n==m){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(c[i][j]){
					c[i][j]=0;
					vis[1]=1;
					p[1]=1;
					dfs(1,2);
					if(flag){
						int fl=0;
						for(int k=1;k<=n;k++)
							if(p[k]<pp[k]){
								fl=1;
								break;
							}
						if(fl)
							for(int k=1;k<=n;k++) pp[k]=p[k];
						flag=0;
					}
					c[i][j]=1;
				}
		for(int i=1;i<=n;i++) cout<<pp[i]<<" ";
	}
	return 0;
}
