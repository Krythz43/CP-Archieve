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

int n,q;
vi euls;
const int S = 2e5 + 5;
vi adj[S];
vi childs(S,1);
vi first(S);

void dfs(int idx, int p){
    first[idx] = euls.size();
    euls.pb(idx);
    for(auto x: adj[idx]){
        if(x ==  p)continue;
        dfs(x,idx);
        childs[idx] += childs[x];
    }
}

int main()
{
    fastio;
    cin>>n>>q;
    int x,y;
    rep(i,n,1){
        cin>>x;
        adj[x].pb(i + 1);
    }

    rep(i,n + 1,1)SO(adj[i]);
    dfs(1,-1);
    // printarray(euls, euls.size())

    while(q--){
        cin>>x>>y;
        if(childs[x] < y){
            cout<<-1<<endl;
            continue;
        }
        cout<<euls[first[x] + y - 1]<<endl;
    }
}