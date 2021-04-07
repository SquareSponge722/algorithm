#include<bits/stdc++.h>
using namespace std;
const int maxn=106;
int T,n,a[maxn],bug,flag;
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			if(a[i]==1) cout<<"1"<<endl,bug=1;
		}
		sort(a,a+n+1);

		if((!bug)&&n==2) {
			for(int i=1; i<=n; i++)
				if(a[2]%a[1]==0) cout<<"1"<<endl;
				else cout<<"2"<<endl;
		}

		if((!bug)&&n==3) {
			int ll=0;
			flag=3;
			if(!a[2]%a[1]) flag-=1;
			if(!a[3]%a[1]) flag-=1;
			if( flag==3 && (!a[3]%a[2]) ) flag-=1;
			for(int i=1; i<=500; i++)
				for(int j=1; j<=500; j++)
					if( flag==3 && i*a[1]+j*a[2]==a[3] ) ll=1;
			if(ll) flag-=1;
			cout<<flag<<endl;
		}

		if((!bug)&&n==4) {
			int ll=0;
			flag=4;
			for(int i=2; i<=4; i++) {
				if(!a[i]%a[1]) flag-=1,a[i]==0;
			}
			if(flag==3 && !a[3]%a[2]&&!a[4]) flag-=1,a[3]=0;
			if(flag==3 && !a[4]%a[2]&&!a[3]) flag-=1,a[4]=0;
			if(flag==3 && !a[4]%a[3]&&!a[2]) flag-=1,a[4]=0;
			if(flag==4) {
				if(!a[4]%a[2])flag-=1,a[4]=0;
				if(!a[4]%a[3])flag-=1,a[4]=0;
			}
			if( flag==4)	{
				for(int i=0; i<=100; i++)
					for(int j=0; j<=100; j++)
						for(int r=0; j<=100; j++) {
							if(i*a[1]+j*a[2]+r*a[3]==a[4]) ll=1;
						}
				if(flag==3) {
					if(!a[3]) {
						for(int i=1; i<=500; i++)
							for(int j=1; j<=500; j++)
								if( i*a[1]+j*a[2]==a[4] ) ll=1;
					}
					if(!a[4]) {
						for(int i=1; i<=500; i++)
							for(int j=1; j<=500; j++)
								if( i*a[1]+j*a[2]==a[3] ) ll=1;
					}
				}

				if(ll) flag-=1;


				cout<<flag-2<<endl;
			}

			if((!bug)&&n>4) cout<<n/2<<endl;
		}
		
	}
	return 0;
}
