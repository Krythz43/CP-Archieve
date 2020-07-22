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
        lli n,m,x,y;
        cin>>n>>m>>x>>y;

        vector<string> a(n);
        rep(i,n,0)cin>>a[i];
        lli A[n][m];
        rep(i,n,0)rep(j,m,0)A[i][j] = 1;
        rep(i,n,0)rep(j,m,0)if(a[i][j] == '*')A[i][j] = 0;

        rep(i,n,0)for(int j = m - 2; j>=0 ;j--)if(A[i][j] != 0)A[i][j] += A[i][j + 1];

        lli ans = 0;

        rep(i,n,0)if(A[i][0] != 0)ans += min(A[i][0]*x,(A[i][0]/2)*y + (A[i][0]%2)*x);
        else if(m != 1){
            ans += min(A[i][1]*x,(A[i][1]/2)*y + (A[i][1]%2)*x);
        }

        // cout<<ans<<endl;
        // displaymatrix(A,n,m)
        rep(i,n,0)
        rep(j,m - 1,1)
        if(A[i][j] == 0)
        ans += min(A[i][j + 1]*x,(A[i][j + 1]/2)*y + (A[i][j + 1]%2)*x);

        cout<<ans<<endl;
    }
}