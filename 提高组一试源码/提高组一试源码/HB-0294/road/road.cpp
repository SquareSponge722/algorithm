#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

long long downp(long long k,long long dis[],long long n){
	long long ans = 0;
	for(int i = k; i <= n; i++){
		if(dis[i] != 0) ans++;
		else break;
	}
	return ans;
//	return ans2;//计算长度 
}

long long maxp(long long a[],long long n){
	long long ans1 = 0;
	for(int i = 1; i <= n; i++)
		if(ans1 < a[i]){
			ans1 = a[i];
		}
	return a[n];
} 

long long n,max1 = 0,k,sum = 0;//k是记录最大序列的首 
long long dis[10];
long long length[10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n; i++) scanf("%lld",&dis[i]);
	while(maxp(dis,n)){
		for(int i = 1; i <= n; i++){
			length[i] = downp(i,dis,n);
			if(max1 < length[i]){
				max1 = length[i];
				k = i; 
			}//找出当前最大连续数列 
		}
		max1 = 0;//max1归零 
		for(int i = k; i <= k+length[k]-1; i++) dis[i]--;//深度减一 
		sum++;//操作次数 
	}
	printf("%lld\n",sum);
	return 0;
}
