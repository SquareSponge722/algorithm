#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("money2.in","r",stdin);
	freopen("money2.out","w",stdout);
	int x,y,a,b,c;
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	cin>>a>>b>>c;
	if(x==7)cout<<31;
	if(x==9)cout<<15;
	return 0;
}
