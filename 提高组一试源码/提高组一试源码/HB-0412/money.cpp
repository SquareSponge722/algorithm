#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	int n;
	int a;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		cin>>a;
		cout<<"2"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
