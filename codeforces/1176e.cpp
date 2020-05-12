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

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vi adj[n+2];
        vector <bool> vis(n+2,false);
        int x,y;
        queue <ipair> Q;
        rep(i,m,0){
            cin>>x>>y;
            adj[x].pb(y),adj[y].pb(x);
        }

        Q.push({1,0});

        vi o,e;

        while(!Q.empty()){
            auto X = Q.front();
            x = X.ff;
            y = X.ss;

            Q.pop();
            if(vis[x])continue;
            if(y)o.pb(x);
            else e.pb(x);
            vis[x] = true;

            for(auto z: adj[x]){
                if(vis[z])continue;
                Q.push({z,(y+1)%2});
            }
        }

        if(o.size() > e.size()){
            cout<<e.size()<<endl;
            printarray(e,e.size())
        }
        else{
            cout<<o.size()<<endl;
            printarray(o,o.size())
        }

        // printarray(e,e.size())
        // printarray(o,o.size())
        
    }   
}