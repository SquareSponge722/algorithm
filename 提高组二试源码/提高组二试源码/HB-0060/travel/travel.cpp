#include<bits/stdc++.h>
using namespace std;
int a[10001][10001];
int N;
int n;
int b[10001][10001];
void f(int i)//6                         
{
	int flag=0;             
	for(int j=1;j<=n;j++)   //n=6,i=1 j=1               
	{
		if(a[i][j]==1)//i=1 j=3    i=3 j=4     i=4 j=6    i=6 j=
		{
			a[j][i]=0;
			cout<<i<<' '<<j<<endl;
			N++;
			f(j);
		}
    }
    
}
int main()
{
		int m;
		int x,y;
		cin>>n>>m;// n 城市个数   
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		f(1);
	return 0;
}
