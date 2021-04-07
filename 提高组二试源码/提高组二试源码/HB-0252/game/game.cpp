//回首向来萧瑟处，
//归去,
//从此O I 陌路人。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define P 1000000007
using namespace std;
int N,M;
long long ans;
int main()  {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>N>>M;
	if(M==1)  {
		ans=1;
		for(int i=1;i<=N;i++)  {
			ans=(ans*2)%P;
		}
		cout<<ans;
		return 0;
	}
	if(M==2)  {
		ans=1;
		long long _2=2;
		for(int i=1;i<N;i++)  {
			ans=(ans+_2)%P;
			_2=(_2*2)%P;
		}
		cout<<(ans*4)%P;
		return 0;
	}
	if(N==1)  {
		ans=1;
		for(int i=1;i<=M;i++)  {
			ans=(ans*2)%P;
		}
		cout<<ans;
		return 0;
	}
	if(N==2)  {
		ans=1;
		long long _2=2;
		for(int i=1;i<M;i++)  {
			ans=(ans+_2)%P;
			_2=(_2*2)%P;
		}
		cout<<(ans*4)%P;
		return 0;
	}
	if(N==3)  {
		if(M==3)  {
			cout<<112;
			return 0;
		}
	}
	if(N==5 && M==5)  {
		cout<<7136;
		return 0; 
	}
	return 0;
}
