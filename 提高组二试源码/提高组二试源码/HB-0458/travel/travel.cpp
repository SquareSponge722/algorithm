#include<bits/stdc++.h>
using namespace std;

int t,li;
int a[5005],la[5005],e[10005][2],mi,o=0;
bool b[5005];
int have(int x){
	mi=5005;
	t=a[x];
	if(b[e[t][0]]==false)mi=min(mi,e[t][0]);
	while(e[t][1]!=-1){
		t=e[t][1];
		if(b[e[t][0]]==false)mi=min(mi,e[t][0]);
	}
	return mi;
}
void add(int x,int y){
	o++;
	e[o][1]=a[x];
	e[o][0]=y;
	a[x]=o;
	return;
}
void sfs(int x){
	if(x==0)return;
	if(b[x]==false){
		b[x]=true;
		cout<<x<<" ";
	}
	li=have(x);
	if(li!=5005){
		la[li]=x;
		sfs(li);
	}
	else sfs(la[x]);
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=-1;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(m==n-1){
		sfs(1);
	}
	return 0;
}
