#include<bits/stdc++.h>
#include<string>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
const int N=10;
const int M=10000;
int py[2]={(0,1),(1,0)};
long long k;
long long d;
long long m,n;
int sum=0;
long long q;
int wmh()
{
	sum=(m*n-1)*2*(m*n-2);
	sum=sum%k;
	printf("%d",sum);
	return sum;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	k=pow(9,10)+7;
	wmh();
	return 0;
	}
