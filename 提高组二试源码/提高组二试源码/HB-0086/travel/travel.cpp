//T1 travel

//呜呜呜，原地爆炸 

/*
	肯定要用贪心
	每个点记录的值：
		是否访问过（vis）
		~~第一次被访问时的道路（第一个指向它的点）(好吧，这个可以不用记录了)~~
	优先队列？
		维护以这个点为代表的一大堆点（下一步可以走的）
		可以一直扩充

	操作
		1.队首出队
		2.判断队首是否访问过（是：回到第一步，继续出队，直至未访问过的点）
		3. 将该点未访问过的邻边入队

-----------------分割线----------------------
悲伤地发现，上面的方法并不可行，贪心求解什么的不存在的，这辈子都不可能的 
（好吧，贪心的确要用，但不是这么用） 

对于树的情况，遇事不决，一根筋走到底

对于图的情况（其实就是比树多了一条有木有~~·） 
那么，我们就 ！！ 把环找出来，剩下的当树跑 （是不是很机智，哈哈）
先跑一圈标记环 
----------------分割线-----------------------
其实楼上的方式也不行啊啊啊~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 死于此处 
3个小时白写了，啊~ 
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int qread();
void search ();
void DFS (int s);
int DFS_huan (int s);
void DFS_biaoji (int p);
void DFS2 (int s, bool pd);
int findd (int p);
vector <int> V[5000 + 9];
int n, m, pk;
priority_queue <int, vector<int>, greater<int> > Q;//升序，优先返回最小
bool vis [5000 + 9];
bool vis2[5000 + 9];//我说是备用的你信吗? 
bool pd_h[5000 + 9];//判断是否是环 
int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> n >> m;

	int u, v;
	for (int i = 1; i <= m; i++)
	{
		u = qread();
		v = qread();
		V[u].push_back(v);
		V[v].push_back(u);
	}
	
	DFS(1);
	
/*	if (m == n - 1)//一棵树，这种情况下，可以直接深搜，因为不允许回溯（回溯之后你就再也去不了了！！！），见样例一 
	{
		DFS(1);
		return 0; 
	} 
	
	if (m == n)//嘿
	{
		//第一步：找环并标记 
		int p = DFS_huan (1);//p 在环上
		pk = findd(p);//与环相遇的第一个点 
		DFS_biaoji (p); */
	/*	memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++)
			if (vis[i]) cout << i <<" "; cout << endl;
		for (int i = 1; i <= n; i++)
			if (vis2[i]) cout << i <<" "; cout << endl;*/
		
		//woccc，怎么这么难写，，肯定是我写复杂了
		
		//额，第二步：总出发点开始搜索？
//		DFS2 (1, false);
//	} 
	

	return 0;
}
void DFS2 (int s, bool pd)//第一个判断是否回溯过，第二个判断是否进入过环 
{
	vis[s] = true;
//	cout << s << " ";
	if (s == pk)//走到该死的环上了！！
	{
		for (int i = 0; i < V[pk].size(); i++)
		{
			int maxn = 0, minn;
			int z = V[pk][i];
			if (vis2[z])//在环上
			{
				if (maxn == 0)
					maxn = z;
				else
				{
					minn = min(maxn, z);
					maxn = max(maxn, z);	
//					cout << minn << "-" << maxn << endl;
					Q.push(maxn);
//					DFS2(min, pd);
				}
			} 
		}
	} 
	else if (vis2[s])//在环上 
	{
		bool pdd = false;
		for (int i = 1; i < V[s].size(); i++)
		{
			int z = V[s][i];
			if (!vis[z] && z < Q.top() )
			{
				pdd = true;
				break;
			}
		}
		if (pdd == true)
		{
			for (int i = 1; i < V[s].size(); i++)
			{
				int z = V[s][i];
				if (!vis[z])
					Q.push(z);
			}
		}
	}
}
int count (int x)
{
	int ans = 0;
	for (int i = 0; i < (int)V[x].size(); i++)
	{
		int z = V[x][i];
		if (vis[z]) ans++;
	}
	return ans;
}
int findd (int p)
{
	for (int i = 0; i < (int)V[p].size(); i++)
	{
		int z = V[p][i];
		if (count(z) == 3)
			return z;
	}
}
void D_biaoji(int s, int p)
{
	if (count(s) == 3)
	{
		vis2[s] = true;
		return;
	}
	for (int i = 0; i < (int)V[s].size(); i++)
	{
		int z = V[s][i];
		if (vis[z] && !vis2[z])
		{
			vis2[z] = true;
			D_biaoji(z, p);
		}
	}
}
void DFS_biaoji (int p)
{
	for (int i = 0; i < (int)V[p].size(); i++)
	{
		int z = V[p][i];
		if (vis[z] && count(z) == 2)
		{
			vis2[p] = true;
			D_biaoji(z, p);
		}
	}
	
}
int DFS_huan (int s)
{
	vis[s] = true;
	int ans = 0;
	for (int i = 0; i < (int)V[s].size(); i++)
	{
		int z = V[s][i];
		if (!vis[z])//未访问
		{
			int p = DFS_huan(z);
			if(p != -1)
				return p;
			else
				vis[z] = false;
		}		
		if (vis[z])//访问过
			ans++; 
	}
	if (ans == 2)//有环！！
	{
		return s;
	}
	return -1;
}
void DFS(int s)
{
	cout << s << " ";
	vis[s] = true;
	for (int i = 0; i < (int)V[s].size(); i++)
	{
		int z = V[s][i];
		if (!vis[z])//未访问
			DFS(z); 
	}
		
}
void search ()
{
	int s = 1;
	while (!Q.empty())
	{
		s = Q.top();
		Q.pop();
		if (!vis[s])   //未访问过
		{
			cout << s << " ";
			vis[s] = true;
			for (int i = 0; i < (int)V[s].size(); i++)
				Q.push(V[s][i]);
		}
	}
}
int qread()
{
	char c = getchar();
	int ans = 0;
	while (c > '9' || c < '0')
		c = getchar();
	while (c <= '9' && c >='0')
	{
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}
