///travel
#include<iostream>
#include<cstdio>
using namespace std;
const int mn=5010;
struct Edge
{
    int next;
    int to;
} edge[mn];
int n,m;
int num_edge;
int head[mn];
bool visited[mn];
int num_path=0;
int last[mn];
string ans="";
void add_edge(int from,int to)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
void init()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);//double ways!
    }
}
string MIN(string a,string b)
{
    int la=a.size();
    for(int i=0; i<=la-1; i++)
    {
        if(a[i]<b[i])
            return a;
        if(a[i]>b[i])
            return b;
        if(a[i]==b[i])
            continue;
    }
    return a;
}
string convert(int a)
{
    string s;
    while(a!=0)
    {
        s=char(a%10+'0')+s;
        a=a/10;
    }
    int ls=s.size();
    while(ls<4)
    {
        s='0'+s;
        ls=s.size();
    }
    return s;
}
void dfs(int place,int from,string path)
{
    int lp;
    lp=path.size();
    if(lp==4*n)//finished
    {
        //cout<<"path="<<path<<endl;
        if(ans=="")
            ans=path;
        else
            ans=MIN(ans,path);
        return;
    }
    else
    {
        if((last[place]==0&&place!=1)||visited[place]==0)///!!?
            last[place]=from;
        visited[place]=1;
        /*
        if(place==5)
            cout<<"hola!  "<<path<<endl;
        */
        int minp=10000;
        for(int i=head[place]; i!=0; i=edge[i].next)
        {
            if(visited[edge[i].to]==0)
                minp=min(edge[i].to,minp);
        }
        //cout<<"minp="<<minp<<endl;
        if(minp!=10000)
        {
            string temp1=path+convert(minp);
            dfs(minp,place,temp1);
            visited[minp]=0;
        }
        //cout<<"place:"<<place<<"   last[place]="<<last[place]<<endl;
        if(last[place]&&place!=1)
        {
            dfs(last[place],place,path);
        }
    }
}
void out(string a)
{
    int la=a.size();
    for(int i=0; i<=la-1;)
    {
        string t="";
        for(int j=i; j<=i+3; j++)
            t+=ans[j];
        int p=0;
        while(t[p]=='0')
            p++;
        for(int j=p;j<=3;j++)
            cout<<t[j];
        cout<<" ";
        i+=4;
    }
    return;
}
int main()
{
    //ios::sync_with_stdio(false);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    init();
    last[1]=1;
    dfs(1,0,"0001");
    out(ans);
    return 0;
}
