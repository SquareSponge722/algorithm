#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=105;
const int maxa=25005;

int T;
int n,cnt;
int a[maxn],b[maxn];
bool f[25005];

bool check(int x) {
	memset(f,0,sizeof f);
	f[0]=1;
	for(int i=1;i<=cnt;i++) {
		for(int j=b[i];j<=x;j++) {
			f[j]|=f[j-b[i]];
		}
	}
	if(f[x]) return true;
	return false;
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			if(!check(a[i])) b[++cnt]=a[i];
		}
		printf("%d\n",cnt);
	}
	return 0;
}
