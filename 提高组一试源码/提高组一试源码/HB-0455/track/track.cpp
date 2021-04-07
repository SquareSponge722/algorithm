#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
struct ha{
	int f,v;
};
vector<ha>q[50050];
int p,tot=0;
int a[50050],k[50050];
inline void dfs(int u,int t,int sum){
	if(sum>tot){
		p=u;tot=sum;
	}
	for(int i=0;i<q[u].size();i++){
		int f=q[u][i].f,v=q[u][i].v;
		if(f!=t)
			dfs(f,u,sum+v);
	}
}
inline void dfs1(int x,int y,int s){
	if(y>m) return;
	if(n-x<m-y) return;
	if(x==n-1){
		if(y==m) tot=max(tot,s);
		return;
	}
	for(int i=x+1;i<=n;i++)
		dfs1(i,y+1,min(s,a[i]-a[x]));
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	if(m==n-1){
		int ans=99999999;
		for(int i=1;i<=n-1;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ans=min(ans,c);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n-1;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ha s;s.f=b;s.v=c;
			q[a].push_back(s);
			s.f=a;
			q[b].push_back(s);
		}
		dfs(1,0,0);
		tot=0;
		dfs(p,0,0);
		cout<<tot;
		return 0;
	}
	int f=0;
	for(int i=1;i<=n-1;i++){
		int aa,b,c;
		if(aa!=1) f=1;
		cin>>aa>>b>>c;
		a[i]=c+a[i-1];
		k[i]=c;
	}
	if(!f){
		dfs1(0,0,9999999);
		cout<<tot;
		return 0;
	}
	if(f==1){
		sort(k+1,k+n);
		int s=n-1,x=n-1-m;
		while(x--){
			k[1]+=k[s];
			s--;
			sort(k+1,k+s);
		}
		cout<<k[1];
		return 0;
	}
	return 0;
}
