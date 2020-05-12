#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(lli i=z;i<n;i++)
#define rrep(i,z) for(lli i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<lli>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(lli i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

const lli S = 5e3 + 5;
lli n,m;
vlli adj[S];
vlli col(S,0);
vector<bool> vis(S,0);
vector<bool> ok(S,0);

int cnt;

void dfs(lli idx){
    vis[idx] = true;
    cnt++;

    for(auto x:adj[idx])
        if(!vis[x] && !ok[x])
            dfs(x);
}

void dfs2(lli idx){
    ok[idx] = true;
    for(auto x:adj[idx])if(!ok[x])dfs2(x);
}

int main()
{
    fastio;
    cin>>n>>m;
    lli IDX;
    cin>>IDX;

    lli x,y;
    rep(i,m,0){
        cin>>x>>y;
        adj[x].pb(y);
    }


    dfs2(IDX);
    lli ans = 0;
    
    priority_queue<llipair> Q;
    

    rep(i,n+1,1){
		if(!ok[i]){
			cnt=0;
			fill(all(vis),false);
			dfs(i);
			Q.push(mp(cnt, i));
		}
	}

    while(!Q.empty()){
        auto x = Q.top();
        Q.pop();
        if(ok[x.ss])continue;
        ans++;
        dfs2(x.ss);
    }
    
    cout<<ans<<endl;
}