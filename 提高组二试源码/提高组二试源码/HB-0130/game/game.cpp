#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#define mod 1000000007
using namespace std;
int mx[2]={0,1};
int my[2]={1,0};
int n,m,x,y,z,mp[100][100],vis[100][100],ans,k,flag,tot;
struct node{
	string a,b;
}c[1000000];


void check(int nowx,int nowy,string px,string py)
{
	if(flag==1) return ; 
	string tmp;
	if(mp[nowx][nowy]==0) tmp="0";
	else tmp="1";
	px=px+tmp;
	if(nowx==n-1 && nowy==m-1)
	{
		c[++tot].a=px;
		c[tot].b=py;
	}
	for(int i=0;i<2;i++)
	{
		int nex=nowx+mx[i],ney=nowy+my[i];
		if(nex<0 || nex>n-1 || ney<0 || ney>m-1) continue;
		tmp=py;
		if(i==0) py=py+"R";
		else py=py+"D";
		check(nex,ney,px,py);
		py=tmp;
	}
}

void Get()
{
	tot=0;
	int ff=1;
	check(0,0,"","");	
	for(int i=1;i<=tot;i++)
	{
		if(ff==0) break;
		for(int j=1;j<=tot;j++)
		{
			if(i==j) continue;
			if(c[i].a>c[j].a && c[i].b>c[j].b) ff=0;
			if(c[j].a>c[i].a && c[j].b>c[i].b) ff=0;
		}
	}
	if(ff==1) ans++;
}

void build(int nowx,int nowy)
{
	if( nowx<0 || nowx>n-1 || nowy<0 || nowy>n-1) return ;
	int nex=nowx+(nowy+1)/m,ney=(nowy+1)%m;
	mp[nowx][nowy]=0;
	if(nowx==n-1 && nowy==m-1)
	{
		flag=0;
		Get();
	}
	else build(nex,ney);
	mp[nowx][nowy]=1;
	if(nowx==n-1 && nowy==m-1)
	{
		flag=0;
		Get();
	}
	else build(nex,ney);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n<=3 && m<=3)
	{
		build(0,0);
		if(n==1 || m==1) ans=0;
		printf("%d\n",ans);
	}
	else
	{
		if(n<m)
			printf("0\n");
	}
	return 0;
}
