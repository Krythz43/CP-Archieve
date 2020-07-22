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

const int S = 1e5 + 5;
int n;
int id[S];
map<int,int> M[S];
lli cnt[S];
lli mx[S];
lli ans[S];
lli col[S];

vi adj[S];

void merge(int a,int b){
    if(M[id[a]].size() < M[id[b]].size())swap(id[a],id[b]);

    int idx = id[a];

    for(auto x: M[id[b]]){
        M[idx][x.ff] += x.ss;
        if(M[idx][x.ff] > mx[idx]){
            mx[idx] = M[idx][x.ff];
            cnt[idx] = 0;
        }

        if(M[idx][x.ff] == mx[idx])cnt[idx] += x.ff;
    }
}
void dfs(int idx,int p){

    for(auto to: adj[idx]){
        if(to == p)continue;
        dfs(to,idx);
        merge(idx,to);
    }

    ans[idx] = cnt[id[idx]];
}

int main()
{
    fastio;
    cin>>n;
    rep(i,n,0){
        cin >> col[i];
        M[i][col[i]]++;
        id[i] = i;
        mx[i] = 1;
        cnt[i] = col[i];
    }
    int x,y;

    rep(i,n-1,0){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y),adj[y].pb(x);
    }
    dfs(0,-1);

    rep(i,n,0)cout<<ans[i]<<" ";
    nl;
}