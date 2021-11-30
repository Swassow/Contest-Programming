#include "/Users/swassow/Downloads/stdc++.h"
//#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
struct DSU
{
    int n;
    vi par;
    DSU(int N)
    {
        n=N;
        par.assign(n+1,-1);
        for(int i=0;i<=n;i++)
            par[i]=i;
    }
    int find(int n)
    {
        if(par[n]==n)
            return n;
        return find(par[n]);
    }
    void Union(int u,int v)
    {
        u=find(u);
        v=find(v);
        if(u!=v)
            par[v]=u;
    }
};
int main()
{
    int n,u,v;
    vvi list1,list2;
    cin>>n;
    DSU graph(n);
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        if(graph.find(u)==graph.find(v))
           list1.pb({u,v});
        else
           graph.Union(u, v);
    }

           for(int i=1;i<=n;i++)
           {
            for(int j=i+1;j<=n;j++)
            {
                if(graph.find(i)==graph.find(j))
                    continue;
                list2.pb({i,j});
                graph.Union(i, j);
            }
        }
    cout<<list1.size()<<endl;
    for(int i=0;i<list1.size();i++)
    {
        cout<<list1[i][0]<<" "<<list1[i][1]<<" "<<list2[i][0]<<" "<<list2[i][1]<<endl;
    }
           
           
}
