#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,t;
	int sum=0;
	int k[n];
	int wrong=-1;
	char type;
	int e;
	int s;
	cin>>n;
	cin>>m;
	cin>>type;
	cin>>t;
	int a[n+1],l;
	for(l=1; l<=n; l++) {
		cin>>a[l];
	}
	int q;
	int b[n+1];
	for(q=0; q<=n+1; q++) {
		b[q]=0;
	}
	int g;
	int c[n],d[n];
	for(g=1; g<=n-1; g++) {
		cin>>c[g];
		cin>>d[g];
		b[c[g]]=1;
		b[d[g]]=1;
	}
	int u,i,o,p;
	int f;
	int h;
	for(f=1; f<=m; f++) {
		cin>>u;
		cin>>i;
		cin>>o;
		cin>>p;
		b[u]=i;
		b[o]=p;
		for(h=1; h<=n; h++) { 
			if(b[c[h]]+b[d[h]]==0) {
				sum=-1;
				cout<<wrong<<endl;
				break;
			}
			if(b[c[h]]+b[d[h]]==1) {
				if(b[c[h]]==1) {
					sum=sum+a[c[h]];
				}
				if(b[d[h]]==1) {
					sum=sum+a[d[h]];
				}
			}
			if(b[c[h]]+b[d[h]]==2) {
				for(s=1; s<=2; s++) {
					if(b[c[1]]==0) {
						b[d[1]]=1;
						e=b[c[1]];
					} else {
						b[d[1]]=0;
						e=b[c[1]];
						b[c[1]]--;
					}
					int yu,k;
					for(yu=1;yu<=n;yu++)
					{
						if(b[c[yu]]==1)
						{
							sum=sum+a[c[yu]];
						}
						if(b[d[yu]]==1)
						{
							sum=sum+a[d[yu]];
						}
						k=sum;
					}
					if(k>=sum)
					{
						k^=sum;
						sum^=k;
						k^=sum;
					}
				}
			}//two
		}
		cout<<k<<endl;
	}
	return 0;
}
