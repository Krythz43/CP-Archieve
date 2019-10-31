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
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];

    memset(b,0,sizeof b);

    rep(i,n,0)rep(j,m,0)cin>>a[i][j];

    vector<ipair> ans;
    rep(i,n-1,0)rep(j,m-1,0){
        if(a[i][j]==1){
            if(a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1){
            ans.pb({i+1,j+1});
            b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
            }
        }
    }

    rep(i,n,0)rep(j,m,0)if(a[i][j]!=b[i][j]){
        cout<<-1<<endl;
        return 0;
    }

    cout<<ans.size()<<endl;

    rep(i,ans.size(),0)cout<<ans[i].ff<<' '<<ans[i].ss<<endl;
}