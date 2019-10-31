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
    lli n,m,k;
    cin>>n>>m>>k;
    lli co=m*k;
    vector<llipair > a,b;
    int x,y;
    rep(i,n,0)
    {
        cin>>x;
        a.pb(mp(x,0));
        b.pb(mp(x,i));
    }

    SO(b);
    lli ans=0;

    for(int i=n-1;i>=0;i--)
    {
        if(co)
        {
            a[b[i].ss].ss=1;
            ans+=b[i].ff;
            co--;
        }
        else
        break;
    }

    int cc=0,oc=0;
    cout<<ans<<endl;

    rep(i,n,0)
    {
        if(oc==k-1)
        break;

        if(cc==m)
        {
            cout<<i<<" ";
            cc=0;
            oc++;
        }
        
        if(a[i].ss)
        cc++;
    }
    nl;
}