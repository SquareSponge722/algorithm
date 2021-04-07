#include<iostream>
#include<cstdio>
using namespace std;

int T,n;
int a[30000];
bool bj = 1;

int iszys(int x,int y)
{
	int bigg;

	if(x>=y)bigg = x;
	else bigg = y;

	for(int i = 1; i <= bigg; i++)
		for(int j = 1; j <= bigg; j++)
			if( (i*j == y) && ( i == x || j == x) )return 1;

	return 0;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	scanf("%d",&T);

	while(T--)
		{
			scanf("%d",&n);
			if(n == 1)
				{
					scanf("%d",&a[1]);
					cout<<1<<"\n";
				}
			else if(n == 2)
				{
					for(int i=1; i<=2; i++)
						{
							scanf("%d",&a[i]);

							if(a[i] == 1)
								{
									cout<<1<<"\n";
									bj = 0;
								}

						}

					if( bj && iszys(a[1],a[2]) )
						cout<<1<<"\n";
					else if( bj )cout<<2<<"\n";

				}
			else if(n ==3)
				{
					for(int i=1; i<=3; i++)
						{
							scanf("%d",&a[i]);

							if(a[i] == 1)
								{
									cout<<1<<"\n";
									bj = 0;
								}

						}

					if( bj )
						{

							if( iszys(a[1],a[2]) && (iszys(a[1],a[3]) || iszys(a[2],a[3]) ) )
								{
									cout<<1<<"\n";
									bj = 0;
								}
							else if( bj && iszys(a[1],a[2]) && !iszys(a[1],a[3]) && !iszys(a[2],a[3]) )
								{
									cout<<2<<"\n";
									bj = 0;
								}
							else if(bj && iszys(a[1],a[3]) && !iszys(a[2],a[3]) && !iszys(a[1],a[2]) )
								{
									cout<<2<<"\n";
									bj = 0;
								}
							else if(bj && iszys(a[2],a[3]) && !iszys(a[1],a[2]) && !iszys(a[1],a[3]) )
								{
									cout<<2<<"\n";
									bj = 0;
								}
							else if( bj )cout<<3<<"\n";

						}
				}
			bj = 1;
		}
	return 0;
}
