#include <cstdio>

using namespace std;

int n,cnt,minn=99999;
int d[100010],book[100010];

void search(int l,int r)
{
	if(l>=r)
	{
		cnt+=d[l];
		d[l]=0;
		return;
	}
	int flag=1;
	for(int i=l;i<=r;i++)
		if(d[i]==0)
		{
			flag=0;
			book[i]=1;
			int left=i-1,right=i+1;
			for(int j=i-1;j>=l;j--)
				if(book[j]==1)
					left=j;
			search(l,left);
			for(int j=i+1;j<=r;j++)
				if(book[j]==1)
					right=j;
			search(right,r);
		}
	if(flag==1)
	{
		cnt++;
		for(int i=l;i<=r;i++)
			d[i]--;
		search(l,r);
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		minn=minn>d[i]?d[i]:minn;
	}
	for(int i=1;i<=n;i++)
		d[i]-=minn;
	cnt+=minn;
	search(1,n);
	printf("%d",cnt);
	return 0;
}