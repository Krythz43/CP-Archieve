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
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> a(n);

    rep(i,n,0)cin>>a[i];

    vector<ipair> ans;
    map<ipair,int> M;

    rep(i,n,0){
        rep(j,m,0){
            if(a[i][j]=='.'){
                queue<ipair> q;
                q.push({i,j});

                while(!q.empty()){
                    ipair x=q.front();
                    q.pop();
                    if(M.count(x))continue;
                    M[x]++;
                    
                    if(x.ff>=0 && x.ss>=0 && x.ff<n && x.ss<m){
                        if(a[x.ff][x.ss]=='.')ans.pb(x);
                        else continue;
                    }
                    else continue;

                    if(!M.count({x.ff+1,x.ss}))q.push({x.ff+1,x.ss});
                    if(!M.count({x.ff-1,x.ss}))q.push({x.ff-1,x.ss});
                    if(!M.count({x.ff,x.ss+1}))q.push({x.ff,x.ss+1});
                    if(!M.count({x.ff,x.ss-1}))q.push({x.ff,x.ss-1});
                }

                for(int i=ans.size()-1;i>=0;i--){
                    if(!k)break;
                    a[ans[i].ff][ans[i].ss]='X';
                    k--;
                }

                rep(i,n,0)cout<<a[i]<<endl;

                return 0;
            }
        }
    }
}