#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
#define endl '\n'
#define y1 y12312313
#define int ll
 
using namespace std;
 
const int N=3e5+3;
const int md=1e9+7;
const int inf=1e9+3;
 
int n,m,l,r;
int dp[N][3];
 
int cnt(int n,int ost)
{
    return (n-ost+3)/3;
}
 
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    cin>>n>>l>>r;
    dp[0][0] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
            {
                dp[i][(j+k)%3] += dp[i-1][j]*(cnt(r,k)-cnt(l-1,k));
                dp[i][(j+k)%3]%=md;
            }
        }
    }
    cout<<dp[n][0];
 
}
