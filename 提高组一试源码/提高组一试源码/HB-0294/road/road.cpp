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
//	return ans2;//���㳤�� 
}

long long maxp(long long a[],long long n){
	long long ans1 = 0;
	for(int i = 1; i <= n; i++)
		if(ans1 < a[i]){
			ans1 = a[i];
		}
	return a[n];
} 

long long n,max1 = 0,k,sum = 0;//k�Ǽ�¼������е��� 
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
			}//�ҳ���ǰ����������� 
		}
		max1 = 0;//max1���� 
		for(int i = k; i <= k+length[k]-1; i++) dis[i]--;//��ȼ�һ 
		sum++;//�������� 
	}
	printf("%lld\n",sum);
	return 0;
}
