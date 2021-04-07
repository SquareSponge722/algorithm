#include <bits/stdc++.h>
using namespace std;
long long read() {
	long long x=0;
	char s=getchar();
	int f=1;
	while(s<'0'||s>'9') {
		if(s=='-')
			f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9') {
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}
long long a[100005];
bool ifzero[100005];
int n;
long long ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1; i<=100003; i++)
		ifzero[i]=1;
	for(int i=1; i<=n; i++) {
		a[i]=read();
		if(a[i])
		ifzero[i]=0;
	}
	int b=1;
	while(b<=5000000) {
		int j=1;
		while (ifzero[j]==1)
			j++;
		//	cout<<j<<' ';
		int m=j;
		long long minn=998244353;
		while(!ifzero[j]) {
			minn=min(a[j],minn);
			j++;
		}
//		cout<<j<<' '<<minn;
		int k=m;
		while(k<j) {
			a[k]-=minn;
			//	k++;
			if(a[k]==0)
			ifzero[k]=1;
			k++;
		}
		ans+=minn;
		//	cout<<minn<<" ";
		bool ok=1;
		for(int p=n; p>=1; p--)
			if(a[p]!=0)
			{
			ok=0;
			break;
			}
		if(ok) {
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
