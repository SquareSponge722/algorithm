#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const long long Ans[9][10]={{0,0,0,0,0,0,0,0,0,0},
					  		{0,0,0,0,0,0,0,0,0,0},
					  		{0,4,12,36,0,0,0,0,0,0},
					  		{0,8,36,112,336,0,0,0,0,0},
					  		{0,16,108,336,912,2688,0,0,0,0},
					  		{0,32,324,1008,2688,7136,21312,0,0,0},
					  		{0,64,972,3024,8064,21312,56768,170112,0,0},
					  		{0,128,2916,9072,24192,63936,170112,453504,1360128,0},
					  		{0,256,8748,27216,72576,191808,510336,1360128,3626752,10879488}};
					   
const long long M=1000000007;

long long n,m,ans=1;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int i;
	
	cin>>n>>m;
	
	if (n>m)
	{
		swap(n,m);
	}
	
	if (n==1)
	{
		for (i=30;i>=0;--i)
		{
			ans=ans*ans%M;
			if (m&(1<<i))
			{
				ans=ans*2%M;
			}
		}
		cout<<ans;
	}
	
	else
	{
		if (m<=n+1)
		{
			cout<<Ans[n][m];
			return 0;
		}
		else
		{
			for (i=30;i>=0;--i)
			{
				ans=ans*ans%M;
				if ((m-n-1)&(1<<i))
				{
					ans=ans*3%M;
				}
			}
			cout<<ans*Ans[n][n+1]%M;
		}
	}
	
	return 0;
}
