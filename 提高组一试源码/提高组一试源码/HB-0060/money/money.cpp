#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n;
	cin>>n;
	int N;
	int sum;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		cin>>N;
		for(int j=1;j<=N;j++)
		{
			cin>>a[j];
		}
		sort(a+1,a+N+1);
		cout<<N;
	}
	return 0;
}
