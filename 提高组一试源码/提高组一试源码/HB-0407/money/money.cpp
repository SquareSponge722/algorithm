#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int T,n;
int a[101];
bool killed[101];
int ans;
struct node {
	node(int a,bool b) {
		val=a,isSource=b;
	}
	int val;
	bool isSource;
	const bool operator <(const node t)const {
		return this->val<t.val;
	}
};
set<int> tester;
int read() {
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0' || ch>'9') {
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int gcd(int a,int b) {
	return b==0?a:gcd(b,a%b);
}

bool cmp(int a,int b) {
	return a>b;
}
void finalTest() {
	queue<node> q;
	int tv;
	for(set<int>::iterator it=tester.begin(); it!=tester.end(); it++) {
		q.push(node(*it,true));
	}
	node t(0,false);
	int lim,tm=tester.size()-1;
	lim=*(tester.rbegin());
	while(!q.empty()) {
		t=q.front();
		q.pop();
		if(tester.count(t.val)) {
			if(t.isSource==false) {
				tester.erase(t.val);
				ans++;
			}
		}
		for(set<int>::iterator it=tester.begin(); it!=tester.end(); it++) {
			if(t.val+(*it)<=lim) {
				q.push(node(t.val+(*it),false));
			}
		}
	}
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int k;
	int lastAns;
	T=read();
	rep(kde,1,T) {
		memset(killed,0,sizeof(killed));
		ans=0;
		tester.clear();
		n=read();
		rep(i,1,n)a[i]=read();
		rep(i,1,n)
			tester.insert(a[i]);
		finalTest();
		printf("%d\n",n-ans);
	}
	return 0;
}
