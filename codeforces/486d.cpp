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

const lli N=2005,mod =1e9+7;
lli n,d;
vlli a,cnt;
int st;
vector<int> adj[N];

void dfs(int i,int p){
    cnt[i] = 1;
    for(auto x:adj[i]){
        if(x == p || a[x] < a[st] || a[x] > a[st]+d || (a[x] == a[st] && x<st))continue;
        dfs(x,i);
        cnt[i]=(cnt[i]*(cnt[x]+1))%mod;
    }
}

int main()
{
    fastio;
    cin>>d>>n;
    a.resize(n);
    cnt.resize(n);
    ainput(a,n);
    int x,y;
    rep(i,n-1,0){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    lli ans = 0;

    rep(i,n,0){
        st = i;
        dfs(i,-1);
        ans+=cnt[i];
        // cout<<"Updating at "<<i<<" : "<<cnt[i]<<endl;
        ans%=mod;
    }

    cout<<ans<<endl;
}