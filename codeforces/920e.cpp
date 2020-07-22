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

set <int> adj[200005],tot;
int main()
{
    fastio;
    int n,m;
    cin>>n>>m;

    rep(i,n + 1,1)tot.insert(i);
    int x,y;
    rep(i,m,0){
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    queue<int> Q;
    vlli ans;
    
    rep(i,n + 1,1)if(tot.count(i)){
        ans.pb(1);
        Q.push(i);
        tot.erase(i);
        while(!Q.empty()){
            y = Q.front();
            Q.pop();
            vi next;

            for(auto x: tot)if(!adj[y].count(x))next.pb(x);
            
            for(auto x : next){
                tot.erase(x);
                Q.push(x);
                ans.back()++;
            }
        }
    }

    cout<<ans.size()<<endl;
    SO(ans);
    printarray(ans,ans.size())
}