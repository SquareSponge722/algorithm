//T1 travel

//�����أ�ԭ�ر�ը 

/*
	�϶�Ҫ��̰��
	ÿ�����¼��ֵ��
		�Ƿ���ʹ���vis��
		~~��һ�α�����ʱ�ĵ�·����һ��ָ�����ĵ㣩(�ðɣ�������Բ��ü�¼��)~~
	���ȶ��У�
		ά���������Ϊ�����һ��ѵ㣨��һ�������ߵģ�
		����һֱ����

	����
		1.���׳���
		2.�ж϶����Ƿ���ʹ����ǣ��ص���һ�����������ӣ�ֱ��δ���ʹ��ĵ㣩
		3. ���õ�δ���ʹ����ڱ����

-----------------�ָ���----------------------
���˵ط��֣�����ķ����������У�̰�����ʲô�Ĳ����ڵģ��Ⱳ�Ӷ������ܵ� 
���ðɣ�̰�ĵ�ȷҪ�ã���������ô�ã� 

����������������²�����һ�����ߵ���

����ͼ���������ʵ���Ǳ�������һ����ľ��~~���� 
��ô�����Ǿ� ���� �ѻ��ҳ�����ʣ�µĵ����� ���ǲ��Ǻܻ��ǣ�������
����һȦ��ǻ� 
----------------�ָ���-----------------------
��ʵ¥�ϵķ�ʽҲ���а�����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ���ڴ˴� 
3��Сʱ��д�ˣ���~ 
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
priority_queue <int, vector<int>, greater<int> > Q;//�������ȷ�����С
bool vis [5000 + 9];
bool vis2[5000 + 9];//��˵�Ǳ��õ�������? 
bool pd_h[5000 + 9];//�ж��Ƿ��ǻ� 
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
	
/*	if (m == n - 1)//һ��������������£�����ֱ�����ѣ���Ϊ��������ݣ�����֮�������Ҳȥ�����ˣ���������������һ 
	{
		DFS(1);
		return 0; 
	} 
	
	if (m == n)//��
	{
		//��һ�����һ������ 
		int p = DFS_huan (1);//p �ڻ���
		pk = findd(p);//�뻷�����ĵ�һ���� 
		DFS_biaoji (p); */
	/*	memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++)
			if (vis[i]) cout << i <<" "; cout << endl;
		for (int i = 1; i <= n; i++)
			if (vis2[i]) cout << i <<" "; cout << endl;*/
		
		//woccc����ô��ô��д�����϶�����д������
		
		//��ڶ������ܳ����㿪ʼ������
//		DFS2 (1, false);
//	} 
	

	return 0;
}
void DFS2 (int s, bool pd)//��һ���ж��Ƿ���ݹ����ڶ����ж��Ƿ������� 
{
	vis[s] = true;
//	cout << s << " ";
	if (s == pk)//�ߵ������Ļ����ˣ���
	{
		for (int i = 0; i < V[pk].size(); i++)
		{
			int maxn = 0, minn;
			int z = V[pk][i];
			if (vis2[z])//�ڻ���
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
	else if (vis2[s])//�ڻ��� 
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
		if (!vis[z])//δ����
		{
			int p = DFS_huan(z);
			if(p != -1)
				return p;
			else
				vis[z] = false;
		}		
		if (vis[z])//���ʹ�
			ans++; 
	}
	if (ans == 2)//�л�����
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
		if (!vis[z])//δ����
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
		if (!vis[s])   //δ���ʹ�
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
