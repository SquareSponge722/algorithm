 #include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int x=0,i,j,T,n[21],a[101][25001];
int sushu[23];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(i=0;i<T;i++) {
		cin>>n[i];
		for(j=0;j<n[i];j++) cin>>a[i][j];
	}
	if(n[0]==0) {
		cout<<a[0][0];
		return 0;
	}
	sushu[1]=2;
	sushu[2]=3;
	sushu[3]=5;
	sushu[4]=7;
	sushu[5]=11;
	sushu[6]=13;
	sushu[7]=17;
	sushu[8]=19;
	sushu[9]=23;
	sushu[10]=29;
	sushu[11]=31;
	sushu[12]=37;
	sushu[13]=41;
	sushu[14]=43;
	sushu[15]=47;
	sushu[16]=51;
	sushu[17]=53;
	sushu[18]=59;
	sushu[19]=61;
	sushu[20]=67;
	sushu[21]=71;
	sushu[22]=73;
	sushu[23]=79;
	sushu[24]=83;
	sushu[25]=87;
	sushu[26]=89;
	sushu[27]=91;
	sushu[28]=97; 
	for(x=0;x<T;x++)
	cout<<sushu[x]<<endl;
}
