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
bool book[100000000]={false};
set<int>::iterator it,itt;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	bool flag=false;
	scanf("%d",&t);
	while(t--)
	{
		set<int> s;
		int n,mmin,ans=2;
		int hb[100]={0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&hb[i]);
		if(n==1)
		{
			printf("1\n",n);
			continue;
		}
		sort(hb+1,hb+n+1);
		int js=2;
		while(!(hb[js]%hb[1])&&js<=n) js++;
		if(js==n+1) {printf("1\n");continue;} 
		mmin=hb[1]*hb[js]-hb[1]-hb[js]-1;
		for(int i=1;i<=mmin;i++) book[i]=false;
		book[0]=true;
		for(int i=0;i<=mmin;i++)
		{
			if(book[i])
			{
				book[i+hb[1]]=true;
				book[i+hb[js]]=true;
				s.insert(i);
			}
		}
		for(int i=js+1;i<=n;i++)
		{
			if(book[hb[i]]) continue;
			if(hb[i]>mmin) break;
			book[hb[i]]=true;
			s.insert(hb[i]);
			ans++;
			for(it=s.begin();*it<mmin;it++)
			{
				if(!book[*it+hb[i]])
				{
					book[*it+hb[i]]=true;
					s.insert(*it+hb[i]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
3
1452896 2905791 5811584

*/