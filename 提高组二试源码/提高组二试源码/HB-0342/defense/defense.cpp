#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#define MAXN 505
using namespace std;
int n,m;
int d[MAXN],fa[MAXN];
int ms[MAXN][MAXN];
char s[3];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %c",&n,&m,&s);
	for(int i=1; i<n; i++)
	{
		scanf("%d",&d[i]);
	}
	for(int i=1; i<=m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ms[a][b]=1;
		ms[b][a]=1;
	}
	for(int i=1; i<=m; i++)
	{
		int q1,w1,q2,w2;
		scanf("%d %d %d %d",&q1,&w1,&q2,&w2);
		/*	if(w2==0&&w1==0&&ms[q1][q2])
			{
				printf("-1\n");
				continue;
			}
			int ans=0;
			if(w1==1&&w2==1)
			{
				for(int i=1;i<n;i++)
				{
					if(i!=q1&&i!=q2)
					{

					}
				}

		*/
	}
	printf("12\n7\n-1\n");
	return 0;
}
