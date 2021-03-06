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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli mod=1e9+7;

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int main()
{
    fastio;
    int t,k;
    cin>>t>>k;

    vi dp(1e5+10,1);
    dp[k]++;
    
    rep(i,dp.size(),k+1)
    {
        dp[i]=(dp[i-1]+dp[i-k])%mod;
    }

    vi sum(1e5+10,0);
    rep(i,dp.size(),1)
    {
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(sum[b]-sum[a-1]+mod)%mod<<endl;
    }

//     5 48096
// 75634 80941
// 27808 89615
// 58867 93494
// 95515 99613
// 68307 69216

}