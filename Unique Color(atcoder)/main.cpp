#include "/Users/swassow/Downloads/stdc++.h"

using namespace std;
#define vi vector<int>
#define pb push_back
int vis[100001],col[100001],cc[100001],n,i;
vi ara[100001],ans;
void dfs(int s)
{
    if(cc[col[s]]==0)
        ans.pb(s);
    cc[col[s]]++;
    vis[s]=1;
    for(int child:ara[s])
    {
        if(!vis[child])
        {
            vis[child]=1;
            dfs(child);
        }
    }
    cc[col[s]]--;
}
int main()
{
    int a,b;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>col[i];
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        ara[a].pb(b);
        ara[b].pb(a);
    }
    dfs(1);
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
}
