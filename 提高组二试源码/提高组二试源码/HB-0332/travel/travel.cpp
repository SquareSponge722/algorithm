#include <iostream>

using namespace std;


bool judge(int a[],int b[],int c)
{
	
		for(int i=0;i<c;i++)
	{
		if(a[i]==b[i])
		{
			continue;
		}
		if(a[i]>b[i])//֤��b��Ŀ������ 
		{
			return true;
	}
	else{
		return false;
	}
	}
	
}

bool pam(int a[],int b)
{
	for(int i=0;i<b;i++)
	{
		
		for(int j=0;j<b;j++)
		{
		if(a[j]==a[i])	
		{
			return false;
		}
		else
		{
			return true;
		}
		}
	}
}










int main(int argc, char** argv) {
	int a;
	int num;
	cin>>a;
	cin>>num;//·������ 
    int link[a][2];
    for(int i=0;i<num;i++)//��õ�·����еĹ�ϵ 
    {
    	for(int j=0;j<2;j++)
    	{
    		
    		cin>>link[i][j];
    	
		}
	}
    int goalstart[a];
    goalstart[0]=link[0][0];
    for(int i=1;i<a;i++)
    {
    	goalstart[i]=link[i-1][!goalstart[i]];//���������� 
	}
	
	while(pam(goalstart,a))
	{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			if(goalstart[j]==goalstart[i])
			{
				goalstart[i]=link[i-1][!goalstart[i]];//��֤goal�е���ÿһ������һ�� 
			}
		}
	}
}
int goalend[a];
while(judge(goalstart,goalend,a))
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			if(goalstart[j]==goalstart[i])
			{
				goalend[i]=link[i-1][!goalstart[i]];//��֤goal�е���ÿһ������һ�� 
			}
		}
	}
}
goalstart[a]=link[a-1][1];
	for(int i=0;i<a;i++)
	{
		cout<<goalstart[i];
	}
	
	
	return 0;
}












