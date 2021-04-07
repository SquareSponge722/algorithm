#include<bits/stdc++.h>
using namespace std;
const int inf=100000;
int t,n,ans,maxn;
int a[105];
int num[105];
int b[30000];
bool check(int o){
	if(b[o]!=-1) return b[o];
	for(int i=1;i<=ans;i++){
		if(o%num[i]==0) return b[o]=1;
		else {
			for(int j=1;j<=ans;j++){
				if(o>num[j]){
					if(check(o-num[j])) return b[o]=1;
				}
				else break;
			}
		}
	}
	return 0;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		memset(b,-1,sizeof(b));
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		if(a[1]==1&&n==1){
			printf("1\n");
			continue;
		}
		ans=1;
		num[ans]=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]%a[1]!=0) {
				maxn=a[1]*a[i]-a[1]-a[i];
				if(maxn<a[i]) maxn=a[i];
				break;
			}
		}
		for(int i=2;i<=n;i++){
			if(a[i]>maxn) break;
			if(!check(a[i])){
				num[++ans]=a[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
