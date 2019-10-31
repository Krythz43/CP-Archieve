#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
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
    vector <int> a[1005],b[1005];
    int x;

    rep(i,n,0)
    rep(j,m,0)
    {
        cin>>x;
        a[i+j].pb(x);
    }

    rep(i,n,0)
    rep(j,m,0)
    {
        cin>>x;
        b[i+j].pb(x);
    }

    rep(i,n+m-1,0)
    {
        SO(a[i]);
        SO(b[i]);
    }

    rep(i,n+m-1,0)
    rep(j,a[i].size(),0)
    {
        // cout<<"Equal at "<<a[i][j]<<" "<<b[i][j]<<" at "<<i<<" "<<j<<endl;
        if(a[i][j]!=b[i][j])
        {
            // if(n==3)
            // {
            // }
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}