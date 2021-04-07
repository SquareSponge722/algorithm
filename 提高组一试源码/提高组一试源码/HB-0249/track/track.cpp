#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m;
int a,b,c;
struct node{
	int to;
	int pre;
	int pi;
};
node p;
vector<node>t[50005];
bool k[50005];
int dfs(int y,int sum){
	for(int i=0;i<t[y].size();i++){
		if(k[t[y][i].pi]!=1){
			sum+=t[y][i].pre;
			k[t[y][i].pi]=1;
			dfs(t[y][i].to,sum);
			k[t[y][i].pi]=0;
		}
	}
	return sum;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		p.pre=c;
		p.to=b;
		p.pi=i;
		t[a].push_back(p);
		p.pre=c;
		p.to=a;
		p.pi=i;
		t[b].push_back(p);
	}
	cout<<dfs(1,0)<<endl;
}
