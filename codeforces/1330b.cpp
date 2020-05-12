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
        int n;
        cin>>n;
        vinput(a,n);
        vector<bool> mf(n,0),mb(n,0);
        
        vector<bool> vis(n+5,false);
        int p1 = 0;

        rep(i,n,0){
            vis[a[i]] = true;
            while(vis[p1+1])p1++;
            if(p1 > i)mf[i] = true;
        }

        vis.clear();
        vis.resize(n+5,false);
        p1=0;

        for(int i=n-1;i>=0;i--){
            vis[a[i]] = true;
            while(vis[p1+1])p1++;
            if(p1 > n-i-1)mb[i] = true;
        }

        vector<ipair> ans;

        // printarray(mf,n)
        // printarray(mb,n)

        for(int i = 0;i < n-1;i++){
            if(mf[i] && mb[i+1])ans.pb(mp(i+1,n-i-1));
        }

        cout<<ans.size()<<endl;
        for(auto x: ans){
            cout<<x.ff<<" "<<x.ss<<endl;
        }
    }
}