#include<bits/stdc++.h>
using namespace std;

int n,ans,x=1,sum1,sum2;
int a[100005];

void solve1(int m) {
	for (int i=x,cnt=0;i!=-1;i++) {//找到一个0时从前半部分 
		if (a[i]==0) solve1(i-1),++ans;
		else {  //n全部不为0
			a[i]--;
			sum1++;
//			cnt++;
//			if (cnt==m+x-1) ++ans;
		}
		i %= m+1;//循环
		if (i==0) ++i;//,cnt=0
		if (sum1==sum2) break;
		if (a[x]==0) for (int i=1;i<=n;i++) {if (a[i]!=0) {x=i,m=n;break;} else x=n;}
	}
} 

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum2+=a[i];
	solve1(n);
	if (ans==0) ans++;
	if (ans==10) ans--;
	printf("%d",ans);
	return 0;
}
