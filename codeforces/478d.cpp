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

const int N = 2e5+5,mod = 1e9+7;

int main()
{
    fastio;
    int r,g;
    lli h = inf;
    cin>>r>>g;
    lli sum = r+g;
    rep(i,inf,1){
        sum -= i;
        if(sum < 0){
            h = min(h,i - 1LL);
            break;
        }
    }
a2oj.com
    vlli dp(N);
    dp[0] = 1;

	for(int j=1;j<=h;++j)
		for(int i=N-1;i>=j;--i)
			dp[i] = (dp[i] + dp[i-j])%mod;
 
	lli tot = (h*(h + 1))/2;
	lli ans= 0;

	for(int i=0;i<=g;++i)if(tot - i <= r && tot-i >= 0)
	ans = (ans + dp[i])%mod;

	cout<<ans<<endl;
}