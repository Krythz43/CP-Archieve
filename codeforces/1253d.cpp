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


int n;
const lli S = 2e5+5;
vi adj[S];
vector<bool> vis(S,false);
lli mx,mn;
vector<llipair> con;

void dfs(lli x){
    vis[x] = true;
    mx = max(mx,x);
    mn = min(mn,x);
    for(auto y:adj[x])if(!vis[y])dfs(y);
}

int main()
{
    fastio;
    int m;
    cin>>n>>m;
    int x,y;
    rep(i,m,0){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    rep(i,n+1,1){
        if(vis[i])continue;
        mx = -inf;
        mn = inf;
        dfs(i);
        con.pb(mp(mn,mx));
    }

    SO(con);

    mn=mx=0;
    lli ans = 0;

    for(auto x: con){
        if(x.ff < mx)ans++;
        mx = max(mx,x.ss);
    }
    cout<<ans<<endl;
}