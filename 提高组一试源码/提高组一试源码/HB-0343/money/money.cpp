#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n[1005],a[1005],m,b;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=t;i++)
			for(int j=1;j<=n[i];j++)
				scanf("%d",&a[j]);
	fclose(stdin);
	fclose(stdout);
}
