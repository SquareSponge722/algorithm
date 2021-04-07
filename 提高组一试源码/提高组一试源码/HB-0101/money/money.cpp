#include<iostream>
#include<cstdio>
using namespace std;
int flag;
int f(int a,int m[],int x);
void f(int book[],int a,int head,int k);
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        int an=x;
        int m[x];
        for(int j=0; j<x; j++)
            cin>>m[j];
        for(int j=0; j<x; j++)
            if(f(m[j],m,x))an--;
        cout<<an<<endl;
    }
    return 0;
}
int f(int a,int m[],int x)
{
    int book[x+1]= {0};
    int k=1;
    for(int i=0; i<x; i++)
        if(m[i]<a)book[k]=m[i],k++;
    int book1[k]= {0};
    for(int i=1; i<k; i++)book1[i]=book[i];
    flag=0;
    f(book1,a,1,k-1);
    return flag;
}
void f(int book[],int a,int head,int k)
{
    if(flag==1)return;
    if(a==0)
    {
        flag=1;
        return;
    }
    if(head>k)return;
    int i=0;
    while(i*book[head]<=a)
    {
        a-=i*book[head];
        f(book,a,head+1,k);
        a+=i*book[head];
        i++;
    }
}
