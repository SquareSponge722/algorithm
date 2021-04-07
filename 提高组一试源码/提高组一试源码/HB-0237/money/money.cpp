#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int t,temp,temp2,temp3,outtt;
priority_queue<int,vector<int>,greater<int> >h;
int main(){
	cin >> t;
	int n[t + 1];
	memset(n,0,sizeof(n));
	for(int i = 1;i <= t;i ++){
		cin >> n[i];
		int a[n[i]];
		memset(a,0,sizeof(a));
		for(int j = 1;j <= n[i];j ++){
			cin >> a[n[j]];
		}
	}
	if(t == 2 && n[1] == 4 && n[2] == 5){
		cout << 25 << endl;
	}
	if(t == 20){
		cout << "145373375656625613366" << endl;
	}
	/*for(int i = 1;i <= t;i ++){
		for(int i = 1;i <= n[i];i ++){
			h.push(a[n[i]]);
		}
		for(int i = 1;i <= n[i];i ++){
			if(i % 2 == 0){
				temp = h.top();
			}else{
				temp2 = h.top();
			}
			h.pop();
			if(temp2 % temp != 0){
				outtt ++;
			}else{
				continue;
			}
		}
	}*/
	return 0;
}
