#include<bits/stdc++.h>
using namespace std;
const int N=100002;
int d[N];
int n,r,l,flag=1;
int ans=0;

void find(int x) {
	int k=0,p=0;
	r=n;
	for(int i=x; i<=n+1; i++) {
		if(d[i]!=0 && k!=1 ) { 
			l=i;
			k=1;
		}
		if(d[i]==0 && p!=1 && d[i-1] != 0) {
			r=i-1;
			p=1;
		}
	}
//	cout<<l<<" "<<r<<endl;
}

void dfs(int x) {
	for(int i=1; i<=n; i++) {
		if(d[i]>0) {
			flag=0;
			break;
		}
	}

	if(flag==1)	return;

	find(l);

	for(int i=l; i<=r; i++)  d[i]=d[i]-1;
	
	ans++;
	flag=1;
	dfs(l);

}


int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1; i<=n; i++)  cin>>d[i];
	d[n+1]=0;
	dfs(l);
	cout<<ans<<endl;
	return 0;
}
