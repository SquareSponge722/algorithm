#include<iostream>
#include<cstdio>
#define N 6000
#define il inline
#define rg register
#include<algorithm>
#include<vector>
using namespace std;
bool link[5100][5100];
vector <int> edg[N];
int n,m,all=1;
int a[N],last[N];
bool ed[N];
bool ok=0;
inline int read(){
	int sum=0,fu=-1;char a=getchar();
	while(a>'9'||a<'0'){
		if(a=='-')fu=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum*fu;
}
void dfs1(int now,int fat){
	if(ok)return;
	if(ed[now]==0){
		a[all]=now;
		all++;
	}
	if(all==n+1){
		ok=1;return;
	}
	int siz=edg[now].size();
	if(siz==0){
		dfs1(fat,now);
	}
	if(ed[now]){
		if(last[now]==siz-1)dfs1(fat,now);
		else{
			for(int i=last[now]+1;i<siz;++i){
				dfs1(edg[now][i],now);
			}
		}
	}
	ed[now]=1;
	for(int i=0;i<siz;++i){
		if(ed[edg[now][i]]==0&&edg[now][i]!=fat){
			last[now]=i;
			dfs1(edg[now][i],now);
		}
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	int s1,s2;
	for(int i=1;i<=m;++i){
		cin>>s1>>s2;
		link[s1][s2]=link[s2][s1]=1;
	}
	for(rg int i=1;i<=n;++i){
		for(rg int j=1;j<=n;++j){
			if(link[i][j])edg[i].push_back(j);
		}
	}
	for(int i=1;i<=n;++i){
		dfs1(i,0);
		if(ok)break;
	}
	for(int i=1;i<n;++i)cout<<a[i]<<' ';
	cout<<a[n]<<endl;
	return 0;
}
