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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int n,k;
const int S = 1005;
const int K = 2005;

const lli mod = 998244353;
lli dp[S][5][K];

int mask(int x, int y){
    if(__builtin_popcount(x^y) == 2){
        if(x == 0 || x == 3)return 1;
        else return 2;
    }
    if(__builtin_popcount(x^y) == 0)return 0;    

    if(x == 0 || x == 3) return 1;
    else return 0;
}

lli solve(int idx,int cur, int comps){
    lli & ans = dp[idx][cur][comps];

    if(comps > k)return ans = 0;
    if(ans != -1)return ans;
    ans = 0;
    if(idx == n){
        if(comps == k)return ans = 1;
        else return ans;
    }

    rep(i,4,0)ans += solve(idx+1,i,comps + mask(cur,i));

    // cout<<"at "<<idx<<" "<<cur<<" "<<comps<<" we return "<<ans<<endl;
    return ans%=mod;
}

int main()
{
    fastio;
    cin>>n>>k;
    memset(dp,-1,sizeof dp);

    lli ans = 0;
    ans = (solve(1,0,1) + solve(1,1,2) + solve(1,2,2) + solve(1,3,1))%mod;
    cout<<ans<<endl;
}