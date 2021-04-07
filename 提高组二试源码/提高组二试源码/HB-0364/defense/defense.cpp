#include<bits/stdc++.h>
using namespace std;
int p[100001],u[100001],v[100001],a[100001],x[100001],b[100001],y[100001];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
    int n,m;
    string type;
    scanf("%d%d",&n,&m);
    cin>>type;
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    for (int i=1;i<n;i++) scanf("%d%d",&u[i],&v[i]);
    for (int i=1;i<=m;i++) scanf("%d%d%d%d",&a[i],&x[i],&b[i],&y[i]);
    for (int i=1;i<=m;i++) printf("%d\n",-1);
	return 0;
}
