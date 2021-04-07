#include<bits/stdc++.h>
using namespace std;
int m,n,a,b,x,y,a1,b1;
string t;
int sum=2147483647;
int v[100005];
bool pd[100005];
void yy(int now,int sum1){
	if(now==a){
		if(x==1){
			yy(now+1,sum1+v[now]);
			return;
		}
		if(x==0){
			yy(now+2,sum1+v[now+1]);
			return;
		}
	}
	if(now+1==a){
		if(x==1){
			yy(now+2,sum1+v[now+1]);
			return;
		}
		if(x==0){
			yy(now+1,sum1+v[now]);
			return;
		}
	}
	if(now==b){
		if(y==1){
			yy(now+1,sum1+v[now]);
			return;
		}
		if(y==0){
			yy(now+2,sum1+v[now+1]);
			return;
		}
	}
	if(now+1==b){
		if(y==1){
			yy(now+2,sum1+v[now+1]);
			return;
		}
		if(y==0){
			yy(now+1,sum1+v[now]);
			return;
		}
	}
	if(now>=n) {
		sum=min(sum,sum1);
		return;
	}
	yy(now+1,sum1+v[now]);
	yy(now+2,sum1+v[now+1]);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>t;
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a1,&x,&b1,&y);
		if(a==b+1&&x==0&&y==0) {
			printf("-1\n");
			continue;
		}
		if(b==a+1&&x==0&&y==0) {
			printf("-1\n");
			continue;
		}
		if(a==b&&x!=y){
			printf("-1\n");
			continue;
		}
		sum=2147482647;
		yy(1,0);
		cout<<sum<<endl;
	}
}
