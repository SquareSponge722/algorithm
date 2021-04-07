#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
inline int read()
{
	register int a(0),p(1);register char ch=getchar();
	while((ch<'0'&&ch>'9')&&ch!='-') ch=getchar();
	ch=='-'?p=-1,ch=getchar():p;
	while(ch>='0'&&ch<='9') a=a*10+ch-48,ch=getchar();
	return a*p;
}
const int N=100100;
int n,a[N],maxn=0,minn=0x3f3f3f3f,temp(0),all(0),sad(0),book[N],vis[N],xx;
inline int maax(int x,int y){return x<y?y:x;}
inline int miix(int x,int y){return x<y?x:y;}
vector<int> happy[10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
	{
		a[i]=read();
		happy[a[i]].push_back(i);
		maxn=maax(maxn,a[i]);minn=miix(minn,a[i]);
	}
	if(n<=1000)
	{
		for(register int i=maxn;i>=minn;--i)
		{
			temp=0;
			for(register int j=1;j<=n;++j)
			{
				if(a[j]<i) 
				{
					if(temp)all++;
					temp=0;
				}
				else temp=1;
			}
			if(temp) all++;
		}
		printf("%d\n",all+minn-1);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<maxn) 
			{
				if(temp)sad++;
				temp=0;
			}
			else temp=1;
		}
		if(temp)sad++;
		all+=sad;
		// printf("%d\n",sad);
		for(register int i=maxn-1;i>=minn;--i)
		{
			for(register int j=0;j<happy[i].size();++j)
			{
				xx=happy[i][j];
				if(a[xx]>a[xx-1]&&a[xx]>a[xx+1]) sad++;
				else if(a[xx]>a[xx+1]&&a[xx]==a[xx-1]&&vis[xx-1]) sad++;
				else if(a[xx]==a[xx+1]&&a[xx]>a[xx-1]) vis[xx]=1;
				else if(a[xx]==a[xx+1]&&a[xx]==a[xx-1]) vis[xx]=vis[xx-1];

				if(a[xx]<a[xx+1]&&a[xx]<a[xx-1]) sad--;
				else if(a[xx]<a[xx+1]&&a[xx]==a[xx-1]&&book[xx-1]) sad--;
				else if(a[xx]==a[xx+1]&&a[xx]<a[xx-1]) book[xx]=1;
				else if(a[xx]==a[xx+1]&&a[xx]==a[xx-1]) book[xx]=book[xx-1];
			}
			all+=sad;
			// printf("%d\n",sad);
		}
		printf("%d\n",all+minn-1);
	}
	return 0;
}
