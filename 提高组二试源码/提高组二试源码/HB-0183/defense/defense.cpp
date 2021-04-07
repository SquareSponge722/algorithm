#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,sum1,sum2,cost;
bool flag1,flag2;
string s;

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>cost;
		if(i%2==0) sum2+=cost;//ou
		if(i%2==1) sum1+=cost;//ji
	}
	for(int i=1,u,v;i<=n-1;i++)
		cin>>u>>v;
	for(int i=1,a,x,b,y;i<=m;i++){
		cin>>a>>x>>b>>y;
		if(x==1&&a%2==0) flag1=true;//ou
		if(x==0&&a%2==0) flag2=true;//ji
		if(x==1&&a%2==1) flag2=true;
		if(x==0&&a%2==1) flag1=true;
		if(flag1==true){
				if(b%2==0&&y==1) printf("%d\n",sum2);
				if(b%2==0&&y==0) puts("-1");
				if(b%2==1&&y==1) puts("-1");
				if(b%2==1&&y==0) printf("%d\n",sum2);
		}
		
		else if(flag2==true){
			if(b%2==1&&y==1) printf("%d\n",sum1);
			if(b%2==1&&y==0) puts("-1");
			if(b%2==0&&y==1) puts("-1");
			if(b%2==0&&y==0) printf("%d\n",sum1);
		}
	}
	return 0;
}
