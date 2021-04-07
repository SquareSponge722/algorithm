#include<bits/stdc++.h>
using namespace std;
int a[100010],cnt,ans,n;
bool op=0,vis[100010];
int f[100010],d[100010];
void read(int& x)
{
	char c=getchar();
	x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(int i=1; i<=n; i++)
	{
		read(a[i]);
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			int j=i+1;
			if(a[j]==a[i])continue;
			else
			{
				cnt++;
				while(a[j]>a[i])
				{
					d[cnt]=max(d[cnt],a[j]);
					f[cnt]=min(f[cnt],a[i]);
					vis[j]=1;
					i++;
					j++;
				}
				while(a[j]<a[i])
				{
					f[cnt]=min(f[cnt],a[j]);
					d[cnt]=max(d[cnt],a[i]);
					vis[j]=1;
					i++;
					j++;
				}
			}

		}
	}
	for(int i=1; i<=cnt; i++)
	{
		ans+=(d[i]-f[i]);
	}
	printf("%d\n",ans);
	return 0;
}

