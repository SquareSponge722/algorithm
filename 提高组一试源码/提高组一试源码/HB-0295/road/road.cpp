#include<iostream>
using namespace std;

int a[100005]={0},n=0,len=0;
long long ans=0,now=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	cout<<ans<<endl;
	return 0;
}

