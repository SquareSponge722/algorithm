#include <bits/stdc++.h>
#define N 101000
using namespace std;
int n,a[N],ans;
bool flag;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=-1;
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				if(a[i-1]<0)
					ans++;
			}
			a[i]--;
		}
		flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				flag=false;
				break;
			}
		}
		if(flag)
			break;
	}
	printf("%d",ans);
	return 0;
}
