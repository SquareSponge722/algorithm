#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[101],ans;
int cnt[10];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n==2) {
			for(int i=1; i<=n; i++) scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			if(a[2]%a[1]!=0) printf("2\n");
			else printf("1\n");
		}
		if(n==3) {
			ans=3;
			for(int i=1; i<=3; i++) scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[2]*k)*2>a[3]) break;
					if(a[3]%(a[1]*j+a[2]*k)==0) pd=1,cnt[3]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			if(a[3]%a[1]==0) cnt[3]=1;
			if(a[3]%a[2]==0) cnt[3]=1;
			if(a[2]%a[1]==0) cnt[2]=1;
			for(int i=1; i<=n; i++) if(cnt[i]==1) ans--;
			printf("%d\n",ans);
			ans=0;
			for(int i=1; i<=n; i++) cnt[i]=0;
		}
		if(n==4) {
			ans=4;
			for(int i=1; i<=4; i++) scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[2]*k)*2>a[3]) break;
					if(a[3]%(a[1]*j+a[2]*k)==0) pd=1,cnt[3]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[2]*k)*2>a[4]) break;
					if(a[4]%(a[1]*j+a[2]*k)==0) pd=1,cnt[4]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[3]*k)*2>a[4]) break;
					if(a[4]%(a[1]*j+a[3]*k)==0) pd=1,cnt[4]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[2]*j+a[3]*k)*2>a[4]) break;
					if(a[4]%(a[2]*j+a[3]*k)==0) pd=1,cnt[4]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			if(a[4]%a[1]==0) cnt[4]=1;
			if(a[4]%a[2]==0) cnt[4]=1;
			if(a[4]%a[3]==0) cnt[4]=1;
			if(a[3]%a[1]==0) cnt[3]=1;
			if(a[3]%a[2]==0) cnt[3]=1;
			if(a[2]%a[1]==0) cnt[2]=1;
			for(int i=1; i<=4; i++) if(cnt[i]==1) ans--;
			
			printf("%d\n",ans);
			ans=0;
			for(int i=1; i<=n; i++) cnt[i]=0;
		}
		if(n==5) {
			ans=5;
			for(int i=1; i<=5; i++) scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[2]*k)*2>a[3]) break;
					if(a[3]%(a[1]*j+a[2]*k)==0) pd=1,cnt[3]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			//4
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[2]*k)*2>a[4]) break;
					if(a[4]%(a[1]*j+a[2]*k)==0) pd=1,cnt[4]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[3]*k)*2>a[4]) break;
					if(a[4]%(a[1]*j+a[3]*k)==0) pd=1,cnt[4]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[2]*j+a[3]*k)*2>a[4]) break;
					if(a[4]%(a[2]*j+a[3]*k)==0) pd=1,cnt[4]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			//5
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[2]*k)*2>a[5]) break;
					if(a[5]%(a[1]*j+a[2]*k)==0) pd=1,cnt[5]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[3]*k)*2>a[5]) break;
					if(a[5]%(a[1]*j+a[3]*k)==0) pd=1,cnt[5]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[1]*j+a[4]*k)*2>a[5]) break;
					if(a[5]%(a[1]*j+a[4]*k)==0) pd=1,cnt[5]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[2]*j+a[3]*k)*2>a[5]) break;
					if(a[5]%(a[2]*j+a[3]*k)==0) pd=1,cnt[5]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[2]*j+a[4]*k)*2>a[5]) break;
					if(a[5]%(a[2]*j+a[3]*k)==0) pd=1,cnt[5]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			for(int j=1; j<=1000; j++) {
				int pd=0;
				for(int k=1; k<=1000; k++) {
					if((a[3]*j+a[4]*k)*2>a[5]) break;
					if(a[5]%(a[3]*j+a[4]*k)==0) pd=1,cnt[5]=1;
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			if(a[5]%a[1]==0) cnt[5]=1;
			if(a[5]%a[2]==0) cnt[5]=1;
			if(a[5]%a[3]==0) cnt[5]=1;
			if(a[5]%a[4]==0) cnt[5]=1;
			if(a[4]%a[1]==0) cnt[4]=1;
			if(a[4]%a[2]==0) cnt[4]=1;
			if(a[4]%a[3]==0) cnt[4]=1;
			if(a[3]%a[1]==0) cnt[3]=1;
			if(a[3]%a[2]==0) cnt[3]=1;
			if(a[2]%a[1]==0) cnt[2]=1;
			for(int i=1; i<=5; i++) if(cnt[i]==1) ans--;
			printf("%d\n",ans);
			ans=0;
			for(int i=1; i<=n; i++) cnt[i]=0;
		}
	}
	return 0;
}
/*
1
4
3 19 10 6

2
2
2 3
3
2 5 9

*/
