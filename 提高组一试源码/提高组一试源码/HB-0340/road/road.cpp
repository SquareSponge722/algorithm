#include<iostream>
#include<algorithm>
#include<list>
#include<cstdio>
#include<cstring>

using namespace std;

char a;
int n,k;
int xcroad[100050];
int current_highest,current_subscript,zerm;
unsigned long long ops;
bool first_flag=true;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&k);
		xcroad[i]=k;
	}
	//for (int i=0;i<n;i++){
	//	cout<<xcroad[i]<<endl;
	//}
	current_highest=xcroad[0];
	for (int i=0;i<n;i++){
		if (xcroad[current_subscript+1]>xcroad[current_subscript] || i==n-1){
			if (first_flag){
				ops=ops+current_highest;
				first_flag=false;
			}else{
				if (xcroad[current_subscript]==0){
					ops=ops+current_highest-min(zerm,xcroad[current_subscript-1]);
				}else{
				
				ops=ops+current_highest-min(zerm,xcroad[current_subscript]);
			}
			}
			zerm=xcroad[current_subscript];
			current_highest=xcroad[current_subscript+1];
			current_subscript++;
			continue;
		}else{    //xcroad[current_subscript+1]<=xcroad[current_subscript]
			current_subscript++;
		}
	}
	cout<<ops;
	return 0;
}
