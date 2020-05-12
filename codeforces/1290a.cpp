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
        int n, m, k;
        cin >> n >> m >> k;
        vinput(a,n);
        vector<int> what(m);
        for (int x = 0; x < m; x++) {
          int y = m - 1 - x;
          what[x] = max(a[x], a[n - 1 - y]);
        }
        k = min(k, m - 1);
        int ans = 0;
        for (int fix = 0; fix <= k; fix++) {
          int fiy = k - fix;
          int mn = (int) 2e9;
          for (int i = fix; i <= m - 1 - fiy; i++) {
            mn = min(mn, what[i]);
          }
          ans = max(ans, mn);
        }
        cout << ans << '\n';
    }
}