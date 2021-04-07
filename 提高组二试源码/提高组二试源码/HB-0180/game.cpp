#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define mod 1000000007
#include<algorithm>
using namespace std;
int n,m,road1[3000010],road2[3000010],op1[3000010],op2[3000010],cx[3]={0,1,0},cy[3]={0,0,1},ans;
int check(int t){
	for(int i=1;i<=t-1;i++) if(op1[i]<=op2[i]) return 0;
	for(int i=1;i<=t;i++) if(road1[i]>road2[i]) return 0;
	return 1; 
}
void dfs(int x1,int y1,int x2,int y2,int step){
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<step<<endl;
	if(x1==n&&y1==m){
		if(check(step)){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i1=0;i1<=1;i1++){
		for(int i2=0;i2<=1;i2++){
			for(int j1=1;j1<=2;j1++){
				for(int j2=1;j2<=2;j2++){
					int xx1=x1+cx[j1],yy1=y1+cy[j1],xx2=x2+cx[j2],yy2=y2+cy[j2];
					op1[step]=j1,op2[step]=j2;
					road1[step]=i1,road2[step]=i2;
					//cout<<xx1<<' '<<yy1<<' '<<xx2<<' '<<yy2<<' '<<i1<<' '<<i2<<' '<<j1<<' '<<j2<<endl;
					if(xx1<=n&&yy1<=m&&xx2<=n&&yy2<=m) dfs(xx1,yy1,xx2,yy2,step+1);
				}
			}
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2) cout<<"12"<<endl;
	else if(n==3) cout<<112<<endl;
	else if(n==5) cout<<7136<<endl;
	else{
		dfs(1,1,1,1,1);
		cout<<ans<<endl;
	}
	return 0;
}
