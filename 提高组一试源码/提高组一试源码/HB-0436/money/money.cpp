#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int t,sum;
int n,a[110];
int dp[110],p;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=2;i<=n;++i){
			int g=a[i]/a[1]+1;
			for(int j=1;j<i;++j){
				for(int l=0;l<=g;l++){
					if(a[j]!=-1){
						dp[l]+=dp[l]+a[j]*l;
						if(dp[l]==a[i]){
							a[i]=-1;
							p=1;
							break;
						}
					}
				}
				if(p){
					p=0;
					for(int l=1;l<=n;++l) dp[l]=0;
					break;
				}
			}
		}
		for(int i=1;i<=n;++i){
			if(a[i]!=-1) sum++;
		}
		printf("%d\n",sum==n?n:sum-1);
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
