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

// N cities and M bidirectional roads
// All edge weights are 1 (an hour)
// All are connected

// Destroy maximum number of roads such that the path between 
// two pairs of cities dont exceed a certain limit

int n,m;
const int S = 3e3+5;
vi adj[S];
lli dist[S][S];

lli ans = LLONG_MAX;

void solve(int s1,int t1,int l1,int s2,int t2,int l2){
    
    if(dist[s1][t1] <= l1 && dist[s2][t2] <= l2)ans = min(
        ans,
        dist[s1][t1] + dist[s2][t2]
    );

    rep(i,n + 1,1)
    rep(j,n + 1,i + 1){
        if((dist[s1][i] + dist[i][j] + dist[j][t1]) <= l1 
        and (dist[s2][i] + dist[i][j] + dist[j][t2] <= l2))
        {ans = min(ans,dist[s1][i] + dist[s2][i] + dist[j][t1] + dist[j][t2] + dist[i][j]);

        // cout<<i<<" "<<j<<" dist = "<< (dist[s1][i] + dist[s2][i] + dist[j][t1] + dist[j][t2] + dist[i][j])<<endl;
    }}
}

void find_dist(int x){
    queue<ipair> Q;
    vector <bool> vis(n + 1, false);
    Q.push(mp(x,0));
    ipair X;
    int w,y;
    while(!Q.empty()){
        X = Q.front();
        Q.pop();
        tie(y,w) = X;
        if(vis[y])continue;
        vis[y] = true;
        dist[x][y] = w;

        for(auto to: adj[y]){
            if(vis[to])continue;
            Q.push(mp(to,w + 1));
        }
    }
}   
int main()
{
    fastio;
    cin>>n>>m;
    int x,y;

    rep(i,m,0){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    rep(i,n + 1,1)find_dist(i);

    int s1,t1,s2,t2,l1,l2;
    cin>>s1>>t1>>l1>>s2>>t2>>l2;

    solve(s1,t1,l1,s2,t2,l2);
    solve(s1,t1,l1,t2,s2,l2);
    solve(t1,s1,l1,s2,t2,l2);
    solve(t1,s1,l1,t2,s2,l2);


    if(ans == LLONG_MAX)cout<<-1<<endl;
    else cout<<m - ans<<endl;

    // rep(i,n + 1,1){
    //     rep(j,n + 1,1)cout<<dist[i][j]<<" ";
    //     nl;
    // }
}