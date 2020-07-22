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

const int S = 3e5 + 5;
map<ipair,int> M;
vector <bool> req,vis,hasp;
vi adj[S];

int main()
{
    fastio;
    int n,k,d;
    cin>>n>>k>>d;
    int x,y,w;

    req.resize(n,0);
    vis.resize(n + 1,0);
    hasp.resize(n + 1,0);
    queue<ipair> Q;

    rep(i,k,0){
        cin>>x;
        Q.push(mp(x,0));
        hasp[x] = true;
    }

    rep(i,n - 1,0){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);

        if(x > y)swap(x,y);
        M[mp(x,y)] = i;
    }

    while(!Q.empty()){
        auto X = Q.front();
        Q.pop();
        tie(x,w) = X;
        if(vis[x] || w == d)continue;
        vis[x] = 1;
        // cout<<"search in "<<x<<endl;

        for(int y: adj[x]){
            if(hasp[y])continue;
            hasp[y] =  true;
            req[M[mp(min(x,y),max(x,y))]] = 1;
            // cout<<"required"<<sendl;
            Q.push(mp(y,w + 1));
        }
    }

    vi ans;
    rep(i,n - 1,0)if(!req[i])ans.pb(i + 1);
    cout<<ans.size()<<endl;
    printarray(ans,ans.size())
}