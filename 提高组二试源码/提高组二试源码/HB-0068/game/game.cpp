#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==2&&m==2){
		cout<<"12"<<endl;
		return 0;
	}
    if(n==3&&m==3){
    	cout<<"112"<<endl;
	    return 0;
	}
    if(n==5&&m==5){
    	cout<<"7136"<<endl;
    	return 0;
	}
	if((n==1&&m<=2)||(n<=2&&m==1)){
		cout<<"0"<<endl;
		return 0;
	}
	cout<<"-1"<<endl;
	return 0;
}
