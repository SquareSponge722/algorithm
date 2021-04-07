#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
long long ans,day,i,n,j,a[100001],b[100001];
bool x=1,y=0;
bool v[100001],v1[100001];
void dig();
//void dig1();
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) b[i]=a[i];
	sort(b,b+n);
	//下方是测试单调数据 
	for(i=0;i<n;i++)
	if(a[i]==b[i]) {
	v1[i]++;
	ans+=v1[i];
}
	day=a[n-1];
	if(ans==n) {
		cout<<day;
		return 0;
	}
	//上方*********** 
	for(i=0;i<n;i++)
	a[i]=a[i]-b[n-1];//此时所有坑都被填平或者填高,下面开始把坑挖平
	dig();
	cout<<day;
	//for(i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
void dig()
{
	while(x) {
		for(j=0;j<n;j++){
	    for(i=j;i<n;i++) {
		    if(a[i]<0) a[i]++;
		    if(a[j]==0) break;
		    else {day++;break;}
        }
	    ans=0;
	    for(i=0;i<n;i++) if(a[i]==0) {v[i]++;ans+=v[i];}
	    if(ans==n) x=0;
        }
    }
}
/*void dig1()//完美的暴力莽夫 
{
	while(x) {
	for(i=0;i<n;i++) {
		if(a[i]<0) a[i]++;
		if(a[0]==0) break;
		else {day++;break;}
	}
	for(i=1;i<n;i++) {	
		if(a[i]<0) a[i]++;
		if(a[1]==0) break;
		else {day++;break;}
	}
	for(i=2;i<n;i++) {
		if(a[i]<0) a[i]++;
		if(a[2]==0) break;
		else {day++;break;}
	}
	for(i=3;i<n;i++) {
		if(a[i]<0) a[i]++;
		if(a[3]==0) break;
		else {day++;break;}
	}
	for(i=4;i<n;i++) {
		if(a[i]<0) a[i]++;
		if(a[4]==0) break;
		else {day++;break;}
	}
	for(i=5;i<n;i++) {
		if(a[i]<0) a[i]++;
		if(a[5]==0) break;
		else {day++;break;}
	}
	ans=0;
	for(i=0;i<n;i++) if(a[i]==0) {v[i]++;ans+=v[i];}
	if(ans==n) x=0;
}
}
*/
