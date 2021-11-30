#include "/Users/swassow/Downloads/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define ll long long
int main()
{
    ll ara[200005],n,i,q,sum[200005],l,r;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>ara[i];
    }
    sum[0]=0;
    sum[1]=ara[1];
    for(i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+ara[i];
    }
    while(q--)
    {
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
}
