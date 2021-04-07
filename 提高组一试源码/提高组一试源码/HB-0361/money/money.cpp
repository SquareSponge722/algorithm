//I HAVE TRY MY BEST TO GET MORE SCORES
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T,n;

int main() {
freopen("money.in","r",stdin);
freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		int a[107];
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		if(n==2) {
			if(a[1]%a[2]==0||a[2]%a[1]==0)printf("%d",1);
			else printf("%d",2);
		}
		if(n==3) {
			bool flag=true;
			sort(a,a+3);
			int a1=0,a2=0;
			for(int i=0; a1+a2<=a[3]; i++) {
				for(int j=0; a1+a2<=a[3]; i++) {

					if(a1+a2==a[3]) {
						printf("%d",2);
						flag=false;
						break;
					}
					a2+=a[2];
				}
				a1+=a[1];
			}
			if(flag)printf("%d",3);
		}
		if(n==4) {
			sort(a,a+4);
			if(a[2]%a[1]) {
			int flag3;
				int a1=0,a2=0;
				for(int i=0; a1+a2<=n; i++) {
					for(int j=0; a1+a2<=n; i++) {
						if(a1+a2==a[3]) {
							flag3=false;
							break;
						}
						a2+=a[2];
					}
					if(!flag3)break;
					a1+=a[1];
				}
				int flag4;
				 a1=0,a2=0;
				for(int i=0; a1+a2<=n; i++) {
					for(int j=0; a1+a2<=n; i++) {
						if(a1+a2==a[4]) {
							flag4=false;
							break;
						}
						a2+=a[2];
					}
					if(!flag4)break;
					a1+=a[1];
				}
				if(flag4&&flag3)printf("%d",4);
				else if((flag4&&(!flag3))||(!flag4)&&flag3)printf("%d",3);
				else if((!flag3)||(!flag4))printf("%d",2);
			}
			 else {
				int flag4;
				int a1=0,a3=0;
				for(int i=0; a1+a3<=n; i++) {
					for(int j=0; a1+a3<=n; i++) {
						if(a1+a3==a[4]) {
							flag4=false;
							break;
						}
						a3+=a[3];
					}
					if(!flag4)break;
					a1+=a[1];
				}
				if(flag4)printf("%d",2);
				else printf("%d",3);
			}
		}
	}
	return 0;
}
