#include <iostream>

using namespace std;

bool judge(int a[],int b[][2],int c) //�Ƿ������ʼҪ�� a��פ���ƻ���B �ǵ�·��ϵ 
{
for(int i;i<c;i++)
{
	bool pam=false;
	if(a[i]==0)//�������û��פ���������һ�ж� 
	{
		for(int n=0;n++;n<c-1)
		{
			for(int j=0;j<2;j++)
			{
				if(b[n][j]==i)//�ҵ����� 
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



bool hjudge(int a[],int b[][4],int c,int d)//A��פ���ƻ���B�ǹ���Ҫ��C�ǳ�������D��Ҫ��ڼ��� 
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
	
	
	int a;//���� 
	int b;//Ҫ��
	cin>>a>>b;
	int money[a];//�����ʽ�
	int road[a-1][2];//��·��Ϣ
	int request[b][4];//����Ҫ��
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
if((judge(plan,road,a)&&hjudge(plan,request,a,i))==false)//��������Ҫ���Ƿ���� 
	{
	cout<<-1<<endl;
}

int m=0;
while((judge(plan,road,a)&&hjudge(plan,request,a,i))==true)//ȥ��һ�� 
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
