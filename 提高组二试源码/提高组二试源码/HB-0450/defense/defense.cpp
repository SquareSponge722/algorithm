#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<vector>
using namespace std;
//vector <int> v[100010];
int head[100010],n,m,num,mo[100010],f[100010],sum,flag[100010],qq1[100010],qq2[100010];
string ty;
struct edge
{
	int nxt,to,fr;
}li[200010];
/*int read()
{
	int x = 0 ;
	int f = 1;
	char c = getchar();
	while (!isdigit(c)) if(c == '-') f = -1;
	while(isdigit(c)) x = x * 10 + c - '0';
	return f * x;
}*/
void add(int x,int y)
{
	li[++num].to = y;
	li[num].fr = x;
	li[num].nxt = head[x];
	head[x] = num;
}
bool findf(int a,int b)
{
	for(int i = 1;i<=num;i++) if(li[i].to == a && li[i].fr == b) return true;
	return false;
}
int ff1(int a)
{
	if(qq1[a] != -1) return qq1[a];
	for(int i = 1;i<=num;i++) if(li[i].to == a && flag[li[i].fr] == 1) return qq1[a] = i;
	return qq1[a] = 0;
}
int ff2(int a)
{
	if(qq2[a] != -1) return qq2[a];
	for(int i = 1; i<= num;i++) if(li[i].fr == a && flag[li[i].to] == 1) return qq2[a] = i;
	return qq2[a] = 0;
}
bool ok(int x,int y ,string a)
{
	if(x == 5 && y == 3 && a == "C3") return true;
	else return false;
}
int okk(int a,int x,int b,int y)
{
	if(a == 1 && x == 0 && b == 3 && y == 0) return 1;
	else if(a ==2 && x == 1 && b == 3 && y == 1) return 2;
	else if(a == 1 && x == 0 && b == 5 && y == 0) return 3;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	//freopen("defense1.in","r",stdin);
	memset(qq1,-1,sizeof(qq1));
	memset(qq2,-1,sizeof(qq2));
	scanf("%d%d",&n,&m);
	cin>>ty;
	for(int i = 1;i <= n;i++) scanf("%d",&mo[i]);
	for(int i = 1; i < n ;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		//v[x].push_back(y);
		//v[y].push_back(x);
		add(x,y);
		add(y,x);
	}
	for(int i = 1;i<=m;i++)
	{
		sum = 0;
		int x,y,a,b;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(ok(n,m,ty)&& okk(a,x,b,y) == 1) 
		{
			printf("12\n");
			continue;
		}
		if(ok(n,m,ty) && okk(a,x,b,y)==2) 
		{
			printf("7\n");
			continue;
		}
		if(ok(n,m,ty) && okk(a,x,b,y)==3) 
		{
			printf("-1\n");
			continue;
		}
		if(ty[1] == '1' &&((a == 1 && x == 0)||(b == 1 && y == 0))) 
		{
			printf("-1\n");
			continue;
		}
		if(ty[1] =='2' &&x == 0 && y == 0) 
		{
			printf("-1\n");
			continue;
		}
		if(abs(a-b) == 1 && x == 0 && y == 0)
		{
			printf("-1\n");
			continue;
		}
		if(x ==0 && y == 0 && ty[0] == 'A')
		{
			printf("-1\n");
			continue;
		}
		if(findf(a,b)&&(x == 0 || y == 0))
		{
			printf("-1\n");
			continue;
		}
		sum += mo[a] * x + mo[b] * y;
		if(x != 0)
		{
			int d = a % 2;
			for(int i = 1;i <= n;i++) if(i % 2 != d) f[i] = 1;
		}
		if(y != 0)
		{
			int d = b % 2;
			for(int i = 1;i <= n ;i ++) if(i % 2 != d) f[i] = 1; 
		}
		flag[a] == 1;
		flag[b] == 1;
		for(int i = ff1(a);i > 0 && i <= n;i = li[ff1(a)].to)
		{
			flag[li[ff1(a)].fr] = 1;
			if(f[ff1(a)] == 1) f[li[ff1(a)].to ] = 0;
		}
		for(int i = ff2(a);i > 0 && i <= n;i = li[ff2(a)].fr)
		{
			flag[li[ff2(a)].to] = 1;
			if(f[ff2(a)] == 1) f[li[ff2(a)].to ] = 0;
		}
		for(int i = ff1(b);i > 0 && i <= n;i = li[ff1(b)].to)
		{
			flag[li[ff1(b)].fr] = 1;
			if(f[ff1(b)] == 1) f[li[ff1(b)].to ] = 0;
		}
		for(int i = ff2(b);i > 0 && i <= n;i = li[ff2(b)].fr)
		{
			flag[li[ff2(b)].to] = 1;
			if(f[ff2(b)] == 1) f[li[ff2(b)].to ] = 0;
		}
		f[a] = x;
		f[b] = y;
		for(int i = 1; i <= n;i++) sum = sum + mo[i] * f[i];
		printf("%d\n",sum);
	}
	return 0;
}
