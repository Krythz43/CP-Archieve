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

lli n,m,k;
const int S = 1e5 + 5;
vi adj[S];
vector <bool> vis(S,false);
vi kset;
vi col;
map<int,int> M;

void dfs(int idx, int pu){
    if(vis[idx] || kset.size() == k)return;

    vis[idx] = true;
    kset.pb(idx);
    col.pb(pu);
    M[idx]++;

    for(auto x: adj[idx])if(!vis[x])dfs(x,(pu^1));
}

int main()
{
    fastio;
    cin>>n>>m>>k;

    int x,y;
    rep(i,m,0){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,0);

    int f = 1;
    int st,end;

    rep(i,k,0){
        for(auto x: adj[kset[i]]){
            if(M.count(x)){
                if(i){if(x == kset[i - 1])continue;}
                else if(x == kset[k - 1]){
                    f = 0;
                    st = kset[0];
                    end = kset[k - 1];
                    cout<<"breaking here at1 "<<i<<endl;
                    break;

                }

                if(i < k - 1){if(x == kset[i + 1])continue;}
                else if(x == kset[0]){
                    f = 0;
                    st = kset[0];
                    end = kset[k - 1];
                    cout<<"breaking here at2 "<<i<<endl;
// 
                    break;
                    
                }

                if(i == 0 || i == k - 1)continue;
                
                st = kset[i];
                end = x;
                f = 0;
                cout<<"breaking here at3 "<<i<<endl;
                break;
            }
        }

        if(!f)break;
    }

    // printarray(kset,k)

    if(f){
        cout<<1<<endl;
        vi zr,on;
        rep(i,n,0)if(col[i])on.pb(kset[i]);else zr.pb(kset[i]);

        if(on.size() >= (k + 1)/2){
            rep(i,(k+1)/2,0)cout<<on[i]<<" ";
            nl;
        }
        else{
            rep(i,(k+1)/2,0)cout<<zr[i]<<" ";
            nl;   
        }
    }   
    else{
        cout<<2<<endl;
        int started = 0;

        // cout<<"testign "<<kset[st]<<" "<<kset[end]<<endl;

        vi ans;

        rep(i,k,0){
            if(!started){
                if(kset[i] == st || kset[i] == end){
                    ans.pb(kset[i]);
                    started = 1;
                }
            }
            else{
                ans.pb(kset[i]);
                if(kset[i] == st || kset[i] == end)break;
            }
        }

        cout<<ans.size()<<endl;
        printarray(ans,ans.size())
    }
}