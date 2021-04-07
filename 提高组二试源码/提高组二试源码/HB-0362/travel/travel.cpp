#include<bits/stdc++.h>
using namespace std;
int n,m,vis[5005],minn[5005];
int ans[5005],flag=0,cnt=1;
vector<int>G[5005];
void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
int e=0;
void dfs1(int u)
{
	flag=0;
	if(cnt==n)
	{
		flag=1;
		if(minn[1]==0 && minn[2]==0)
		{
			for(int i=1;i<=n;i++)
			{
				minn[i]=ans[i];
			}
		}
		return;
	}
	if(flag==1)	return;
	int len=G[u].size();
	for(int i=0;i<len;i++)
	{
		int v=G[u][i];
		if(!vis[v])
		{
			vis[v]=1;
			cnt++;
			ans[cnt]=v;
			dfs1(v);
		}
	}
}
void dfs2(int u)
{
	flag=0;
	if(cnt==n)
	{
		flag=1;
		if(minn[1]==0 && minn[2]==0)
		{
			for(int i=1;i<=n;i++)
			{
				minn[i]=ans[i];
			}
		}
		return;
	}
	if(flag==1)	return;
	int len=G[u].size();
	for(int i=0;i<len;i++)
	{
		int v=G[u][i];
		if(!vis[v])
		{
			vis[v]=1;
			cnt++;
			ans[cnt]=v;
			dfs2(v);
		}
		
		if(vis[v] && vis[u]==1 && ans[cnt]==v)//�ܹ�����һ������
		{
			vis[u]=2;//�Ѿ����ݹ���
			dfs2(v);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
	}               
	if(m==n-1)
	{
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)//��iΪ��� 
		{ 
			memset(vis,0,sizeof(vis));
			vis[i]=1;//�Ѿ�����һ���� 
			cnt=1;//��ʼ��
			memset(ans,0,sizeof(ans));
			ans[cnt]=i;
			
			dfs1(i);//dfs֤������
			
			if(flag==1)
			{
				int tmp=0;
				for(int j=1;j<=n;j++)
				{
					if(tmp>j && ans[j]!=0)
					{
						minn[j]=ans[j];
						tmp++;
						continue;
					}
					if(minn[j]>=ans[j] && ans[j]!=0)	tmp++;
					if(minn[j]>ans[j] && tmp==j && ans[j]!=0)
					{
						minn[j]=ans[j];
						tmp+=2;
						continue;
					}
				}
				
				if(i==1 && minn[1]!=0 && minn[2]!=0)
				{
					for(int j=1;j<=n;j++)
						cout<<minn[j]<<" ";
					//cout<<endl;
					return 0;
				}
			}
		}
	}
	if(m==n)
	{
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)//��iΪ��� 
		{ 
			memset(vis,0,sizeof(vis));
			vis[i]=1;//�Ѿ�����һ���� 
			cnt=1;//��ʼ��
			memset(ans,0,sizeof(ans));
			ans[cnt]=i;
			
			dfs2(i);//dfs֤������
			
			if(flag==1)
			{
				int tmp=0;
				for(int j=1;j<=n;j++)
				{
					if(tmp>j && ans[j]!=0)
					{
						minn[j]=ans[j];
						tmp++;
						continue;
					}
					if(minn[j]>=ans[j] && ans[j]!=0)	tmp++;
					if(minn[j]>ans[j] && tmp==j && ans[j]!=0)
					{
						//cout<<"###";
						minn[j]=ans[j];
						tmp+=2;
						continue;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
			cout<<minn[i]<<" ";//�Ż�:��1��������н����ֱ�������ͬ����2ect 
	return 0;
}
