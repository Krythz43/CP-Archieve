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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

const int S=1e5+5;
vi a[S],cat(S);
int n,m;
vector <bool> vis(S,false);
int ans=0;

void dfs(int i,int cc)
{
    if(vis[i])
    return;
    vis[i]=true;

    cc=cat[i]?cc+1:0;
    if(cc>m)
    return;

    if(a[i].size()==1  && vis[a[i][0]])
    {
        ans++;
    }
    else
    {
        rep(j,a[i].size(),0)
        {
            if(vis[a[i][j]]==false)
            dfs(a[i][j],cc);
        }
    }
}

int main()
{
    fastio;
    int x,y;
    cin>>n>>m;
    rep(i,n+1,1)
    cin>>cat[i];

    rep(i,n-1,0)
    {
        cin>>x>>y;
        a[x].pb(y),a[y].pb(x);
    }

    dfs(1,0);
    cout<<ans<<endl;

}