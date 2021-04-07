#include<iostream>
#include<cstdio>
#define INF 99999999
using namespace std;

int n,a[100010];
long long ans=0;

void fix(int l,int r) {
	int m=INF,p;
	while(r>l){
		for(int j=l; j<=r; j++)
			if(a[j]<m) {
				m=a[j];
				p=j;
			}
			for(int g=l; g<=r; g++) {
				a[g]-=m;
			}
			r=p-1;
			ans+=m;
			m=INF;
	}
	ans+=a[l];
	a[l]=0;
}

void find()
{	
	int k,b,c;
	for(int i=0; i<=n; i++) {
		if(a[i]==0&&a[i+1]!=0) {
			b=i+1,k=b;
			while(a[k]!=0) k++;
			c=k-1;
			fix(b,c);
		}
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	find();
	cout<<ans;
	return 0;
}
