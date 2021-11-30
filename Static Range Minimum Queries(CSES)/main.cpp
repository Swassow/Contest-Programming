//
//  main.cpp
//  Segment tree
//
//  Created by Ahsan Habib on 11/28/21.
//

#include "/Users/swassow/Downloads/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n,q;
long long a[N];
long long tree[4*N];

void built(int root,int left,int right)
{
    if(left == right)
    {
        tree[root] = a[left];
        return ;
    }
    built(2*root,left,(left+right)/2);
    built(2*root+1,((left+right)/2) + 1,right);
    tree[root] = min(tree[2*root] , tree[2*root + 1]);
}

long long query(int root,int left,int right,int l,int r)
{
    if(r < left || l > right) return INT_MAX;
    if(left >= l && right <= r)
    {
        return tree[root];
    }
    long long sumLeft = query(2*root,left,(left+right)/2,l,r);
    long long sumRight = query(2*root + 1,((left+right)/2) + 1,right,l,r);
    return min(sumLeft , sumRight);
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    built(1,1,n);
    //for(int i=1;i<=3*n;i++)
    //{
    //    cout<< i << ' ' << tree[i] <<endl;
    //}
    //cout << tree[1] <<endl;
    while(q--)
    {
            int a,b;
            cin>> a >> b;
            cout<< query(1,1,n,a,b) <<'\n';
    }
    
}
