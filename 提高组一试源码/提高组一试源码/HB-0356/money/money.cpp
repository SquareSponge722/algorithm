#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 1000
int a[N];
int minv1;
int minv2;
int minv3;
int main(){
	freopen("money.in","r",stdin);
	freopen("money,out","w",stdout);
	int T;
	int ycb;
	int n;
	int bo;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		if(n==2)
		{
			cout<<2<<endl;
			continue;
		}
		for(register int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		minv1=a[1];
		for(register int j=2;j<=n;j++)
		{
			if(a[j]%minv1!=0)
			{
				minv2=a[j];
				ycb=j+1;
				break;
			}
		}
		minv3=a[ycb];
		bo=minv1*minv2-minv1-minv2;
		if(bo<minv3)
		{
		    cout<<2<<endl;
		}
		else if(bo==minv3)
		cout<<3<<endl;
		else 
		{
			cout<<n<<endl;
		}
	}
}
