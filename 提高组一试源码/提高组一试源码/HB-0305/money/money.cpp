#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],f[50006],b[105],g[50006],f2[50006],cnt;
bool check(int x) {
	memset(f2,0,sizeof(f2));
	f2[0]=1;
	int tot=0;
	for(int i=1; i<=cnt; i++) {
		if(f2[g[i]]==1) continue;
		b[++tot]=g[i];
		for(int j=b[tot]; j<=25005; j++) {
			f2[j]=max(f2[j],f2[j-b[tot]]);
		}
	}
	if(tot>x) return false;
	for(int i=1; i<=25005; i++) {
		if(f2[i]!=f[i]) return false;
	}
	return true;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		f[0]=1;
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		for(int i=1; i<=n; i++)
			for(int j=a[i]; j<=25005; j++) {
				f[j]=max(f[j],f[j-a[i]]);
			}
		cnt=0;
		for(int i=1; i<=25005; i++) {
			if(f[i]==1) {
				cnt++;
				g[cnt]=i;
			}
		}
		int l=1,r=cnt;
		while(l<r) {
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}
