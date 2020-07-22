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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vlli> a(n,vlli(m));
        rep(i,n,0)rep(j,m,0){
            cin>>a[i][j];
            a[i][j] -= (i + j);
        }
// myMap: {{1, "Gennady"}, {42, "Petr"}, {3, "Makoto"}};
Note: Extract is the only way to change a key of a map element without reallocation

Complexity:
extract(key): ￼ doc

        a
// myMap: {{1, "Gennady"}, {42, "Petr"}, {3, "Makoto"}};
Note: Extract is the only way to change a key of a map element without reallocation

Complexity:
extract(key): ￼ doc
        d
// myMap: {{1, "Gennady"}, {42, "Petr"}, {3, "Makoto"}};
Note: Extract is the only way to change a key of a map element without reallocation

Complexity:
extract(key): ￼ doc

        for(int i = n-2;i >=0;i--)dp[i][m-1] = dp[i+1][m-1] + abs(a[i][m-1] - a[0][0]);
        for(int i = m-2;i >=0;i--)dp[n-1][i] = dp[n-1][i+1] + abs(a[n-1][i+1] - a[0][0]);

        for(int i = n-2; i >= 0;i--)
        for(int j = m-2; j >= 0;j--){
            dp[i][j] = min(dp[i+1][j] + abs(a[i+1][j] - a[0][0]),
                           dp[i][j+1] + abs(a[i][j+1] - a[0][0]));
        }

        cout<<dp[0][0]<<endl;
    }
}