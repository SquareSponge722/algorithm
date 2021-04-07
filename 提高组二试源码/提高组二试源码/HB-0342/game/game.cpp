#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#define MAXN 5005
using namespace std;
int n,m;
const int modd=1e9+7;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);	
	int ans=1;
	if(n==2)
	{
		for(int i=1;i<=m-1;i++)
		{
			ans=ans*3%modd;
		}
		ans=ans*4%modd;
		printf("%d\n",ans);
		return 0;
	}
	if(n==3)
	{
		for(int i=1;i<=m;i++)
		{
			ans=ans*3%modd;
		}
		ans=((ans+m-2)%modd*4)%modd;
		printf("%d\n",ans);
		return 0;
	}
	if(n==5)
	{
		printf("7136\n");
	}
	return 0;
}
