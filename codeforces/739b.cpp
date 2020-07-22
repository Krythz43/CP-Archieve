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
// #define endl '\n'

int n,l;
vector<vector<ipair>> adj;

vector<vi> up;

vlli ans,depth,col,tot;

void dfs(int v, int p){
    up[v][0] = p;
    depth[v] = depth[p] + 1;

    rep(i,l + 1,1)up[v][i] = up[up[v][i - 1]][i - 1];

    for(auto u: adj[v]){
        tot[u.ff] += tot[v] + u.ss;
        dfs(u.ff,v);
    }
}



void preprocess(int root){
    depth.resize(n + 1,0);
    ans.resize(n + 1,0);
    tot.resize(n + 1,0);

    l = ceil(log2(n));
    up.assign(n + 1,vi (l + 1));

    dfs(root,root);
}

void solve(int v){
    int u = v;
    ans[up[v][0]] += 1;
    for(int i = l; i >=0 ;i--){
        if(col[v] >= tot[v] - tot[up[u][i]])u = up[u][i];
    }
    if(u != 1)ans[up[u][0]] += -1;

    // cout<<"solve for "<<v<<": can go till "<<u<<endl;
}

void dfs2(int u){
    for(auto x: adj[u]){
        dfs2(x.ff);
        ans[u] += ans[x.ff];
    }
}

int main()
{
    fastio;
    cin>>n;
    int x,y;
    col.resize(n + 1);
    rep(i,n+1,1)cin>>col[i];

    adj.resize(n + 1,vector<ipair>());

    rep(i,n + 1,2){
        cin>>x>>y;
        adj[x].pb(mp(i,y));
    }

    preprocess(1);

    rep(i,n+1,2)solve(i);

    dfs2(1);
    rep(i,n+1,1)cout<<ans[i]<<" ";
    nl;
}