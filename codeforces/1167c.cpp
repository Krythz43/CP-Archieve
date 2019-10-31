#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
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

#define S 500005

vi connected[S],a[S],layer[S];
vector <bool> vis(S,false),vis_layer(S,false);
map<int,int> M;
int con=0;

void dfs_layer(int id);

void dfs(int id)
{
    vis[id]=true;
    M[id]=con;
    connected[con].pb(id);
    for(auto x:a[id])
    {
        if(vis_layer[x]==false)
        dfs_layer(x);
    }
}

void dfs_layer(int id)
{
    vis_layer[id]=true;
    for(auto x: layer[id])
    {
        if(vis[x]==false)
        dfs(x);
    }
}

int main()
{
    fastio;
    int n,m,l,x;
    cin>>n>>m;
    rep(i,m,0)
    {
        cin>>l;
        while(l--)
        {
            cin>>x;
            a[x].pb(i);
            layer[i].pb(x);
        }
    }

    rep(i,n+1,1)
    {
        if(vis[i]==false)
        {
            con++;
            dfs(i);
        }
    }

    rep(i,n+1,1)
    cout<<connected[M[i]].size()<<" ";
    nl;
}
