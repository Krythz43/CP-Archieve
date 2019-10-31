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
    int a[n][m];
    rep(i,n,0)
    rep(j,m,0)
    cin>>a[i][j];

    if(n>1)
    for(int i=n-2;i>=0;i--)
    {
        if(m==1)
        a[i][0]+=a[i+1][0];
        else
        {
            a[i][0]+=min(a[i+1][0],a[i+1][1]);
            a[i][m-1]+=min(a[i+1][m-1],a[i+1][m-2]);
        }

        rep(j,m-1,1)
        {
            a[i][j]+=min(a[i+1][j-1],min(a[i+1][j],a[i+1][j+1]));
        }
    }

    int ans=inf;
    rep(i,m,0)
    {
        ans=min(ans,a[0][i]);
    }
    cout<<ans<<endl;
}
