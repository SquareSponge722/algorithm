#include<iostream>
#include<cstdio>
using namespace std;
int a[5001][3];
char c[5001];
int main()
{
	FILE*fin,*fout;
	fin=fopen("travel.in","rb");
	fout=fopen("travel.out","wb");
	int n,m;
    int maxn=5002;
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		{
			fscanf(fin,"%d%d",&a[i][1],&a[i][2]);
		}
	if(m==n-1)//m=n-1����� 
	{
	//��ÿ��������Ϊ��������� ���ж��Ƿ���·���� 
			 
		
	}
	fprintf(fout,"%s",c[maxn]);
	return 0;
}
