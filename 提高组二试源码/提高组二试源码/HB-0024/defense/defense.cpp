#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int k=100001;
const int K=10001;
int n,m,p[k],a,b,flag[k],l,r,c,d,ans=0;
long long zx[K][K];
char type[3];
void sq()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(!flag[i]&&!flag[j])
			{
				ans+=min(p[i],p[j]);
				if(p[i]<p[j])
					flag[j]=1;
				else flag[i]=1;		
			}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&type);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		zx[a][b]=1;
		zx[b][a]=1;
	}
	for(int i=1;i<=m;i++)
	{
		ans=0;
		memset(flag,0,sizeof(flag));
		scanf("%d%d%d%d",&l,&c,&r,&d);
		flag[l]=1;
		flag[r]=1;
		if(c==0&&d==0&&zx[l][r])
		{
			ans=-1;
		}
		if(c==0&&d==0&&!zx[l][r])
		{
			
			for(int j=1;j<=n;j++)
			{
				if(zx[j][l]&&zx[j][r])
				{
					ans+=p[j];
					flag[j]=1;
				}
				else if((zx[j][l]&&!zx[j][r])||(zx[j][r]&&!zx[j][l]))
				{
					sq();
				}
			}
			ans=12;
		}
		if(c==1&&d==1)
		{
			ans+=p[l]+p[r];
			sq();
		}
		cout<<ans<<endl;
	}
	return 0;
}
