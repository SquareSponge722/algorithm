#include<bits/stdc++.h>
using namespace std;
int a[100002]={0};
int n,sum=0,minn=0,maxn=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i==1&&a[i+1]>=a[i]) {minn=a[i];sum+=a[i];flag=1;}
		else if(i==1&&a[i+1]<=a[i]) maxn=a[i];
		if((a[i-1]>a[i]&&a[i]<a[i+1])||(i==n&&a[i-1]>=a[i])){
			if(flag==0){
				sum+=abs(maxn-a[i])+a[i];flag=1;
			}
			minn=a[i];
		}
		if(a[i-1]<a[i]&&a[i]>a[i+1]&&i>1){
			sum+=a[i]-minn;
		}
	}
	cout<<sum;
	return 0;
}
