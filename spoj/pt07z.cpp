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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

vi a[10005];
int dist[10005];

void dfs(int c,int l,int d)
{
    dist[c]=d;
    for(auto x: a[c])
    {
        if(x==l)
        continue;
        dfs(x,c,d+1);
    }
}
int main()
{
    fastio;
    int n;
    cin>>n;
    memset(dist,0,sizeof dist);
    int x,y;
    rep(i,n-1,0)
    cin>>x>>y,a[x].pb(y),a[y].pb(x);

    dfs(1,-1,0);
    int mi=1;
    rep(i,n+1,1)
    {
        if(dist[mi]<dist[i])
        mi=i;
    }

    memset(dist,0,sizeof dist);
    dfs(mi,-1,0);
    int ans=0;
    rep(i,n+1,1)
    ans=max(ans,dist[i]);
    cout<<ans<<endl;
}