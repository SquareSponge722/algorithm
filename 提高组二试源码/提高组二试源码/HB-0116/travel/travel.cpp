#include<bits/stdc++.h>
using namespace std;
int m,n;
int con[5000][5000];
int c[5000];
int w[5000];
void work(int a)
{
    if(w[a]==0&&a!=0) cout<<a+1<<" ";
    w[a]=1;
	for(int i=0;i<n;i++)
		if(con[a][i]==1&&w[i]==0) work(i);
	w[a]=2;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	int l,r;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		con[l-1][r-1]=1;
		con[r-1][l-1]=1;
		c[l-1]++;
		c[r-1]++;
	}
	cout<<1<<" ";
	if(m==n-1)
	{
		for(int i=0;i<n;i++)
		    if(con[0][i]==1) work(i);
	}
	//if()
	return 0;
}
