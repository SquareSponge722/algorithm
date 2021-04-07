#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 

 int t;
 int a[100000];
    void zhixing()
 {int n=0;
 cin>>n;
 for (int i=1;i<=n;i++)
 cin>>a[i];
 for (int i=1;i<=n;i++)
 for (int j=i;j<=n;j++)
 {if (a[i]>a[j])
 {int temp=a[i];
 a[i]=a[j];
 a[j]=temp;
 }
 }
 int maxx;
 int abc;
 for (int i=1;i<=n;i++)
 if(a[1+i]%a[1]!=0)
 {maxx=a[1]*a[i+1]-a[i+1]-a[1];
 abc=i+1;
 break;
 }
  int ans=2;
  int k=1;
//cout<<maxx<<endl;
 for (int i=abc+1;i<=n;i++)
  {
  if(a[i]<=maxx){
  
  for (int j=0;a[1]*j<=a[i];j++)
{k=(a[i]-a[1]*j)%a[abc];
if(k!=0)
	{ans++;
	break;
	}
}}
 else break;}
 
 
 	cout<<ans<<endl;
 	
 }
 
 
 
int main() {
	
	freopen ("money.in","r",stdin);
	freopen("money.ans","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	zhixing();
	fclose(stdin);
		fclose(stdout);
	
return 0;
}
