#include <cstdio>

using namespace std;

const int maxn=100001;
int n,a[maxn];

int zmin(int a,int b) {
	if(a<=b) return a;
	else return b;
}

int main() {
	int minv=1e9,ans=0;
	bool finish=true;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		minv=zmin(a[i],minv);
	}
	for(int i=1; i<=n; i++) a[i]-=minv;
	ans+=minv;
	do {
		bool fir=true;
		finish=true;
		int l=1,r=n;
		for(int i=1; i<=n; i++) {
			if(!(fir&&a[i]==0)) {
				if(fir) l=i;
				fir=false;
			}
			if(!fir&&a[i]==0) {
				r=i-1;
				break;
			} 
		}
		minv=1e9;
		for(int i=l; i<=r; i++) minv=zmin(a[i],minv);
		for(int i=l; i<=r; i++) a[i]-=minv;
		ans+=minv;
		for(int i=1; i<=n; i++) {
			int j=n-i+1;
			if(a[i]!=0||a[j]!=0) {
				finish=false;
				break;
			}
		}
	} while(!finish);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
