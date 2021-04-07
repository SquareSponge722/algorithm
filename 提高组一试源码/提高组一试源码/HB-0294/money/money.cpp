#include<bits/stdc++.h>
using namespace std;
long long t,p;//p是最大无法组成的数 
long long a[110];
bool b[110];
int main(){
	freopen("money.in","r",stdin); 
	freopen("money.out","w",stdout); 
	scanf("%d",&t);
	for(int l = 1; l <= t; l++){
		long long n,k;
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		long long ans = n;
		for(int i = 1; i <= n; i++)
			 scanf("%d",&a[i]);
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				printf("1");
				return 0;
			}
		}
		sort(a+1,a+n+1);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++){
				if(a[j]%a[i] == 0 && b[j] == 0)
				{
					ans--;
					b[j] = 1;
				}
			}//此处为剔除掉所有重复的数(或某个数的倍数) 
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				for(int k = j + 1; k <= n; k++){
					if((a[k]%a[j])%a[i] == 0 && b[k] == 0){
						ans--;
						b[k] = 1;
					}
				}
		printf("%d\n",ans--);
	}
	return 0;
}
