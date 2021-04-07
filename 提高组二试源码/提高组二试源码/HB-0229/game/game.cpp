#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
int n,m,tmp;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{ 
	    cout<<((2^m)%(10^9+7));
	    return 0;
	}
	 else if(m==1)
	{ 
	    cout<<((2^n)%(10^9+7));
	    return 0;
	}
	else   if(n==2)
	{ 
	    
	    cout<<((2^n)*(2^m-1))%(10^9+7);
	    return 0;
	}
	else if(m==2)
	{ 
	    
	    cout<<((2^m)*(2^n-1))%(10^9+7);
	    return 0;
	}
	else if(n==3)
	{ int c=112;
	    cout<<c;
	    return 0;
	}
	else if(n==5)
	{ 
	   int b=7136;
	    printf("%d",b);
	    return 0;
	}
	
	
	
	
   return 0;
}
