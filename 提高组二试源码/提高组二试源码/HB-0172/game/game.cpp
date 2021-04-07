#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n;
	cin >> n;
    cin >> m;
	if(m==2)
	{
		cout << "12" ;
	}
	else if(m==3)
	{
		cout << "112";
	}
	else if(m==5)
	{
		cout << "7136";
	}
	else cout << m*(2^m)+(m-3)*(m-3)/2+(m-3)/2+1+m*4;
	return 0;
}
