#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=100000+10;
int n,d[maxn],ans,a[maxn][20],b[maxn][20];
void solve(int,int,int);
void RMQ();
int query(int,int);
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	RMQ();
	solve(1,n,0);
	printf("%d\n",ans);
    return 0;
}
void solve(int l,int r,int t){
	if(l==r){
		ans+=d[l]-t;
		return;
	}
	int x=query(l,r);
	ans+=d[x]-t;
	if(x!=l)solve(l,x-1,d[x]);
	if(x!=r)solve(x+1,r,d[x]);
	return;
}
void RMQ(){
	for(int i=1;i<=n;i++){
	a[i][0]=d[i];
	b[i][0]=i;
}
	for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i+(1<<j)-1<=n;i++){
	if(a[i][j-1]>a[i+(1<<(j-1))][j-1]){
		a[i][j]=a[i+(1<<(j-1))][j-1];
		b[i][j]=b[i+(1<<(j-1))][j-1];
	}
	else {
		a[i][j]=a[i][j-1];
		b[i][j]=b[i][j-1];
	}
}
}
int query(int l,int r){
	int len=r-l+1;
	int x=log(len)/log(2);
 	if(a[l][x]>a[r-(1<<x)+1][x])return b[r-(1<<x)+1][x];
	else return b[l][x];
}
