#include<bits/stdc++.h>
#include<vector>
using namespace std;
int p,n,o,a;
bool pd;
vector<int>q;
vector<int>sum;
bool cmp(int a,int b){
	return a>b;
}
void bs(int nw,int k){
	if(nw==k) {
		pd=1;
		return;
	}
	if(nw>k){
		return;
	}
	for(int i=0;i<sum.size();i++){
		bs(nw+sum[i],k);
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&p);
	for(int i=1;i<=p;i++){
		sum.clear();
		q.clear();
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d",&o);
			q.push_back(o);
		}
		sort(q.begin(),q.end(),cmp);
		while(!q.empty()){
			a=q.back();
			q.pop_back();
			pd=0;
			bs(0,a);
			if(pd==0){
				sum.push_back(a);
			}
		}
		cout<<sum.size()<<endl;
	}
	return 0;
}
