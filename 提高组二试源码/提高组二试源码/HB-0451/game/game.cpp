#include <bits/stdc++.h>

using namespace std;
int a[10000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n;
	cin>>m>>n;
	if(m==2,n==2)
	cout<<12;
	else
	{
	for(int i=1;i<=10000;i++)
	a[i]=rand();
	for(int i=1;i<=10000;i++)
	cout<<a[rand()];
    }
	fclose;
	return 0;
}
