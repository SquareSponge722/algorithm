// T2 money
/*
	˼·��
	�ȶ��룬��������
	��ǰ������ɸ�� ������˵���� a1*a2��Χ a1 a2 ����ʱ a1 *a2 - (a1+a2)��
	����ans++ 
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int qread();
int a[100 + 9];
bool pd[25000 + 9];
int n, ans;
void work(int p, int maxn);
int gcd (int a, int b);
int main()
{
	freopen ("money.in", "r", stdin);
	freopen ("money.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		//ÿһ��ĳ�ʼ��
		memset (pd, false, sizeof(pd));
		memset (a, 0, sizeof(a)); 
		ans = 0;
		
		n = qread();
		for (int i = 1; i <= n; i++)
			a[i] = qread();
		
		sort(a+1, a+n+1);//Ĭ������
		
		if (n == 1)
		{
			cout << "1" << endl;
			continue;
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++)
			if (gcd(a[1], a[i]) == 1) 
				maxn = a[1] * a[i] - a[1] - a[i];
		for (int i = 1; i <= n; i++)
//			work(a[i], a[1] * a[2] - (a[1] + a[2]) );
			work(a[i], maxn);
		cout << ans << endl;
	}
}
int gcd (int a, int b)
{
	return b == 0 ? a : gcd (b, a % b);
}
void work(int p, int maxn)
{
//	cout << p << " ? " << pd[p] <<endl;
	if (p > maxn)
		return;
 	if (pd[p] == false)
		ans++;
	else
		return;
	pd[p] = true;
	for (int i = 1; i <= maxn; i++)
	{
		if (pd[i] == true)
		{
			pd[i+p] = true;
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
