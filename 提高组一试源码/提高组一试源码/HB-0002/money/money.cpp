#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int curr[6][21];
int main()
{
	int n, T, val, a;
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin>>T;
	for (int i=1; i<=T; i++)
	{
		cin>>n;
		curr[i][0]=n;
		for (int j=1; j<=n; j++)
		{
			cin>>a;
			curr[i][j]=a;
		}
	}
	for (int i=1; i<=T; i++)
	{
		cout<<curr[i][0]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
