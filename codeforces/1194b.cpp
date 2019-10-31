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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        rep(i,n,0)
        cin>>a[i];
        int ansx=0,ansy=0;
        vi px,py;

        rep(i,n,0){
            int tans=0;
            rep(j,m,0)
            if(a[i][j]=='*')tans++;
            ansx=max(tans,ansx);
        }
        rep(i,m,0){
            int tans=0;
            rep(j,n,0)
            if(a[j][i]=='*')tans++;
            ansy=max(tans,ansy);
        }

        rep(i,n,0){
            int tans=0;
            rep(j,m,0)
            if(a[i][j]=='*')tans++;
            if(tans==ansx)px.pb(i);
        }
        rep(i,m,0){
            int tans=0;
            rep(j,n,0)
            if(a[j][i]=='*')tans++;
            if(tans==ansy)py.pb(i);            
        }
        // cout<<ansx<<"x"<<ansy<<endl;

        int fans=n+m-ansx-ansy;
        if(ansx==0 && ansy==0){
            cout<<n+m-1<<endl;
            continue;
        }

        rep(i,px.size(),0){
            int f=0;
        rep(j,py.size(),0)
        if(a[px[i]][py[j]]=='.'){
            f=1;
            fans--;
            break;
        }
        if(f)break;}
        cout<<fans<<endl;
    }
}