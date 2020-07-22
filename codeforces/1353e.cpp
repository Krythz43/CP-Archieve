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
string s;
const int S = 1e6 + 5;
lli dp[S][3];

lli solve(int idx,int st){
    if(idx >= n)return 0;
    lli & ans = dp[idx][st];
    if(ans != inf/2)return ans;
    ans = 0;

    if(st == 0)return ans = (s[idx] == '1' ?1:0) + min(solve(idx+k,0),min(solve(idx+k,1),solve(idx+k,2)));
    if(st == 1)return ans = (s[idx] == '1' ?0:1) + min(solve(idx+k,1),solve(idx+k,2));
    return ans = (s[idx] == '1'?1:0) + solve(idx+k,2);
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        rep(i,n+5,0)rep(j,3,0)dp[i][j] = inf/2;
        lli cnt = 0,temp;
        rep(i,n,0)cnt += (s[i] == '1');
        lli ans = inf/2;
        rep(i,k,0){
            temp = cnt;
            for(int j = i;j < n; j += k)temp -= (s[j] == '1');

            ans = min({ans,temp + solve(i,0),temp + solve(i,1),temp + solve(i,2)});
        }
        cout<<ans<<endl;
    }
}