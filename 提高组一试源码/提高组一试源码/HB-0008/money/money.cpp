#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int a[N]={0},r[N]={0};
int n,T;

bool comp(int x,int y) {return x<y;}

void z2(){
	if (a[2]%a[1]==0) 
	cout<<"1"<<endl;
	else
	cout<<"2"<<endl;
}

void z3(){
	for (int a1=0;a1*a[1]<=a[3];a1++)
	for (int a2=0;a1*a[1]+a2*a[2]<=a[3];a2++)
	if (a1*a[1]+a2*a[2]==a[3]) {
	    n--;
	    goto label;
	}
	label:
	    if (a[2]%a[1]==0) n--;
	    cout<<n<<endl;
}

void z4(){
	for (int a1=0;a1*a[1]<=a[4];a1++)
	for (int a2=0;a1*a[1]+a2*a[2]<=a[4];a2++)
	for (int a3=0;a1*a[1]+a2*a[2]+a3*a[3]<=a[4];a3++)
	if (a1*a[1]+a2*a[2]+a3*a[3]==a[4]) {
	    n--;
	    goto label;
	}
	label:
		z3();
}
void z5(){
	for (int a1=0;a1*a[1]<=a[5];a1++)
	for (int a2=0;a1*a[1]+a2*a[2]<=a[5];a2++)
	for (int a3=0;a1*a[1]+a2*a[2]+a3*a[3]<=a[5];a3++)
	for (int a4=0;a1*a[1]+a2*a[2]+a3*a[3]+a4*a[4]<=a[5];a4++)
	if (a1*a[1]+a2*a[2]+a3*a[3]+a4*a[4]==a[5]) {
	    n--;
	    goto label;
	}
	label:
		z4();
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for (int k=1;k<=T;k++){
		cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,comp);
		if (n==2) z2();
		else if (n==3) z3();
		else if (n==4) z4();
		else if (n==5) z5();
	}
	return 0;
}
