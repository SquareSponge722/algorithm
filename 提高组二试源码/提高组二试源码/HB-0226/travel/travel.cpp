#include <bits\stdc++.h>
using namespace std;
int n,m;
bool con[5005][5005];
int d[5005];
bool flag[5005];	
int cc=1;
void init()
{
	memset(con,false,sizeof(bool));
	//memset(flag,true,sizeof(bool));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		flag[i]=true;
	flag[0]=false;
	int a,b;
	for (int i=0; i<m; i++)
	{
		scanf("%d%d",&a,&b);
		con[a][b]=true;
		con[b][a]=true;
	}
	return ;
}
int temp;
bool p_ok(int wz,int c,int s)
{
	for (int i=wz;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(con[i][j] && j<s && flag[j])
				{
					con[i][j]=false;
					temp=j;
					return false;
				}
			}
		}
	}
	
}
void w_slx(int wz,int c)
{
	if(cc>=n || c>=n)
	{
		return ;
	}
	for (int i=1; i<=n; i++)
	{
		if(i!=wz&& flag[i])
		{
			
			if(con[wz][i])
			{
				con[wz][i]=false;
				flag[wz]=false;
				//if(p_ok(wz,c,i))
					d[cc]=i,cc++;	
				//else
				//{
				//	d[cc]=temp,cc++;
				//}
				w_slx(i,c+1);
			}
			else if(i==n)
			{
				flag[d[c-1]]=true;
				return ;
			}
		}
		
	}

}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	int c=1;
	d[0]=1;
	w_slx(1,c);
	for (int i=0;i<n;i++)
		printf("%d ",d[i]);
	return 0;

}
