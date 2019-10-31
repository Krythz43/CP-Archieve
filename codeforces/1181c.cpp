#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    rep(i,n,0)
    cin>>a[i];
    int dp[1005][1005],ip[1005][1005];
    memset(ip,0,sizeof ip);
    rep(i,1005,0)
    rep(j,1005,0)
    dp[i][j]=1;

    for(int j=0;j<m;j++){
        for(int i=n-2;i>=0;i--)
        {
            if(a[i][j]==a[i+1][j])
            dp[i][j]+=dp[i+1][j];
        }
    }
    lli ans=0;

    // rep(i,n,0)
    // {rep(j,m,0)
    // cout<<dp[i][j];
    // nl;}

    //CHECK FOR COLOUR DIFFERENCE 


    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++)
        {
            int k=dp[i][j];
            if(i+2*k>=n)
            continue;
            if((dp[i+k][j]==dp[i][j] && min(dp[i+2*k][j],dp[i][j])==dp[i][j]))
            {
                ans++;
                ip[i][j]=k;
                // cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }

    // cout<<ans<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ip[i][j]==0)
            continue;

            int l=1;
            for(int k=1;j+k<m;k++){
                if(ip[i][j]==ip[i][j+k]
                && a[i][j]==a[i][j+k] 
                && a[i+dp[i][j]][j]==a[i+dp[i][j]][j+k] 
                && a[i+2*dp[i][j]][j]==a[i+2*dp[i][j]][j+k]
                ){
                    ip[i][j+k]=0;
                    l++;
                }
                else break;
            }
            ans+=(l*(l+1))/2-l;
        }
    }

    cout<<ans<<endl;
}



// && a[i][j]==a[i][j+k] 
                // && a[i+dp[i][j]][j]==a[i+dp[i][j]][j+k] 
                // && a[i+2*dp[i][j]][j]==a[i+2*dp[i][j]][j+k]