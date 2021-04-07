
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[100005],f[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,j=1,i,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool flag=false;
	while(!flag){
		int min=1000001;
		for(i=1;i<=n;i++)f[i]=0;
		for(i=1;i<=n;i++){
			if(a[i]){
				f[i]=1;
				min=min<a[i]?min:a[i];
			}
		}
			j=1;
			while(!f[j])j++;
			if(j!=n+1)
				while(f[j]){
					a[j]-=min;
					j++;
					}
		ans+=min;
		flag=true;
		for(i=1;i<=n;i++) if(a[i]) flag=false;
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
