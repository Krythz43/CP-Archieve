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

int main()
{
    fastio;
    int n,q,C;
    cin>>n>>q>>C;
    int dp[105][105][11];
    memset(dp,0,sizeof dp);

    int x,y,c;
    rep(i,n,0){
        cin>>x>>y>>c;
        dp[x][y][0] = c;
        rep(i,C + 1,1)dp[x][y][i] = min(C,dp[x][y][i-1] + 1);
    }

    rep(k,C + 1,0){
        rep(i,105,1)dp[0][i][k] += dp[0][i-1][k];
        rep(i,105,1)dp[i][0][k] += dp[i-1][0][k];
        rep(i,105,1)rep(j,1-5,1)dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
    }

    while(q--){
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;

        int ans = 0;
        for (int p = 0; p <= C; p++) {
            int brightness = (p + t) % (C + 1);
            int amount = dp[x2][y2][p] - dp[x1 - 1][y2][p] - dp[x2][y1- 1][p] + dp[x1 - 1][y1 - 1][p];
            ans += brightness * amount;
        }
        printf("%d\n", ans);

    }
}