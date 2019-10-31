#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}
int dp[107][2];
int n,k,d;
int mod=1e9+7;

int main()
{
    fastio;
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    
    cin>>n>>k>>d;

    rep(i,n+1,1)
    {
        rep(j,k+1,1)
        {
            if(i-j<0)break;

            if(j<d)
            {
                dp[i][0]=(dp[i][0]+dp[i-j][0])%mod;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%mod;
            }
            else
            {
                dp[i][1]=(dp[i][1]+dp[i-j][0])%mod;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%mod;
            }
        }
    }

    cout<<dp[n][1];

}