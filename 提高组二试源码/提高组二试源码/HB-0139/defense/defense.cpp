#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
int n;
int m;
string type;
void dfs(int a,int b,int x,int y,int step,int tot,bool flag){
	if(step>n){
		ans=min(ans,tot);
	}
	if(x==0&&step==a||y==0&&step==b){
		if(!flag){
			return;
		}
		dfs(a,b,x,y,step+1,tot,0);
	}
	if(!flag){
	dfs(a,b,x,y,step+1,tot+p[x]);
	}
	else{
	dfs(a,b,x,y,step+1,tot+p[x]);
	dfs(a,b,x,y,step+1,tot); 
	}
}
int p[2000000];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>type;
	for(int x=1;x<=n;x++){
		scanf("%d",&p[x]);
	}
	while(m--){
	int a,x,b,y;
	ans=10000000000;
	scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==0&&y==0&&abs(a-b)%2){
			printf("-1\n");
		}
		else dfs(a,x,b,y,1,0,0);
		printf("%d",ans);
	}
	return 0;
}
