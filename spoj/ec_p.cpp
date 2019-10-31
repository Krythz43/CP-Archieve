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

#define S 500005
vector<ipair> Q;
bool vis[S];
int tin[S],low[S],timer=0;
vi a[S];

void IS_BRIDGE(int x,int y){
    if(x>y)swap(x,y);
    Q.pb(mp(x,y));
}
void dfs(int v,int p=-1){
    vis[v]=true;
    tin[v]=low[v]=timer++;
    for(int to:a[v]){
        if(to==p)continue;
        if(vis[to])low[v]=min(tin[to],low[v]);
        else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>tin[v])IS_BRIDGE(to,v);
        }
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(Z,t+1,1){
        int n,m,x,y;
        cin>>n>>m;

        memset(vis,false,sizeof vis);
        Q.clear();
        rep(i,n+1,1)a[i].clear();

        rep(i,m,0){
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }

        cout<<"Caso #"<<Z<<endl;
        dfs(1);
        SO(Q);
        if(!Q.empty()){
            cout<<Q.size()<<endl;
            rep(i,Q.size(),0)
            cout<<Q[i].ff<<" "<<Q[i].ss<<endl;
        }
        else cout<<"Sin bloqueos"<<endl;
    }
}