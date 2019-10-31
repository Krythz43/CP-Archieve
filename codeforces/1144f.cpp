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

const int S=200005;
vi color(S+1,-1);
vi a[S];
int f=0;

void dfs(int id, int c)
{
    color[id]=c;
    c^=1;
    for(auto x:a[id])
    {
        if(color[x]==-1)
        dfs(x,c);
    }
}

int main()
{
    fastio;
    int n,m,x,y;
    cin>>n>>m;
    vector<ipair>query;
    rep(i,m,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        query.pb(mp(x,y));
    }
    dfs(1,0);
    rep(i,n+1,1)
    {
        for(auto x:a[i])
        if(color[x]==color[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    rep(i,m,0)
    cout<<color[query[i].ff];
    nl;
}
