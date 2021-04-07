#include<iostream>
#include<cstdio>
using namespace std;
const int mn=5050;
int con[mn][mn];
int a[mn],book[mn];
int n,m,u,v;
int now,last,llast;
int pla;
bool check(int x)
{
	bool b=0;
	if(x==0) return 1;
	else for(int t=1; t<=n; t++)
			if(con[x][t]&&!book[t])
			{
				b=1;
				pla=t;
				break;
			}
	return b;
}
bool exam(int k)
{
	bool flag=1;
	if(last==0) return 1;
	for(int v=1; v<=n; v++)
		if(con[last][v] && !book[v] && v<k && con[v][k])
		{
			now=last;
			last=llast;
			flag=0;
			break;
		}
	return flag;
}
void dfs(int i)
{
	if(i>n)
	{
		for(int i=1; i<=n; i++)
			cout<<a[i]<<' ';
		cout<<endl;
		return;
	}
	for(int k=1; k<=n; k++)
	{
		if(pla!=0) k=pla;
		if(!check(now))
		{
			now=last;
			last=llast;
		}

		else if(con[now][k]&&!book[k])
		{
			if(exam(k))
			{
				a[i]=k;
				now=a[i];
				last=a[i-1];
				llast=a[i-2];
				book[now]=1;
				dfs(i+1);
				//q=0;
				pla=0;
			}

		}
	}

}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	now=last=0;
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>u>>v;
		con[u][v]=1;
		con[v][u]=1;
	}
	for(int i=1; i<=m; i++)
		con[0][i]=1;
	dfs(1);
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6

1 3 2 4 5 6
*/

/*
6 5
1 3
2 3
2 5
3 4
4 6

1 3 2 5 4 6
*/
