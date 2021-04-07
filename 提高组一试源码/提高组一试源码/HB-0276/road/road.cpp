#include<iostream>
#include<cstdio>
using namespace std;
int d[10001];
int main()
{
    FILE*fin,*fout;
    fin=fopen("road.in","rb");
    fout=fopen("road.out","wb");
    int n,day=0,num1=0,num2=0,num3=0;//num1表示改变的个数，num3表示0的个数 
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    fscanf(fin,"%d",&d[i]);
    while(num3<n)//如果不是全0就执行程序 
    {
	for(int j=0;j<n;j++)
	{
		if(d[j]==0)
		{
		num3++;//0的个数加1,并过滤多余的0 
		for(int x=0;x<n-1;x++)
		{
		d[x]=d[x+1];
		d[n-1]=0;
		}
		
		}
		else
		break;
	}
	    for(int h=0;h<n;h++)
        {
		if(d[h]!=0)
        {d[h]=d[h]-1;
		num1++;//改变数加1 
		}
		else
		break;
		}
	if(num1!=0)
	day++;
	}
	fprintf(fout,"%d",day);
	return 0;
}
