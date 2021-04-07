#include <iostream>
using namespace std;

int choosemin(int a,int b[])
{
	int temp=0;
	int j=0;
	int first;
	int last;
	int strat;
	for(int i=0;i<a;i++)
	{
		if(b[i]!=0)
		{
			temp++;
		}
    } 
		int c[temp];
		strat=c[0];
	for(int i=0;i<a;i++)
	{
		if(b[i]!=0)
		{
        c[j]=i;
        j++;
		}
	}
	for(int i=0;i<temp;i++)
	{
		if(c[i]+1==c[i]+1)
		{
			first=c[i];
		}
	}
if(strat!=first)
{
	return strat;
}

return first;

}

int choosemax(int a,int b[])
{
	int temp=0;
	int j=0;
	int first;
	int last;
	int strat;
	for(int i=0;i<a;i++)
	{
		if(b[i]!=0)
		{
			temp++;
		}
    } 
		int c[temp];
		strat=c[0];
	for(int i=0;i<a;i++)
	{
		if(b[i]!=0)
		{
        c[j]=i;
        j++;
		}
	}
	for(int i=0;i<temp;i++)
	{
		if(c[i]+1==c[i]+1)
		{
			first=c[i];
		}
	}

if(strat!=first)
{
	return strat;
}

return last;

}

int main()
{
	
		int a;//路的长 
	int b[a];//各路段的凹陷程度 
	int count=0;//天数计算 
	int judge=0;//判断是否完工 
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	while(judge!=a)
	{
	for(int i=choosemin(a,b);i<=choosemax(a,b);i++)
	{
		b[i]--;
	}
    for(int i=0;i<a;i++)
	{
		if(b[i]==0)
		{
			judge++;
		}
	}	
	count++;
	}
	count+=b[a-1]-b[a-2];
	cout<<count;
return 0;
}
	























