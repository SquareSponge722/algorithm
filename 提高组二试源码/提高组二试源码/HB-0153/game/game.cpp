#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int i,j;
char m,n;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n,a[i][j];
	scanf("%d%d",&m,&n);	
		{
			if(m,n<=4)
			{
				cout<<(m*n*3*3)+((m+1)*(m+n+1)+m);
			}
			else
			{
				cout<<(m+1)*(n+1)*(m+1)*(m+1)*(m+1)-(m*(2*2*2*2*2*2*2));
			}
		}
	return 0;
}
