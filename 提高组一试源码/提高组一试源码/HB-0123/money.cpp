#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105;
int s[maxn];
void sorta(int n)
{
	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,min;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>s[j];
		}
		min=s[1];
		for(int i=1;i<n;i++)
		{
			if(s[i]>=s[i+1])
			min=s[i+1];
		}
	}
	cout<<min;
	for(int i=1;i<=n;i++)
		cout<<s[i]<<" ";
	return 0;
	fclose(stdin);
	fclose(stdout);
}
