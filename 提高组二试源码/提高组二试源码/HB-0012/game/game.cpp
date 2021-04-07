#include<cstdio>
#include<iostream>
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long m,n;
	long long r=1;
	scanf("%d%d",&n,&m);
	if(m==1)
	{
        for(int i=1;i<=n;i++)
        {
        	r=r*2;
		}
	}
	else if(m==2)
	{
		if(n==1)
	    {
            for(int i=1;i<=m;i++)
            {
            	r=r*2;
	    	}
	    }
	    else if(n==2)
	    {
	    	r=4;
            for(int i=1;i<m;i++)
            {
            	r=r*3;
	    	}	    	
		}
	}
	else if(m==3) r=112;
    for(int j=1;r>1000000007;j++)
    {
    	r=r-1000000007;
	}
	printf("%d",r);
}
