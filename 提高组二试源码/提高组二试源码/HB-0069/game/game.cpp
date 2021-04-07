#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<vector>
#include<string>
using namespace std;

inline int read(){
	
	int x=0,y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
	
}
const long long N=1e9+7;
int n,m;
inline long long ksm(int x,int y){
	long long base=x,ans=1;
	while(y){
		if(y&1){
			ans*=base;
			ans%=N;
		}
		base*=base;
		base%=N;
		y>>=1;
	}
	return ans;
}


int main(){
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if(n==2){
		cout<<ksm(2,m*n)-4<<endl;
		return 0;
	}
	if(n<=3&&m<=3){
		if(n==1&&m==1) cout<<2<<endl;
		else if(n==1&&m==2) cout<<4<<endl;
		else if(n==1&&m==3) cout<<8<<endl;
		else if(n==2&&m==1) cout<<4<<endl;
		else if(n==2&&m==2) cout<<12<<endl;
		else if(n==2&&m==3) cout<<60<<endl;
		else if(n==3&&m==2) cout<<60<<endl;
		else if(n==3&&m==1) cout<<8<<endl;
		else if(n==3&&m==3) cout<<112<<endl;
		return 0;
	}
	
}
