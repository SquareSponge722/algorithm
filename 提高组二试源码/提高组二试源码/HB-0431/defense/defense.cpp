#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
char w[2];
int n,m,fei[100002];
int w1,w2;
bool g[40000][40000];
int main()
{
	FILE *fin,*fout;
	fin=fopen("defense.in","r");
	fout=fopen("defense.out","w");
	fscanf(fin,"%d%d%s",&n,&m,w);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g[i][j]=0;
	for(int i=1;i<=n;i++)
	fscanf(fin,"%d",&fei[i]);
	for(int i=1;i<=n-1;i++)
	{
		fscanf(fin,"%d%d",&w1,&w2);
		g[w1][w2]=g[w2][w1]=1;
	}
	for(int k=1;k<=m;k++)
	{
		int a,x,b,y,minn=0;
		bool fang[1000001];
		for(int i=1;i<=n;i++)
		fang[i]=0;
		fscanf(fin,"%d%d%d%d",&a,&x,&b,&y);	
		if((g[a][b]==1)&&(x==0)&&(y==0))
		{
			printf("-1\n");
			break;
		}
		else
		{
			if((x==1)&&(y==1))
		    {
			    minn=minn+fei[a]+fei[b];
			    fang[a]=fang[b]=1;
			    for(int i=1;i<=n;i++)
			    {
				     if((g[a][i]==1)||(g[b][i]==1))
				     fang[i]=1;
			    }
		    }
		    if((x==0)&&(y==0)&&(g[a][b]==1))
		    {
		    	if(fei[a]>fei[b])
		    	{
		    		minn=minn+fei[a];
		    		fang[a]=1;
		    		for(int i=1;i<=n;i++)
		    		if(g[a][i]==1)
		    		fang[i]=1;
				}
				else
				{
		    		minn=minn+fei[b];
		    		fang[b]=1;
		 		    for(int i=1;i<=n;i++)
		    		if(g[b][i]==1)
		    		fang[i]=1;
				}
			}
		    for(int i=1;i<=n;i++)
		    {
			     if((i!=a)&&(i!=b)&&(fang[i]==0))
			    {
			        int k=0;
				    fang[i]=1;
				    for(int j=1;j<=n;j++)
			        {
				         if((g[i][j]==1)&&(j!=a)&&(j!=b)&&(fang[j]==0))
				         {
				    	    k++;
				    	    fang[j]=1;
					     }
			        }
				    if(k>=2)
			        {
				        int xiaof=0;
				        for(int j=1;j<=n;j++)
				        {
					        if((g[i][j]==1)&&(j!=a)&&(j!=b))
					        xiaof=xiaof+fei[j];
				        }
				        if(xiaof<fei[i])
				        minn=minn+xiaof;
				        else
				        minn=minn+fei[i];
			        }
			        else
			        {
			        	minn=minn+fei[i];
			        	fang[i]=1;
					}
			    }
		    }	
	        for(int i=1;i<=n;i++)
	        {
	    	     if(fang[i]==0)
	    	     minn=minn+fei[i];
		    }
		    fprintf(fout,"%d\n",minn);
		}
	}
	system("pause");
	return 0;
}
