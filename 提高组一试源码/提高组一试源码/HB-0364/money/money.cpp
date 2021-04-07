#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		scanf("%d",&n);
		for (int j=1;j<=n;j++) scanf("%d",&a[j]);
		printf("%d\n",a[n]/a[1]);
	}
	return 0;
}
