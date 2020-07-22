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
// #define LP{0OP0-        `q135687j  0.kl7-+*]igdtu70*854q    l(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

const int S = 1e3 + 5;
int f = 0;

lli dp[S][S][2];
int n,m;
vlli a;

void solve(int idx,int sum, int inc){
    lli & ans = dp[idx][sum][inc];

    if(ans != -1 || f || idx >= n)return;
    ans = 0;
    if(inc)if((sum + a[idx])%m == 0){
        f = 1;
        return;
    }

    if(inc){sum += a[idx];
    sum %= m;}

    solve(idx + 1,sum,0);
    solve(idx + 1,sum,1);
}
int main()
{
    fastio;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);

    a.resize(n);
    ainput(a,n);
    if(n > m || a[0]%m == 0){
        cout<<"YES"<<endl;
        return 0;
    }

    rep(i,n,0){
        a[i] %= m;
        if(a[i] == 0){
            f = 1;
            break;
        }
        if(f)break;
        solve(i+1,a[i],0);
        solve(i+1,a[i],1);
    }

    if(f)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}