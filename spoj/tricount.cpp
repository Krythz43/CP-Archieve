#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        cout<<(n*(n+2)*(2*n+1))/8<<endl;
    }
}