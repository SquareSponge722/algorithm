#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<climits>
using namespace std;
const long long constant=100000;
long long self[constant+20];
long long funcreal(long long begin,long long end){
	long long minn=LLONG_MAX,sum=0,half;
	for(long long k=begin;k<=end;k++)
		minn=min(self[k],minn);
	for(long long k=begin;k<=end;k++)
		{
			if(self[k]==minn)half=k;
			self[k]-=minn;
	    }
	if(minn==LLONG_MAX){
	return 0;
	}
	sum+=funcreal(begin,half-1)+funcreal(half+1,end)+minn;
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    	long long n;
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&self[i]);
		printf("%lld",funcreal(0,n-1));
}
