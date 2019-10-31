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

#define S 300000

int n;
vector <int> a[S];
vector <bool> vis(S,false);
vector <int> ans;


void dfs(int id)
{
    if(vis[id]==true)
    return;
    vis[id]=true;
    rep(i,a[id].size(),0)
    {
        if(vis[a[id][i]]==false)
        {
            ans.pb(a[id][i]);
            dfs(a[id][i]);
            break;
        }
    }
}

int main()
{
    fastio;
    cin>>n;
    int x,y;
    rep(i,n,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    ans.pb(1);
    dfs(1);
    int f=1;
    rep(i,ans.size(),0)
    {
        if(     (ans[(i+1)%n]==a[ans[i]][0] && ans[(i+2)%n]==a[ans[i]][1] ) || (ans[(i+2)%n]==a[ans[i]][0] && ans[(i+1)%n]==a[ans[i]][1] ))
        {

        }
        else
        {
            f=0;
            break;
        }
    }

    if(f)
    {
        for(auto x: ans)
        cout<<x<<" ";
    }
    else
    {
        for(int i=n-1;i>=0;i--)
        cout<<ans[i]<<" ";
    }
    nl;
}