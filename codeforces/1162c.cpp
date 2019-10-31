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
    int n,k;
    cin>>n>>k;
    vi a(n+1,0);
    int x,ff,ss;

    rep(i,k,0)
    {
        cin>>x;
        a[x]++;
        if(i==0)
        ff=x;
        if(i==k-1)
        ss=x;
    }

    lli ans=0;
    int zc=0,oc=0;
    rep(i,n+1,1)
    {
        if(a[i]==0)
        {
            ans++;
            // cout<<i<<endl;
        }
    }

    rep(i,n,1)
    {
        if((a[i]==1||a[i]==0) && (a[i+1]==1 || a[i+1]==0))
        {
            ans+=2;
            // cout<<i<<" "<<i+1<<endl;

            if(i==ss || i==ff)
            ans--;
        }
    }

    // if(ff==ss)
    // ans++;

    cout<<ans<<endl;


}
