# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;
# define N 100005
long long f[N];//表示到第i个数时需要的最少天数； 
long long a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<=a[i-1]){
			f[i]=f[i-1];
		}
		else{
			f[i]=f[i-1]+a[i]-a[i-1];
		}
	}
	printf("%lld",f[n]);
	return 0;
}
