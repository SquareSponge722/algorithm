#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	int n; scanf("%d",&n);
	cin>>ans;
	int last=ans;
	int x;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		ans+=max(x-last,0);
		last=x;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
