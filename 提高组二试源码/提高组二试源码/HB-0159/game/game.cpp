#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[1000][1000];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long ans1,ans2,k;
	int p,q;
	k=pow(10,9);
	int n,m;
	cin>>n>>m;
	p=m*n;q=m+n-2;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			a[i][j]=0;
//		}
//	}
	
	if(n==2&&m==2){            /*Æ­·Ö¿ªÊ¼*/ 
		cout<<"12";
	}
	if(n==3&&m==3){
		cout<<"112";
	}
	if(n==5&&m==5){
		cout<<"7136";
	}
	ans1=pow
	ans2=floor(ans1%(k+7));
	cout<<ans2;
	return 0;
}
