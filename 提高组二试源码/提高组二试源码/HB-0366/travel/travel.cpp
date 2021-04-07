#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;
ifstream fin;ofstream fout;
const int _=5000+7;
int n,m,a,b,now,total,cnt,ans[_],son[_][_],num[_];
inline void dfs(int k,int father)
{
	if(cnt==n)
		return;
	ans[++cnt]=k;
	for(int i=1;i<=num[k];i++)
		if(son[k][i]!=father)
			dfs(son[k][i],k);
}
inline void DFS(int k)
{
	
}
int main()
{
	fin.open("travel.in");
	fout.open("travel.out");
	fin>>n>>m;
	if(m==n-1)
	{
		for(register int i=1;i<=m;i++)
		{
			fin>>a>>b;
			son[a][++num[a]]=b;
			son[b][++num[b]]=a;
		}
		for(register int i=1;i<=n;i++)
			if(num[i])
				sort(son[i]+1,son[i]+num[i]+1);
		dfs(1,0);
		/*while(cnt!=n)
		{
			now=q.top();
			ans[++cnt]=now;
			q.pop();
			for(register int i=head[now];i;i=e[i].next)
				if(!visited[e[i].to])
					q.push(e[i].to),visited[e[i].to]=true;
		}*/
		for(register int i=1;i<n;i++)
			fout<<ans[i]<<" ";
		fout<<ans[n];
	}
	/*else
	{
		for(register int i=1;i<=m;i++)
		{
			fin>>a>>b;
			son[a][++num[a]]=b;
			son[b][++num[b]]=a;
		}
		for(register int i=1;i<=n;i++)
			if(num[i])
				sort(son[i]+1,son[i]+num[i]+1);
		DFS(1);
		for(register int i=1;i<=m;i++)
		{
			
		}
	}*/
	fin.close();
	fout.close();
	return 0;
}
