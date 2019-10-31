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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vi a[n+5];
    int x,y;
    rep(i,m,0){
        cin>>x>>y;
        a[y].pb(x);a[x].pb(y);
    }

    queue<ipair> Q;
    vector<bool> vis(n+1,false);
    rep(i,n+1,1){
        lli ec=0,nc=0;
        if(vis[i]==false){
            Q.push({i,0});
            while(!Q.empty())
            {
                auto z=Q.front();
                Q.pop();
                x=z.ff;
                if(vis[x])
                continue;
                vis[x]=true;
                nc++;
                y=z.ss;
                y++;
                for(auto X: a[x]){
                    if(vis[X]==false){
                        ec++;
                        Q.push({X,y});
                    }
                }
            }
            if(ec!=(nc*(nc-1))/2){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
}