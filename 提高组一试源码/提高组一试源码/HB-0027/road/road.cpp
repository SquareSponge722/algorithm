#include<cstdio>
#include<iostream>
using namespace std;

int a[100001];
int n;
int strt = 1;
int cnt = 0;

int fnd(){
	
	while(a[strt] == 0){
		strt++;
	}
	int i = strt;
	int temp = a[strt];
	int end;
	while(a[i]!=0){
		
		if(temp > a[i] && a[i] != 0){
			temp = a[i];
		}
		i++;
		end = i-1;
	}
	cnt++;
	
	//cout <<"  start:"<< strt;
	//cout <<"  end:"<< end;
	
	for(int i = 1; i <= end; i++){
		if(a[i] != 0){
		a[i] = a[i] - 1;	
		}
	}
	
	/*
	for(int i = 1; i < n; i++){
		if(a[i] == 0){
			return 0;
		}
	}
	*/
}


int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "rw", stdout);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	/*
	int l = a[1];
	for(int i = 1; i <= n; i++){
		
		if(l > a[i]){
			l = a[i];
		}
		
	}
	
	int day;
	day = l;
	for(int i = 1; i <= n; i++){
		a[i] = a[i] - l;
	}
	if(a[1] == 0){
		
	}
	i = 1;
	while(a[i]!=0){
		
		if(l > a[i]){
			l = a[i];
		}
		i++;
		
	}*/
	int ans = 0;
	
	/*
	for(int i = 0; i > 100; i++){
		ans = fnd();
		cout << ans;
	}
	*/
	
	//cout << cnt;
	/*while(ans == 0){
		ans = fnd();
	}
	cout << fnd;*/
	
	
	for(int i = 1; i <= n; i++){
		if(a[i] != 0){
			fnd();
			//cout << i;
			i = 1;
		}
	}
	
	cout << cnt;
	/*for(int i = 1; i <= n; i++){
		cout << a[i];
	}*/
}
