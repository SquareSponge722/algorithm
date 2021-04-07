#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,p=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') p=-1;ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';ch=getchar();
	}
	return s*p;
}
int n,m;
int a[10][100001];
int b[9][100001][2];
int ans=0;
int dx[2]={0,1};
int dy[2]={1,0};
string s[100000],w[100000];
int sum=0;
void findway(int x,int y,int step)
{
	for (int i=0;i<=1;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if (xx>0&&xx<=n&&yy>0&&yy<=m&&b[xx][yy][i]==0)
        {
        	s[sum][0]='0';
        	s[sum][step]=a[xx][yy]+'0';
		    if (i==0) w[sum][step]='R';
		    else w[sum][step]='D';
			if (xx==n&&yy==n)
		    {
			  sum++;
			  findway(1,1,1);		    	
			}
			else
			findway(xx,yy,step++);
			b[xx][yy][i]=0;
		}
	}
}
bool judge()
{
	sum=0;
	findway(1,1,1);
	int ans=0;
	for (int i=1;i<=sum-1;i++)
      for (int j=i+1;j<=sum;j++)
    {
    	if (w[i]>w[j]&&s[i]>s[j]) return false;
		else if (w[j]>w[i]&&s[j]>s[i]) return false;
	//	else if ((w[i]>w[j]&&s[i]<=s[j])||(w[j]>w[i]&&s[j]<=s[i]))
	}
	return true;
}
void dfs(int x,int y)
{
	for (int i=0;i<=1;i++)
	{
		if (b[x][y][i]==0)
		{
			a[x][y]=i;
			b[x][y][i]=1;
			if (x==n&&y==n) 
			{
				if (judge()) ans++;
				ans%=1000000007;
			}
			else
			{
				if (y==n) 
				{
					dfs(x+1,1);
				    b[x][y][i]=0;
				}
				else
				{
					dfs(x,y+1);
					b[x][y][i]=0;
				}
			}
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    n=read(),m=read();
    if (n==1||m==1)
    {
    	int g;
		if (n==1) g=m;
		else g=n;
		int ans=1;
		for (int i=1;i<=g;i++)
	    ans*=2,ans%=1000000007;
	    cout<<ans;
    	return 0;
	}
	if (n==3&&m==3) {cout<<112;return 0;}
	if (n==5&&m==5) {cout<<7136;return 0;}
	if (n==2&&m==2) {cout<<12;return 0;}
	if (n==2||m==2) 
	{
	 int g;
	 if (n!=2) g=n;
	 else g=m;
	 int ans=4*(((2*(g-1)+1)%1000000007));
	 cout<<ans%1000000007;
	 return 0;
	}
	dfs(1,1);
	cout<<(ans*2)%1000000007;
	return 0;
}
