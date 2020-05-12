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


const lli S  = 1e5 + 5;

vector<int> deg(S,0),adj[S];
vi epa(S,0);

set <int> check;

void dfs(int i,int p, int x){
    if(deg[i] == 1)check.insert(x%2);
    for(auto y: adj[i]){
        if(y == p)continue;
        dfs(y,i,(x^1));
    }
}

int main()
{
    fastio;
    int n;
    cin>>n;
    int x,y;
    vector<ipair> edges;
    rep(i,n-1,0){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb(mp(x,y));
        deg[x]++;
        deg[y]++;
    }

    for(auto x:edges){
        if(deg[x.ff] == 1)epa[x.ss]++;
        if(deg[x.ss] == 1)epa[x.ff]++;
    }

    int tot = n-1;
    rep(i,n+1,1){
        if(epa[i])tot -= epa[i]-1;
    }

    rep(i,n+1,1){
        if(deg[i] == 1){
            dfs(i,-1,0);
            break;
        }
    }

    if(tot == 1 || tot == 2){
        cout<<1<<" "<<1<<endl;
    }
    else{
        if(check.size()>1)cout<<3<<" "<<tot<<endl;
        else cout<<1<<" "<<tot<<endl;
    }
}