#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch;
	int f=1;
	int num=0;
	ch=getchar();
	if(ch=='-'){
		f=-1;
		ch='0';
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}
int n,m;
long long ans=1;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<min(m,n);i++){
		ans*=i+1;
		ans%=1000000007;
	}
	ans*=ans;
	ans%=1000000007;
	for(int i=0;i<=max(m,n)-min(m,n);i++){
		ans*=min(m,n)+1;
		ans%=1000000007;
	}
	cout<<ans;
	return 0;
}
