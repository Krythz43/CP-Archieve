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

const int S  = 2e5+5;
vector<int> adj[S];
vlli a(S);
vlli ans(S);
vlli dp(S);


void dfs(int i, int p){
    dp[i] = a[i];

    for(auto x: adj[i]){
        if(x == p)continue;
        dfs(x,i);
        dp[i] += max(0LL,dp[x]);
    }
}

void dfs2(int i, int p, int prev_score){
    ans[i] = dp[i] + prev_score;
    for(auto x: adj[i]){
        if(x == p)continue;
        dfs2(x,i,max(0LL,ans[i]-max(dp[x],0LL)));
    }
}

int main()
{
    fastio;
    int n;
    cin>>n;
    ainput(a,n);
    rep(i,n,0)a[i]-=(!a[i]);

    int x,y;
    rep(i,n-1,0){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(0,-1);
    dfs2(0,-1,0);
    printarray(ans,n)
}