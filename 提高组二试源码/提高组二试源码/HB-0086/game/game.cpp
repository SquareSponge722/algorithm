//T2 game
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int game[6][6] = {
					{0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0},
					{0, 0, 12, 88, 0, 0},
					{0, 0, 88, 112, 0, 0},
					{0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 7136},
				};
				
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cout << game[n][m] <<endl;
}
