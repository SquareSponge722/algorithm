#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>

using namespace std;
#define ll long long
#define INF 2147483647
int n,js=1;
int d[100010]={0},mmap[100010][2]={0},last[100010]={0};
void add(int a,int b)
{
	mmap[js][0]=b;
	mmap[js][1]=last[a];
	last[a]=js++;
}
int main()
{
	int ans=0;
	set<int> s;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&d[i]);
		s.insert(d[i]);
		add(d[i],i);
	}
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		for(int i=last[*it];i;i=mmap[i][1])
		{
			if(!d[mmap[i][0]]) continue;
			int j=mmap[i][0]-1;
			ans+=d[mmap[i][0]];
			while(d[j]>0)
			{
				d[j]-=d[mmap[i][0]];
				j--;
			}
			j=mmap[i][0]+1;
			while(d[j]>0)
			{
				d[j]-=d[mmap[i][0]];
				j++;
			}
			d[mmap[i][0]]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
