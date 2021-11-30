#include "/Users/swassow/Downloads/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int main()
{
    int n,m,a,b,i,c=0,d=0,e=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        ara[a]++;
        ara[b]++;
    }
    for(i=1;i<=n;i++)
    {
        if(ara[i]==2)
            c++;
        else if(ara[i]==1)
            d++;
        else if(ara[i]==m)
            e++;
    }
    //for(i=0;i<=n;i++)
        //cout<<ara[i]<<" ";
    if(n==m&&c==n)
        cout<<"ring topology"<<endl;
    else if(e==1)
        cout<<"star topology"<<endl;
    else if(n==m+1&&(d==2&&c==n-2))
        cout<<"bus topology"<<endl;
    else
        cout<<"unknown topology"<<endl;
}
