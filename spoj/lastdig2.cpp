#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
// #define endl '\n'


lli multi(lli a, lli b)
{
    a=a%10;
    if(b==0)
    return 1;
    if(b==1)
    return a%10;

    if(b%2)
    return (a*multi(a*a,b/2))%10;
    return multi(a*a,b/2)%10;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        lli a,b;
        a=s[s.size()-1]-48;
        cin>>b;
        cout<<multi(a,b)%10<<endl;
    }
}