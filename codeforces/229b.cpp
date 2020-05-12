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
// #define endl '\n'
 

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vector<llipair> adj[n];
    int x,y,z;
    while(m--){
        cin>>x>>y>>z;
        x--,y--;
        adj[x].pb(mp(z,y));
        adj[y].pb(mp(z,x));
    }

    vlli gates[n];

    rep(i,n,0){
        cin>>x;
        if(x)gates[i].resize(x);
        rep(j,x,0)cin>>gates[i][j];
    }


    priority_queue <ipair> pq;

    int T = 0;
    while(binary_search(all(gates[0]),T))T++;
    pq.push(mp(-T,0));
    vector<bool> vis(n,false);

    lli w,t;
    ipair X;

    while(!pq.empty()){
        X=pq.top();
        pq.pop();
        w=-X.ff;
        x=X.ss;
        t=w;

        if(vis[x])continue;
        vis[x] = true;
        if(x == n-1){
            cout<<w<<endl;
            return 0;
        }

        for(auto to: adj[x]){
            y = to.ss;
            z = to.ff;
            if(vis[y])continue;
            int T = t;
            if(y!=n-1){
                while(binary_search(all(gates[y]),z+T))T++;
                T = lower_bound(all(gates[y]),z+t)-gates[y].begin();
            }

            // cout<<"push "<<z+T<<" at "<<x+1<<" to "<<y+1<<endl;
            pq.push(mp(-z-T,y));
        }
    }

    cout<<-1<<endl;
}