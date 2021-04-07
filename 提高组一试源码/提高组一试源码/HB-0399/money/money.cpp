#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n;
bool isprime[25001];
vector<int> prime;

void fast_sieve() {
	fill(isprime,isprime+25001,true);
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=25000;i++) {
		if(isprime[i]) prime.push_back(i);
		for(int j=0;j<prime.size()&&prime[j]*i<=25000;j++) {
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}

int main() {
	int t,cnt=0;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	fast_sieve();
	cin >> t;
	while(t--) {
		cnt=0;
		cin >> n;
		for(int i=1;i<=n;i++) {
			int tmp;
			cin >> tmp;
			if(isprime[tmp]) cnt++;
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
