#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define rg register
using namespace std;
vector<int>g[6000];
bool vis[6000],ge[6000],p[6000],top[6000];
int n,m,find1=6;
int f[6000],father[6000];
int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
void dfs(int i)
{
	vis[i]=true;
	int minn=99999999;
	for(int k=1;k<=g[i][0];k++)
	{ 
	for(int j=1;j<=g[i][0];j++)
	{ 
		if(minn>g[i][j]&&vis[g[i][j]]!=true)
		{ 
			minn=g[i][j];
		} 
	} 
	if(minn==99999999)
	{return;}
	cout<<minn<<" ";
    vis[minn]=true;
	dfs(minn);
	minn=99999999;
    } 
	return;
} 
void dfs2(int i,int j)
{
	while(father[i]!=j)
	{
	   top[i]=true;
	   i=father[i];	
	}
	top[i]=true;
	top[j]=true;
	return;
}
void dfs1(int i)
{
	vis[i]=true;
	//int summ=0;
	for(int j=1;j<=g[i][0];j++)
	{
		if(vis[g[i][j]]==true&&g[i][j]!=father[i])
		{
			dfs2(i,g[i][j]);
			find1=7;
			return;
		}
		else if(vis[g[i][j]]!=true)
		{
			father[g[i][j]]=i;
			dfs1(g[i][j]);
			if(find1==7)
			{
				return;
			}
		}
	}
	return;
}
void dfs3(int i,int minn)
{
	vis[i]=true;
	if(g[i][0]==0)
	{
		return;
	}
	for(int j=1;j<=g[i][0];j++)
	{
		int minnn=99999;
		for(int l=1;l<=g[i][0];l++)
		{
			if(vis[g[i][l]]!=true)
			{
				minnn=min(minnn,g[i][l]);
			}
		}
		//cout<<"!";
		if(minnn==99999999)
		{
			return;
		}
		if(vis[minnn]!=true&&top[minnn]!=true)
		{
		   cout<<minnn<<" ";
		  // cout<<"!";
		   dfs3(minnn,99999999);	
		}
		if(vis[minnn]!=true&&top[minnn]==true&&minn==99999999)
		{
			 int mu=99999999;
			 vis[minnn]=true;
			 for(int k=1;k<=g[minnn][0];k++)
			 {
			 	if(top[g[minnn][k]]==true)
			 	{
			 		mu=min(mu,g[minnn][k]);
				}
			 }
			 int muu=99999999;
			 int muuu=99999999;
			 cout<<minnn<<" ";
			 if(top[mu]!=true)
			 {
			 for(int k=1;k<=g[minnn][0];k++)
			 {
			 	if(g[minnn][k]>mu&&top[g[minnn][k]]==true)
			 	{
			 		muu=min(muu,g[minnn][k]);
				}
			 }
			 for(int k=1;k<=g[minnn][0];k++)
			 {
			 	if(vis[g[minnn][k]]!=true&&g[minnn][k]>muu)
			 	{
			 		muuu=min(muuu,g[minnn][k]);
				 }
			 }
			 cout<<muuu<<" ";
			 dfs3(muuu,muu);
		     }
		     else if(top[mu]==true)
		     {
		     	for(int k=1;k<=g[minnn][0];k++)
			    {
			 	if(g[minnn][k]>mu&&vis[g[minnn][k]]!=true)
			 	{
			 		muu=min(muu,g[minnn][k]);
				}
			    }
			    cout<<mu<<" ";
			    dfs3(mu,muu);
			 }
		}
		//cout<<"!!";
		if(vis[minnn]!=true&&top[minnn]==true&&minn!=99999999)
		{
			//cout<<"!!!";
			if(minnn>=minn)
			{
				//cout<<father[minn]<<" ";
				cout<<minn<<" ";
				for(int k=1;k<=n;k++)
				{
					top[k]=false;
				}
				dfs3(minn,99999999);
			}
			else
			{
				cout<<minnn<<" ";
				dfs3(minnn,minn);
			}
		}
	    /*else if(top[minnn]==true&&vis[minnn]!=true&&minn==99999999)
	    {
	    	vis[minnn]=true;
	    	cout<<minnn<<" ";
	    	//cout<<999;
	    	//cout<<minn<<endl;
	    	for(int k=1;k<=g[minnn][0];k++)
	    	{
	    		if(vis[g[minnn][k]]!=true)
	    		{
	    			minn=min(minn,g[minnn][k]);
				}
			}
		/*	if(top[minn]==true)
			{
				
			}
			cout<<minn<<endl;
			dfs3(minnn,minn);
		}
		else if(minn!=99999999&&top[minnn]==true&&vis[minnn]!=true&&minnn<minn)
		{
			cout<<minnn<<" ";
			dfs3(minnn,minn);
		}
		else if(minn!=99999999&&top[minnn]==true&&vis[minnn]!=true&&minnn>=minn)
		{
	        minn=99999999;
			return;
		}*/
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	if(m==n-1)
	{
	for(int i=1;i<=n;i++)
	{
		g[i].push_back(0);
		f[i]=99999999;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u][0]++;
		g[v][0]++;
		g[u].push_back(v);
		g[v].push_back(u);
		p[u]=true;
		p[v]=true;
        if(f[u]>v)
        {
        	f[u]=v;
        	//nf[u]=g[u][0];
		}
		if(f[v]>u)
		{
			f[v]=u;
			//nf[v]=g[v][0];
		}
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==true)
		{
			now=i;
			vis[now]=true;
			break;
		}
	}
	for(int i=1;i<=g[now][0];i++)
	{
		ge[g[now][i]]=true;
	}
	ge[f[now]]=false;
	cout<<now<<" ";
	dfs(now);
	return 0;
    }
    else if(m==n)
    {
    	for(int i=1;i<=n;i++)
    	{
    		g[i].push_back(0);
		}
    	for(int i=1;i<=m;i++)
    	{
    		int u,v;
    		cin>>u>>v;
    		g[u][0]++;
    		g[v][0]++;
    		g[u].push_back(v);
    		g[v].push_back(u);
		}
		father[1]=0;
    	dfs1(1);
    	for(int i=1;i<=n;i++)
    	{
    		vis[i]=false;
		}
    	cout<<1<<" ";
    	dfs3(1,99999999);
    	
    	
    	return 0;
	}
    return 0;
}
/*
100 99
26 51
91 93
93 58
62 32
39 48
15 28
83 35
76 100
80 10
18 37
33 20
50 7
27 24
14 10
18 88
47 34
55 100
84 64
75 34
56 67
17 30
75 96
45 60
62 27
41 1
61 87
83 72
36 42
72 23
31 5
53 99
97 93
44 66
100 77
52 98
78 92
15 11
99 65
61 78
1 85
71 88
98 20
22 10
38 54
42 10
87 56
90 100
64 92
29 68
72 2
30 89
72 63
86 58
19 28
19 94
79 41
44 6
66 59
55 21
73 6
38 34
79 29
82 69
76 3
98 49
19 67
80 38
69 65
91 60
60 99
12 81
97 40
86 51
80 25
57 39
95 7
83 95
17 70
59 50
78 5
75 16
9 89
8 86
6 71
46 35
83 4
54 43
55 14
12 33
76 11
82 9
13 41
68 81
32 84
48 1
26 72
70 96
49 24
74 37
*/
