#include<bits/stdc++.h>
#define inf 0x3f3f3f
using namespace std;
int n,d[100004],d0[100004],ans=0,ncomple;
bool comple[100004];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)scanf("%d",&d0[i]);
	for(int i=1; i<=n; i++)d[i]=d0[i];
	int p=1;
	for(;;) {
		while(d[p]==0&&p<=n) {
			if(!comple[p])ncomple++,comple[p]=1;
			p++;
		}
		if(ncomple==n){
			cout<<ans<<endl;
			return 0;
		}
		int st=p,ed=0,mindlr=inf;

		while(d[p]) {
			mindlr=min(mindlr,d[p]);
			p++;
		}
//		cout<<p<<endl;
		ed=p-1;
//		cout<<st<<" "<<ed<<" "<<mindlr<<"sted"<<endl;
		if(st>ed) {
			p=1;
			continue;
		}
//		for(int i=1; i<=n; i++)cout<<d[i]<<" ";
//		cout<<endl;

		ans+=mindlr;
//		cout<<ans<<"ans\n";
		for(int i=st; i<=ed; i++) {
			d[i]-=mindlr;
//			cout<<d[i]<<"d\n";
			if(d[i]==0&&(!comple[i]))comple[i]=1,ncomple++;
		}

		//	int cmp=1;for(int i=1;i<=n;i++)if(d[i])cmp=0;
		if(p>n)p=1;
//		cout<<ncomple<<"ncmp"<<endl;
		if(ncomple==n) {
			cout<<ans;
			return 0;
		}

	}
}
