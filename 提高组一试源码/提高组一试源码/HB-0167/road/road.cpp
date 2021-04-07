# include <cstdio>
# include <algorithm>
# include <iostream>
using namespace std;
int d[100050],wei[100050];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i,j=0,q=0,ok=0,tian,x=1,y,_q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]==0)
		{
			ok++;
			wei[q]=i;
			q++;
		}
	}
	for(tian=1;;tian++)
	{
		if(q==0)
		{
			for(i=1;i<=n;i++)
				d[i]--;
			for(i=1;i<=n;i++)
				if(d[i]<=0)
				{
					ok++;
					wei[q]=i;
					q++;
				}
		}
		else
		{
			if(_q!=q) sort(wei,wei+q);
			for(i=0;i<q;i++)
			  if(wei[0]==1)
				if((wei[j]+1)==wei[j+1])
					j++;
			if(wei[0]==1)
			{
				x=wei[j]+1;
				if(wei[j+1]!=0) y=wei[j+1];
				else y=n+1;
			}
			else y=wei[j];
			for(i=x;i<y;i++)
				d[i]--;
			for(i=x;i<y;i++)
				if(d[i]<=0)
				{
					ok++;
					wei[q]=i;
					_q=q;
					q++;
				}
		}
		if(ok>=n)
		{
			cout<<tian;
			break;
		}
	}
	return 0;
}
