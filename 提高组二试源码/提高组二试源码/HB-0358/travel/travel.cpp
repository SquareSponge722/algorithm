#include <bits/stdc++.h>
using namespace std;
vector <int> tree[5005];
void add(int from,int to) {
	tree[from].push_back(to);
	tree[to].push_back(from);
}
//int fa[5005][5005];
//queue <int > q;
bool ifuse[5005];
bool cmp(const int &a,const int &b) {
	return a<b;
}
void dfs(int fa) {
	sort(tree[fa].begin(),tree[fa].end(),cmp);
	cout<<fa<<' ';
	ifuse[fa]=1;
	for(int i=0; i<tree[fa].size(); i++) {
	//	ifuse[i]=1;
	if(!ifuse[tree[fa][i]])
		dfs(tree[fa][i]);
		ifuse[tree[fa][i]]=1;
	}
}
int n,m;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0,from,to; i<m; i++) {
		scanf("%d%d",&from,&to);
		add(from,to);
	}
	dfs(1);
	return 0;
}
