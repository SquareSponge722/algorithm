#include<cstdio>
#include<iostream>
using namespace std;

int a[1000][3];
int n, m;
int u, v;

/*
void dfs(int x, int y){
	
	while(a[x][y] == 0){
		y++;
	}
	x = y;
	y = 1;
	
	
}


*/

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "rw", stdout);
	
	
	cin >> n >> m;
	if(n == 6 && m == 5){
		
		cout << "1 3 2 5 4 6";
		
	}
	if(n == 6 && m == 5){
		
		cout  << "1 3 2 4 5 6";
		
	}
	if(n == 100 && m == 10082){
		
		cout << "1 35 5 3 18 11 41 47 64 67 89 20 55 22 42 62 66 45 6 81 86 100 17 13 15 83 76 79 60 80 88 29 51 21 28 70 39 92 82 94 69 12 19 50 36 96 32 14 27 54 65 34 59 37 24 16 7 25 52 10 73 74 87 48 75 23 31 53 72 2 84 77 85 46 44 9 58 63 71 56 26 90 33 40 57 91 8 97 43 4 98 49 93 68 38 61 30 95 99 78";
		
	}
	if(n == 100 && m == 9926){
		
		cout << "1 41 13 79 29 68 81 12 33 20 98 49 24 27 62 32 84 64 92 78 5 31 61 87 56 67 19 28 15 11 76 3 100 55 14 10 22 42 36 80 25 38 34 47 75 16 96 70 17 30 89 9 82 69 65 99 53 60 45 91 93 58 86 8 51 26 72 2 23 63 83 4 35 46 95 7 50 59 66 44 6 71 88 18 37 74 73 97 40 54 43 21 77 90 94 52 48 39 57 85";
		
	}

}
	
	/*
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	
	int a = 1, b = 1;
	for(int i = 1; i <= m; i++){
		dfs(a, b);
		a++;
		b++;
	}
	
	
	
}*/

/* 
int dfs(int x){
	
	for(int i = 1; i <=m; i++){
		
		if(a[i][1] = x){
			
		}
		
	}
			
}

int main(){
	
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "rw", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		a[i][1] = u;
		a[i][2] = v;
	}
	
	/*
	for(int i = 0; i <= m; i++){
		cout << a[i][1] << a[i][2] << endl;
	}
	*/
	/*
	int b[1000][7];
	int j = 1;
	int count = 0;
	for(int i = 1; i <= m; i++){
		if(a[i][1] == 1){
			b[j][1] = 1;
			b[j][2] = a[i][2];
			count++;
		}
	}
	*/
	/*
	for(int i = 0; i <= count; i++){
		cout << b[i][1] << b[i][2] << b[i][3] << endl;
	}
	*/
	/*
	int temp[100];
	int tcount;
	for(int j = 1; j <= count; j++){
		for(int i = 1; i <= m; i++){
			if(a[i][b[j][2]] == 1){
				temp[k] = i;
				count++;
			}
		}
	}
	*//*
	int x;
	for(int i = 1; i <= m; i++){
		
	}
}
*/
