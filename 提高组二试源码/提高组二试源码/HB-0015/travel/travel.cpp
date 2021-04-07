#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m,ans[N],l=0;
vector <int> dian[N];
bool v[N];
void dfs(int x) {
	ans[++l]=x;
	v[x]=1;
	priority_queue <int> pq;
	for(unsigned int i=0; i<dian[x].size(); i++) {
		int y=dian[x][i];
		if(v[y])continue;
		pq.push(-y);
	}
	while(pq.size()) {
		int y=-pq.top();
		pq.pop();
		dfs(y);
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(v,0,sizeof(v));
	for(int i=1; i<=m; i++) {
		int x,y;
		cin>>x>>y;
		dian[x].push_back(y);
		dian[y].push_back(x);
	}
	dfs(1);
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
