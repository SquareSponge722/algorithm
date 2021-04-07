#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int T,n,tot,a[maxn],now1,now2;
bool ok;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(n==2){
			if(a[1]%a[2]==0||a[2]%a[1]==0){
				printf("1\n");
				continue;
			}
			else {
				printf("2\n");
				continue;
			}
		}
		if(n==3){
			sort(a+1,a+1+n);
			tot=3;
			if(a[2]%a[1]==0){
				if(a[3]%a[1]==0){
					printf("1\n");
					continue;
				}
				else {
					printf("2\n");
					continue;
				}
			}
			else {
				now1=0;
				now2=0;
				ok=0;
				while(now1<=a[3]){
					now2=now1;
					while(now2<=a[3]){
						if(a[3]==now2){
							printf("2\n");
							ok=1;
							break;
						}
						now2+=a[2];
					}
					if(ok)break;
					now1+=a[1];
				}
				if(ok)continue;
				printf("3\n");
				continue;
			}
		}
		printf("%d\n",n);
	}
}
