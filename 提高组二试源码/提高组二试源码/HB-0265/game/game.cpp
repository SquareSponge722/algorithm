#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long ans;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans = int(pow(2,n+m)*(rand()+1)/2.0)%1000000007;
	cout<<ans<<endl;
	return 0;
}
