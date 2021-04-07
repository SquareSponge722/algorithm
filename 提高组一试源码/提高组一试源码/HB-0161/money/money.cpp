#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int mp[105]={0};
const int base = 25005;

bool cmp(int x, int y)
{
	return x>y;
}

bool dfs(int x,int maxPos)
{
	if(x<0) return false;
	else if(x==0) return true;	
	for(int i=1;i<=maxPos;i++)
	{
		if(x % mp[i] == 0) return true;
	}
	for(int i=1;i<=maxPos;i++)
	{
		if(dfs(x-mp[i],i)) return true;
	}
	//printf("%d test failed\n",x);
	return false;
}

int deal()
{
	for(int i=1;i<=102;i++) mp[i] = 0;
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&mp[i]);
	sort(mp+1,mp+n+1);
	if(mp[1]==1) return 1;
	if(mp[1]==2)
	{
		for(int i=2;i<=n;i++)
		{
			if(mp[i]%2==0)
			{
				//printf("%d not included\n",mp[i]);
				mp[i]=base;
				n--;
			}
		}
		sort(mp+1,mp+1+n);
	
	}
	else if (mp[2]==2)
	{
		for(int i=3;i<=n;i++)
		{
			if(mp[i]%2==0)
			{
				//printf("%d not included\n",mp[i]);
				mp[i]=base;
				n--;
			}
		}
		sort(mp+1,mp+1+n);
	}
	
	//printf("n:%d\n",n);
	for(int i=n;i>=2;i--)
	{
		if(dfs(mp[i],i-1))
		{
			cnt++;
			//printf("%d not included\n",mp[i]);
		}
		//else
		//{
			//printf("%d must include\n",mp[i]);
		//}
	}
	return n-cnt;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("%d\n",deal());
		//printf("-----------\n");
	}
	return 0;
}
