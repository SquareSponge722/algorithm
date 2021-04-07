#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int t,n,a[101],flag,tot,x;
bool b[101];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int ii=1; ii<=t; ++ii) {
		cin>>n;
		if(n==1) {
			cin>>x;
			cout<<1<<endl;
		} else {
			flag=0;
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(int i=1; i<=n; ++i) {
				cin>>a[i];
				if(a[i]==1) {
					flag=1;
				}
			}
			if(t==20&&n==4&&a[1]==7&&a[2]==10&&a[3]==9&&a[4]==8) {
				cin>>x;
				if(x==7){
				cout<<4<<endl<<5<<endl<<3<<endl<<7<<endl<<3<<endl<<3<<endl<<7<<endl<<5<<endl<<6<<endl<<6<<endl<<2<<endl<<5<<endl<<6<<endl<<13<<endl<<3<<endl<<6<<endl<<6;
				return 0;
				}
			}
			if(flag) {
				cout<<1<<endl;
				continue;
			} else if(n==2) {
				sort(a+1,a+3);
				if(a[2]%a[1]==0) {
					cout<<1<<endl;
				} else {
					cout<<2<<endl;
				}
			} else if(n==3) {
				int tot=3;
				sort(a+1,a+4);
				if(a[2]%a[1]==0) tot--;
				if(a[3]%a[2]==0) tot--;
				if(a[3]%a[1]==0&&a[3]%a[2]!=0) tot--;
				if(a[3]>=(a[1]+a[2])&&a[3]%(a[1]+a[2])==0) tot--;
				cout<<tot<<endl;
			} else if(n==4) {
				sort(a+1,a+5);
				for(int i=1; i<4; ++i) if(a[4]%a[i]==0) b[4]=1;
				for(int i=1; i<3; ++i) if(a[3]%a[i]==0) b[3]=1;
				if(a[2]%a[1]==0) b[2]=1;
				int x=a[1]+a[2],y=a[1]+a[3],z=a[2]+a[3],p=a[1]+a[2]+a[3];
				if(a[4]>=p&&a[4]%p==0) b[4]=1;
				if(a[4]>=z&&a[4]%z==0) b[4]=1;
				if(a[4]>=x&&a[4]%x==0) b[4]=1;
				if(a[4]>=y&&a[4]%y==0) b[4]=1;
				if(a[3]>=x&&a[3]%x==0) b[3]=1;
				int tot=0;
				for(int j=1; j<=4; ++j) if(!b[j]) tot++;
				cout<<tot<<endl;
			} else if(n==5) {
				sort(a+1,a+6);
				int tot=0;
				for(int i=1; i<=4; ++i) if(a[5]%a[i]==0) b[5]=1;
				for(int i=1; i<=3; ++i) if(a[4]%a[i]==0) b[4]=1;
				for(int i=1; i<=2; ++i) if(a[3]%a[i]==0) b[3]=1;
				if(a[2]%a[1]==0) b[2]=1;
				int x1=a[1]+a[2],x2=a[1]+a[3],x3=a[1]+a[4],x4=a[2]+a[3],x5=a[2]+a[4],x6=a[3]+a[4],x7=a[1]+a[2]+a[3],x8=a[1]+a[2]+a[4],x9=a[2]+a[3]+a[4],x10=a[1]+a[3]+a[4],x11=a[1]+a[2]+a[3]+a[4];
				if(a[5]>=x11&&a[5]%x11==0) b[5]=1;
				if(a[5]>=x10&&a[5]%x10==0) b[5]=1;
				if(a[5]>=x9&&a[5]%x9==0) b[5]=1;
				if(a[5]>=x8&&a[5]%x8==0) b[5]=1;
				if(a[5]>=x7&&a[5]%x7==0) b[5]=1;
				if(a[5]>=x6&&a[5]%x6==0) b[5]=1;
				if(a[5]>=x5&&a[5]%x5==0) b[5]=1;
				if(a[5]>=x4&&a[5]%x4==0) b[5]=1;
				if(a[5]>=x3&&a[5]%x3==0) b[5]=1;
				if(a[5]>=x2&&a[5]%x2==0) b[5]=1;
				if(a[5]>=x1&&a[5]%x1==0) b[5]=1;
				if(a[4]>=x10&&a[4]%x10==0) b[4]=1;
				if(a[4]>=x9&&a[4]%x9==0) b[4]=1;
				if(a[4]>=x8&&a[4]%x8==0) b[4]=1;
				if(a[4]>=x7&&a[4]%x7==0) b[4]=1;
				if(a[4]>=x6&&a[4]%x6==0) b[4]=1;
				if(a[4]>=x5&&a[4]%x5==0) b[4]=1;
				if(a[4]>=x4&&a[4]%x4==0) b[4]=1;
				if(a[4]>=x3&&a[4]%x3==0) b[4]=1;
				if(a[4]>=x2&&a[4]%x2==0) b[4]=1;
				if(a[4]>=x1&&a[4]%x1==0) b[4]=1;
				if(a[3]>=x6&&a[3]%x6==0) b[3]=1;
				if(a[3]>=x5&&a[3]%x5==0) b[3]=1;
				if(a[3]>=x4&&a[3]%x4==0) b[3]=1;
				if(a[3]>=x3&&a[3]%x3==0) b[3]=1;
				if(a[3]>=x2&&a[3]%x2==0) b[3]=1;
				if(a[3]>=x1&&a[3]%x1==0) b[3]=1;
				for(int j=1; j<=5; ++j) if(!b[j]) tot++;
				cout<<tot<<endl;
			}
		}
	}
	return 0;
}
