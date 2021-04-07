#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int p[110000]={0},n;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	int head=1,tail=1;
	long long ans=0;
	while(!(head==n && tail==n)){
		int minn=99999999;
		head=1;tail=1;
		while(p[head]==0 && head<=n)
			head++;
		if(head>n)
			head=n;
		tail=head;
		while(p[tail]!=0 && tail<=n){
			minn=min(p[tail],minn);
			tail++;
		}
		if(head==n)
			break;
		else 
			tail--;
		for(int i=head;i<=tail;i++)
			p[i]-=minn;
		if(!(head==n && tail==n))
			ans+=minn;
	}
	printf("%lld",ans);
	return 0;
}

