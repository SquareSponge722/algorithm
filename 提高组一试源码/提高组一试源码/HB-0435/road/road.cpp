#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,sum,p,tot;
int a[105000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) tot++;//�ж��ٸ�������Ŀ�
    }
    p=1;//��ʼֵ
    while(tot<n)
    {
        while(a[p]==0) p++;//�ҵ���һ����Ϊ0�Ŀ�
        while(a[p]>=2)//���Լ� ���Ҽ���û���
        {
            a[p]--;
            p++;
        }
        while(a[p]==1)
        {
            a[p]--;
            p++;
            tot++;
        }
        if((a[p]==0) && (p<=n))
        {
            sum++;
            p=1;
            //for(int i=1;i<=n;i++)
            //cout<<a[i];
            //cout<<endl;
        }
        if(p==n+1)
        {
            p=1;
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
