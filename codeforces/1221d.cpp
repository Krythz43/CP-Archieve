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
#define inf LLONG_MAX
#define endl '\n'

const int S = 3e5+5;
lli dp [S][3];
lli a[S],b[S];
int n;

lli solve(lli i,lli x){
    lli &ans = dp[i][x];
    if(ans != -1)return ans;

    ans = inf;
    if(i == n-1)return ans = x*b[i];
    if(a[i]+x != a[i+1])ans = min(ans,solve(i+1,0));
    if(a[i]+x != a[i+1]+1)ans = min(ans,solve(i+1,1));
    if(a[i]+x != a[i+1]+2)ans = min(ans,solve(i+1,2));

    return ans = ans + x*b[i];
}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n;

        rep(i,n+5,0)rep(j,3,0)dp[i][j] = -1;
        
        rep(i,n,0)cin>>a[i]>>b[i];
        lli ans = min(solve(0,0),min(solve(0,1),solve(0,2)));
        cout<<ans<<endl;
    }
}