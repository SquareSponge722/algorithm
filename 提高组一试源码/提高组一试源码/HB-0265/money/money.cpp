#include<bits/stdc++.h>
using namespace std;
const int N=105;
int T,a[N],b[N],n,m=1,stop=0;

void ck(int x){
	for (int i=m;i>=1;i--){
		if (stop) return;
		if (x%b[i]==0){
			stop = 1;
			return;
		}
		if (x-b[i]<b[1]) continue;
		ck(x-b[i]);
	}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		m = 1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		b[1] = a[1];
		for (int i=2;i<=n;i++){
			ck(a[i]);
			if (!stop){
				m++;
				b[m] = a[i];
			}
			stop = 0;
		}
		printf("%d\n",m);
	}
	return 0;
}
