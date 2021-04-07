#include <iostream>

using namespace std;

bool judge(int a[],int b[][2],int c) //是否满足初始要求 a做驻军计划，B 是道路关系 
{
for(int i;i<c;i++)
{
	bool pam=false;
	if(a[i]==0)//如果城市没有驻军则进入下一判断 
	{
		for(int n=0;n++;n<c-1)
		{
			for(int j=0;j<2;j++)
			{
				if(b[n][j]==i)//找到城市 
				{
					if(a[b[n][!j]]==0)
					{
						pam=false;
					 } 
					 else
					 {
					 	pam=true;
					 }
				}
			}
		}
		if(pam==false)
		{
			return false;
		}
	}
 } 

return true;
}



bool hjudge(int a[],int b[][4],int c,int d)//A是驻军计划，B是国王要求，C是城市数，D是要求第几条 
{
	if((a[b[d][1]]==b[d][2])&&(a[b[d][3]]==b[d][4]))
	{
		return true;
	}
	else
	return false;
}


int search(int a[])
{
	int min=a[1];
	for(int i=0;i<1000;i++)
	{
		if(a[i]==0)
		{
			continue;
		}
		 else if(min>a[i+1])
		{
			min=a[i+1];
		}
	}
	return min;
}




int main(int argc, char** argv) {
	
	
	int a;//城市 
	int b;//要求
	cin>>a>>b;
	int money[a];//城市资金
	int road[a-1][2];//道路信息
	int request[b][4];//国王要求
	int biggest[1000];
	int sum=0;
	for(int i=0;i<a;i++)
	{
		cin>>money[i];
	}
	for(int i=0;i<a-1;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>request[i][j];
		}
	}
	for(int i;i<b;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>request[i][j];
		}
	}
	

	int plan[a];
	for(int i=0;i<a;i++)
	{
		plan[i]=1;
	}
	for(int i=0;i<b;i++)
	{
	plan[request[i][1]]=request[i][2];
	plan[request[i][3]]=request[i][4];
if((judge(plan,road,a)&&hjudge(plan,request,a,i))==false)//检查国王的要求是否可行 
	{
	cout<<-1<<endl;
}

int m=0;
while((judge(plan,road,a)&&hjudge(plan,request,a,i))==true)//去掉一个 
{
	plan[m]=0;
	i++;
	for(int j=0;j<a;j++)
	{
		if(plan[j]==1)
		{
			sum+=money[j];
		}
	}
	
	biggest[m]=sum;
}
cout<<search(biggest)<<endl;
}
	
return 0;
}
