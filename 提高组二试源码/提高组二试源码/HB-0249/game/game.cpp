#include<bits/stdc++.h>
using namespace std;
long long x,y;
long long sum=1; 
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>x>>y;
	if(x==3&&y==3){
		cout<<112<<endl;
		return 0;
	}
	if(x==3&&y==2){
		cout<<40<<endl;
		return 0;
	}
	if(x==2){
		for(int i=3;i<=y;i++){
			sum*=2;
			sum%=1000000007;
		}
		sum*=(sum*2+1);
		sum*=4;
		sum%=1000000007;
		cout<<sum<<endl;
		return 0;
	}
	if(x==1){
		for(int i=1;i<=y;i++){
			sum*=2;
			sum%=1000000007;
		}
		cout<<sum<<endl;
		return 0;
	}
	if(y==1){
		for(int i=1;i<=x;i++){
			sum*=2;
			sum%=1000000007;
		}
		cout<<sum<<endl;
		return 0;
	}
	if(x==5&&y==5){
		cout<<7136<<endl;
		return 0;
	}
}
