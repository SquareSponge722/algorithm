#include<bits/stdc++.h>
using namespace std;
const int mn=110000;
int a[mn];
int n,ans;
bool com()
{
	bool b=1;
	for(int i=1; i<=n; i++)
	{
		if(a[i]!=0)
		{
			b=0;
			break;
		}
	}
	return b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	a[0]=a[n+1]=0;//ĞéÄâ¸ÚÉÚ
	while(!com())
	{
		for(int i=1; i<=n+1; i++)
		{
			if(a[i]==0&&a[i-1]!=0)
			{
				for(int j=i-1; j>=1; j--)
					if(a[j]!=0) a[j]--;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

