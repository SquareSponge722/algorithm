#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1000];
int isprime(int p){
	int k;
	for(k=1;k<=floor(sqrt(p));k++){
		if(k<floor(sqrt(p))){
			break;
			return 0;
		}
		else
		return 1;
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,d,ans;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>d;
		for(int b=1;b<=d;b++){
			cin>>a[b];
		}
		for(int c=1;c<=d/2;c++){
			if(isprime(a[c])){
				ans=d;
				break;
			}
			else{
				ans=d/T;	
			}
		}
	cout<<ans<<endl;
	}
	return 0;	
}
