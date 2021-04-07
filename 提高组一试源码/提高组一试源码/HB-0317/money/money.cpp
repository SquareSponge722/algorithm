#include<cstdio>
#define N 105
using namespace std;
int t,n,a[N],ans;
int ok[25005];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",t);
	while(t--){
		scanf("%d",n);
		ans=n;
		for(int i=1;i<=n;i++){
			scanf("%d",a[i]);
			for(int j=1;j<=25000;j++){
				if(j%a[i]) ok[i]=1;
			}
			if(ok[a[i]]) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
