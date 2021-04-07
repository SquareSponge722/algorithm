#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
struct def
{
	int x,y;
}e[100005];
bool cmp(def A,def B)
{
	return A.x < B.x;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&e[i].x);
		scanf("%d",&e[i].y);
	}
	sort(e+1,e+n,cmp);
	while(m--)
	{
		int A,x,B,y;
		scanf("%d%d%d%d",&A,&x,&B,&y);
		if(A%2!=B%2&&x==y)
		{
			printf("-1\n");
			continue;
		}
		int ans1=0;
		for(int i=1;i<=n;i+=2) ans1+=a[i];
		int ans2=0;
		for(int i=2;i<=n;i+=2) ans2+=a[i];
		if(x==y)
		{
			printf("%d\n",min(ans1,ans2));
			continue;
		}
		int ans=1e9;
		if(A%2==1&&x) ans=min(ans,ans1);
		if(B%2==1&&y) ans=min(ans,ans1); //有奇数 
		if(A%2==0&&x) ans=min(ans,ans2);
		if(B%2==0&&y) ans=min(ans,ans2); //有偶数 
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
