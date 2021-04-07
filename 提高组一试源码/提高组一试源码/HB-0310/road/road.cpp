#include<bits/stdc++.h>
using namespace std;
int n,a[100005],f,mi=2147483600;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f=mi=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]>mi)f+=(a[i]-mi);
		mi=a[i];
	}
	printf("%d",f);
	return 0;
}
