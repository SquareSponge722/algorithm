#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int t;
int n,a[105],maxv,b[25005];
void work(int x){
	for(register int i=0;i+x<=maxv;i++){
		if(b[i]==1){
			b[i+x]=1;
		}
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(register int i=1;i<=t;i++){
		scanf("%d",&n);
		int sum=1;
		maxv=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		b[0]=1;
		for(register int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maxv=max(maxv,a[i]);
		}
		sort(a+1,a+1+n);
		work(a[1]);	
		for(register int i=1;i<=n;i++){
			if(b[a[i]]==0){
				work(a[i]);
				sum++;
			}
		}	
		printf("%d\n",sum);
	}
	return 0;
}
