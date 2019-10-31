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

lli n;
lli dp[(int)3e5+5];
vector<llipair> a[(int)3e5+5];
lli pet[(int)3e5+5];


lli ans=0;

lli dfs(lli v,lli lv)
{
    dp[v]=pet[v];
    lli ans1=0,ans2=0;
    for(auto node : a[v])
    {
        lli x=node.ff,y=node.ss;
        // cout<<v<<" "<<x<<" "<<y<<endl;
        if(x==lv)
        continue;
        // cout<<"check at "<<v<<","<<x<<" where edge weight="<<y<<endl;
        dfs(x,v);
        // cout<<"check at "<<v<<","<<x<<" where edge weight="<<y<<endl;
        if(dp[x]-y>ans1)
        {
            ans2=ans1;
            ans1=dp[x]-y;
        }
        else if(dp[x]-y>ans2)
        ans2=dp[x]-y;
    }
    dp[v]+=ans1;
    // cout<<"updating vertice "<<v<<" "<<ans1<<" "<<ans2<<" "<<dp[v]+ans2<<endl;
    ans=max(ans,dp[v]+ans2);
}

int main()
{
    fastio;
    cin>>n;
    lli x,y,z;
    rep(i,n+1,1)
    cin>>pet[i];
    rep(i,n,1)
    cin>>x>>y>>z,a[x].pb(mp(y,z)),a[y].pb(mp(x,z));

    dfs(1,0);
    cout<<ans<<endl; 
}