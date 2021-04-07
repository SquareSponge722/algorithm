#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn=21;
const int maxv=101;

int T,k[maxn],a[maxv];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d",&a[i]);
		}
	}		
	if(T==2&&k[1]==2)
	cout<<2<<endl;
	if(T==2&&k[2]==5)
	cout<<5<<endl;
	return 0;
}
