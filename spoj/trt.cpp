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
#define endl '\n'

vector<lli> a;
lli dp[2005][2005];

lli solve(int fp,int bp,int i)
{
    if(fp>bp)
    return 0;
    lli &ans=dp[fp][bp];
    if(ans!=-1)
    return ans;

    return ans=max(i*a[fp]+solve(fp+1,bp,i+1),i*a[bp]+solve(fp,bp-1,i+1));
}
int main()
{
    fastio;
    memset(dp,-1,sizeof dp);
    int n,x;
    cin>>n;
    rep(i,n,0)
    {
        cin>>x;
        a.pb(x);
    }

    cout<<solve(0,n-1,1)<<endl;
}