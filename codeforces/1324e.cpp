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


vlli a;
int n,h,l,r;

const lli S = 2005;

lli dp[S][S][2];

lli solve(int i,int ho, int s){
    
    lli &ans = dp[i][ho][s];
    if(ans!=-1)return ans;
    if(i == n)return ans = 0;

    if(s == 0)
    ans = max(solve(i+1,(ho+a[i])%h,0),solve(i+1,(ho+a[i])%h,1));
    else
    ans = max(solve(i+1,(ho+a[i]-1)%h,0),solve(i+1,(ho+a[i]-1)%h,1));

    if(s == 0)
    ho=(ho+a[i])%h;
    else
    ho=(ho+a[i]-1)%h;
    
    if(ho>=l && ho<=r)ans++;
    return ans;
};

int main()
{
    fastio;
    cin>>n>>h>>l>>r;
    a.resize(n);
    ainput(a,n);
    memset(dp,-1,sizeof dp);

    lli ans = max(solve(0,0,0),solve(0,0,1));
    cout<<ans<<endl;
}