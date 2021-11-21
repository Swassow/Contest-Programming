#include "/Users/swassow/Downloads/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

int main()
{
    int t,i,p,q;
    string s,s1;
    char ch,ch1;
    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>s>>s1;
        for(i=0;i<s1.size()-1;i++)
        {
            ch=s1[i];
            ch1=s1[i+1];
            for(int j=0;j<s.size();j++)
            {
                if(s1[i]==s[j])
                    p=j+1;
                if(s1[i+1]==s[j])
                    q=j+1;
            }
            sum+=abs(q-p);
            
        }
        cout<<sum<<endl;
    }
}
