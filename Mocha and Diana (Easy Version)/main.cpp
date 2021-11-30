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
    int n,m1,m2,u,v;
    cin>>n>>m1>>m2;
    DSU graph1(n+1),graph2(n+2);
    vvi ans;
    while(m1--)
    {
        cin>>u>>v;
        graph1.Union(u, v);
    }
    while(m2--)
    {
        cin>>u>>v;
        graph2.Union(u, v);
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(graph1.find(i)!=graph1.find(j) && graph2.find(i)!=graph2.find(j))
            {
                ans.pb({i,j});
                c++;
                graph1.Union(i, j);
                graph2.Union(i, j);
            }
                
            
        }
    }
    cout<<c<<endl;
    for(auto it:ans)
        cout<<it[0]<<" "<<it[1]<<endl;
}
