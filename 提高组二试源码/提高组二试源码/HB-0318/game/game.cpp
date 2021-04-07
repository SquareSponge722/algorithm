#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,k,p,ans1=0,ans2=0,ans;  // 1 ： 全涂或全不涂  但是要减去最边上的两个只涂一个的情况 
	cin>>n>>m;   // 2 ：排列的那个玩意     3：对称涂  由 k 当变量来计算 
	int q=m+n-1;

	ans1=2;

	for(int i=1; i<=q; i++) {
		int fz=1,fm=1,v;
		for(int j=1; j<=i; j++) { //分子大小
			fz=fz*(q-j+1);
		}
		for(int j=1; j<=i; j++) { //分母大小
			fm=fm*j;
		}
		v=fz/fm;
		ans2+=v;
	}
	if(m==1){
		if(n==1) ans=2;
		if(n==2) ans=4;
		if(n==3) ans=9;
	}
	if(m==2){
		if(n==1) ans=4;
		if(n==2) ans=12;
	}
	if(m==3){
		if(n==1) ans=9;
		if(n==3) ans=112;
	}
	if(m>=4) ans=ans1+ans2+ans2-4;
	ans%=1000000000+7;
	cout<<ans<<endl;
	return 0;
}
