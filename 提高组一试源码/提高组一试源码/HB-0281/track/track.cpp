#include<bits/stdc++.h>
using namespace std;
int g[10005][10005],wei[10005][10005];
int n,m,k[10005],ans=0,f=0;
void init(){
	for(int i=1,a,b,c;i<=n-1;i++){
       cin>>a>>b>>c;
       wei[a][k[a]]=c;
       g[a][k[a]]=b;
       k[a]++;
	}
}

int solve(int a){
	int c=0;
	if(k[a]==0)return c;
	for(int i=0;i<k[a];i++){
		f=max(f,solve(g[a][k[a]])+wei[a][k[a]]);
	}
	return f;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			if(k[i]==0)continue;
			else ans=max(solve(i),ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
