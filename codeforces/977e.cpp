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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

const int S=2e5+5;
int n,m;
vi a[S];
vi conn;
vector<bool> vis(S,false);

void dfs(int id){
    if(vis[id])return;
    vis[id]=true;
    conn.pb(id);
    for(auto x:a[id])if(!vis[x])dfs(x);
}

int main()
{
    fastio;
    int x,y;
    cin>>n>>m;
    rep(i,m,0){
        cin>>x>>y;
        a[x].pb(y);a[y].pb(x);
    }
    int ans=0;
    rep(i,n+1,1){
        if(vis[i]==false){
            conn.clear();
            dfs(i);
            int f=1;
            rep(j,conn.size(),0){
                if(a[conn[j]].size()!=2){
                    f=0;
                    break;
                }
            }
            if(f)ans++;
        }
    }
    cout<<ans<<endl;
}