#include<bits/stdc++.h>
using namespace std;
int n,m,fa,son,a[100001],a1,x,b1,y;
long long f[100001][2];
char type[3];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&type);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)scanf("%d%d",&fa,&son);	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a1,&x,&b1,&y);
		f[1][1]=a[1];f[1][0]=a[2];
		if(x==1)f[a1][0]=2147483647;
		else f[a1][1]=f[a1-1][0]=2147483647;
		if(y==1)f[b1][0]=2147483647;
		else f[b1][1]=f[b1-1][0]=2147483647;
		for(int j=1;j<=n-1;j++)
		{
			f[j][1]=min(f[j-1][0],f[j-1][1]+a[j]);
			f[j][0]=min(f[j-1][1],f[j-1][0])+a[j+1];
		}
		long long ans=min(f[n-1][0],f[n-1][1]);
		if(ans>=2100000000)printf("-1\n");
		else printf("%lld",ans);
	}
	return 0;
}
