#include<cstdio>

using namespace std;

const int maxn=100005;

int n;
int a[maxn];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans,maxh;
	scanf("%d",&n);
	maxh=0;ans=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(maxh<a[i]) ans+=a[i]-maxh;
		maxh=a[i];
	}
	printf("%d",ans);
	return 0;
}
