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
    int n;
    cin>>n;
    vector<ipair> a(n);
    rep(i,n,0)
    cin>>a[i].ff;
    rep(i,n,0)
    cin>>a[i].ss;
    long double mid,hi=1e9,lo=0,eps=1e-7;

    function<bool(long double)>F=[&](long double t)->bool{
        long double l=-LLONG_MAX,r=LLONG_MAX,l1,r1;
        rep(i,n,0){
            l1=a[i].ff-t*a[i].ss;
            r1=a[i].ff+t*a[i].ss;
            r=min(r,r1);
            l=max(l,l1);
        }
        return l<=r;
    };

    while(hi-lo>eps){
        // cout<<hi<<" "<<lo<<endl;
        mid=(hi+lo)/2;
        if(F(mid))
        hi=mid;
        else
        lo=mid;
    }
    cout<<std::fixed<<std::setprecision(7)<<hi<<endl;
}