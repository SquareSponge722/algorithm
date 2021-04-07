#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[100000];
int b[100000];
int n;int len=1;
void f();
int main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) continue;
		for(int j=i;j<=n;j++)
		{
			if(a[j]==0) break;
			else a[j]--;
		}
		i--;
		f();
	}
	for(int j=len;j>=1;j--) cout<<b[j];
	return 0;
}
void f()
{
	b[1]++;int x=1;
	while(b[x]==10)
	{
		b[x]=0;
		x++;
		b[x]++;
	}
	if(x>len) len=x;
}
