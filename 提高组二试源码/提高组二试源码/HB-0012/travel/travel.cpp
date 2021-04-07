#include<cstdio>
#include<iostream>
int cit[101][1];
int tt(int x,int y,int c[101][1])
{
	int t=c[x][y];
	printf("%d",t);
	int sum=0;
	for(int i=1;i<=x;i++)
	{
		for(int j=0;j<1;j++)
		{
			sum=sum+c[i][j];
		}
    }
	if(sum>0)
	{
		int temp;
		if(y==0)
	    {
	    	temp=c[x][1];
	    }  
	    else
	    {
		    temp=c[x][0];
	    }
	    for(int i=1;i<=x;i++)
	    {
		    for(int j=0;j<1;j++)
		    {
			    if(x==i)
			    {
				    c[i][j]=0;
			    }
			    if(c[i][j]==t)
			    {
				    c[i][j]=temp;
			    }
		    }
	    }
	    int e,f;
	    int min=x;
	    for(int i=1;i<=x;i++)
	    {
		    for(int j=0;j<1;j++)
		    {
			    if(c[i][j]==temp)
			    {
				    if(j==0)
				    {
					    if(min<c[i][1])
					    {
						    min=c[i][1];
						    e=i;f=1;
					    }
				    }
				    else
				    {
					    if(min<c[i][0])
					    {
						    min=c[i][0];
						    e=1;f=0;
					    }
				    }
			    }
		    }
	    }
	tt(e,f,c);
    }
    else goto LOOP;
	LOOP:printf("%d",t);;    
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,q,p;
	int min=n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<1;j++)
		{
			scanf("%d",&cit[i][j]);
			if(cit[i][j]==1)
			{
				if(j==0)
				{
				    if(min<cit[i][1])
				    {
					    min=cit[i][1];
					    q=i;p=1;
				    }
			    }
			    else
			    {
				    if(min<cit[i][0])
				    {
					    min=cit[i][0];
					    q=1;p=0;
			        }
			    }
			}
		}
	}
	tt(n,m,cit);
	return 0;
}
	
