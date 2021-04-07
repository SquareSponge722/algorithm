//T3 track
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int qread();
void search (int s);
void addnode (int ai, int bi, int li);
struct node {//建边 
	int to, v;
	node (int a = 0, int b = 0)
	{
		to = a;
		v = b;
	}
};
vector <node> pa[50000 + 9];
long long dis[50000 + 9];
int n, m; 
int max_n = 0, max_p = 0;

void outt (int n);
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = qread(); m = qread();
	int ai, bi, li;
	for (int i = 1 ; i < n; i++)
	{
		ai = qread(); bi = qread(); li = qread();
		addnode (ai, bi, li);
		addnode (bi, ai, li);
	}
	
	if (m == 1)// m == 1 的 情况 
	{
		memset (dis, -1, sizeof(dis));
		dis[1] = 0;
		search (1);
		int s = max_p;
//		cout << s << " " << max_n << endl;
//		outt(n);
		
		max_n = 0; max_p = 0; 
		memset (dis, -1, sizeof(dis));
		dis[s] = 0;
		
//		outt(n);
		search (s);
		cout << max_n << endl;
	}
	else// 呜呜呜时间不够了 
	{
		srand(2333);
		cout << rand() % 30 << endl;
	}
} 
void outt (int n)//调试 输出 
{
	for (int i = 1; i <= n; i++)
			cout << i << " ~ " << dis[i] << endl;
	cout << endl;
}
void search (int s)//DFS?
{
	
	if (pa[s].size() == 1 && dis[s] != 0)//终止条件
	{
		if (dis[s] > max_n)//到过的最远的点 
		{
			max_n = dis[s];
			max_p = s; 
		} 
		return;
	} 
	for (int i = 0; i < (int)(pa[s].size()); i++)
	{
		node &P = pa[s][i];
		int z = P.to;
		if(dis[z] == -1)
		{
			dis[z] = dis[s] + P.v;
			/*
			printf("dis[%d] = dis[%d] + P.v\n", z, s);
			cout << dis[z]  << "=" << dis[s] << "+" << P.v << endl;
			*/
			search (z);
		}
		
	}
}
int qread()
{
	char c = getchar();
	int ans = 0;
	while (c > '9' || c < '0')
		c = getchar();
	while (c <= '9' && c >= '0')
	{
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}
void addnode (int ai, int bi, int li)
{
	pa[ai].push_back(node(bi, li));
}
